#include "DataBase.hpp"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <ctime>

#define CUSTOMER_NAME     0
#define DATE_OPENED       1
#define SOCIAL_SECURITY   2

//////////////////////
// Helper functions //
//////////////////////
unsigned levenshtein_distance(const std::string s1, std::string s2) {

	const std::size_t len1 = s1.size(), len2 = s2.size();
	std::vector<std::vector<unsigned int>> d(len1 + 1, std::vector<unsigned int>(len2 + 1));

	d[0][0] = 0;
	for(unsigned int i = 1; i <= len1; ++i) d[i][0] = i;
	for(unsigned int i = 1; i <= len2; ++i) d[0][i] = i;

	for(unsigned int i = 1; i <= len1; ++i)
		for(unsigned int j = 1; j <= len2; ++j) {
            d[i][j] = std::min({ d[i - 1][j] + 1, d[i][j - 1] + 1, d[i - 1][j - 1] + (s1[i - 1] == s2[j - 1] ? 0 : 1) });
        }

	return d[len1][len2];
}

bool db::DataBase::find_account(unsigned int account_id) const {

    if (data.find(account_id) == data.end()) {
        std::cerr << "Error: invalid account.\n"
                  << "\n" << std::flush;
        return false;
    }

    return true;
}

bool db::DataBase::add_account(std::string name, std::string ssn) {

    // Generate random number
    int account_id = rand() % INT32_MAX;

    // Get datetime
    time_t rawtime;
    time(&rawtime);

    tm* timeinfo;
    char datetime[80];

    timeinfo = localtime(&rawtime);
    strftime(datetime, sizeof(datetime), "%Y-%m-%d", timeinfo);

    // Verify that data is unique
    for (const auto& it : data) {
        for (const auto& value : it.second) {
            if (value == name || value == ssn) {
                return false;
            }
        }
    }
    
    // Pouplate values
    std::vector<std::string> values = { name, datetime, ssn };
    data[account_id] = values;

    return true;
}

std::string db::DataBase::get_name_by_account_id(unsigned account_id) const {

    return data.at(account_id)[CUSTOMER_NAME];

}

std::vector<unsigned> db::DataBase::search_name(const std::string& name) const {

    std::vector<unsigned> search_results;

    // Find exact
    for (const auto& it : data) {
        if (std::find(it.second.begin(), it.second.end(), name) != it.second.end()) {
            search_results.push_back(it.first);
        }
    }

    // Find Similar
    std::stringstream ss;
    for (const auto& it : data) {
        std::vector<std::string> tmp = it.second;

        if (levenshtein_distance(tmp[CUSTOMER_NAME], name) < 4 &&
            (std::find(search_results.begin(), search_results.end(), it.first) == search_results.end())) {

            search_results.push_back(it.first);
        }
    }
    
    return search_results;
}

void db::DataBase::display_account(unsigned int account_id) const {

    if (data.find(account_id) == data.end()) {
        std::cerr << "Error: invalid account.\n"
                  << "\n" << std::flush;
        return;
    }

    const auto& values = data.at(account_id);
    std::cout << "Customer Name:\t" << values[CUSTOMER_NAME]   << "\n"
              << "SSN:\t\t"         << "***-**-"
              << values[SOCIAL_SECURITY].substr(values[SOCIAL_SECURITY].length() - 4) << "\n"
              << "Date Opened:\t"   << values[DATE_OPENED]     << "\n"
              << "Account:\t"       << account_id              << "\n"
              << "\n" << std::flush;

}

void db::DataBase::close_account(unsigned int account_id) {

    data.erase(data.find(account_id));

}

void db::DataBase::show_accounts() const {

    // Header
    std::cout << "Customer Name\t\tAccount\t\tDate Opened\n";

    // Data
    for (const auto& it : data) {
        std::cout << it.second[CUSTOMER_NAME] << "\t\t"
                  << it.first << "\t"
                  << it.second[DATE_OPENED]
                  << "\n";
    }
    std::cout << "\n" << std::flush;

}

bool db::DataBase::populate_database(std::string _file_name) {

    std::ifstream fs(_file_name);
    if (!fs) {
        std::cerr << "Could not open '" << _file_name << "'.\n";
        return false;
    } else {
        std::cout << "Extracting data from '" << _file_name << "'.\n";
    }

    // Iterate through file
    std::string buffer = "";
    std::getline(fs, buffer); // discard first line
    while (std::getline(fs, buffer)) {
        // TOKENIZE
        std::string account_id_buffer;
        unsigned int account_id = 0;
        std::vector<std::string> result;

        std::stringstream ss(buffer);
        // Extract account id
        getline(ss, account_id_buffer, ',');
        account_id = std::stoul(account_id_buffer);

        // Extract remaining elements
        while (ss.good()) {
            std::string token;
            getline(ss, token, ',');
            result.push_back(token);
        }

        data[account_id] = result;
    }

    std::cout << "Data extracted from '" << _file_name << "'.\n"
              << "\n" << std::flush;

    return true;
}

void db::DataBase::log_info(std::string info) {
    std::cerr << info << std::endl;
}
void db::DataBase::log_error(std::string error) {
    std::cerr << error << std::endl;
}
void db::DataBase::log_warning(std::string warning) {
    std::cerr << warning << std::endl;
}
