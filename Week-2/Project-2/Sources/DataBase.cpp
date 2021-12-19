#include "DataBase.hpp"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <ctime>

#define CUSTOMER_NAME     0
#define DATE_OPENED       1
#define SOCIAL_SECURITY   2

//////////////////////////////
// Helper functions - start //
//////////////////////////////
unsigned levenshtein_distance(const std::string_view& s1, const std::string_view& s2) {

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
////////////////////////////
// Helper functions - end //
////////////////////////////

bool db::DataBase::find_account(unsigned int account_id) const {

    log_info("Searching for account ID: '" + std::to_string(account_id) + "'...");
    if (data.find(account_id) == data.end()) {
        std::cerr << "Error: invalid account.\n"
                  << "\n" << std::flush;

        log_warning("Invalid account ID: '" + std::to_string(account_id) + "'.");
        return false;
    }

    log_info("Account ID: '" + std::to_string(account_id) + "' found.");
    return true;
}

bool db::DataBase::add_account(std::string full_name, std::string social_security) {

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
    log_info("Verifying that data is unique...");
    bool bDuplicate = false;
    for (const auto& [account_id, account_values] : data) {
        if (account_values.full_name == full_name) {
            log_warning("Existing Account with name '" + full_name + "' found.");
            bDuplicate = true;
        }

        if (account_values.social_security == social_security) {
            log_warning("Existing Account with Social Security Number '" + social_security + "' found.");
            bDuplicate = true;
        }

        if (bDuplicate) {
        log_warning("Failed to create new account - Account: " + full_name +
                 " Social Security Number: " + social_security.substr(7, 10) +
                 " Date Created: " + datetime + ".");
            return false;
        }
    }
    
    // Pouplate values
    log_info("Attempting to populate database with new account...");
    data[account_id].full_name = full_name;
    data[account_id].date_created_dt = get_current_time();
    data[account_id].social_security = social_security;
    data[account_id].transactions.clear(); 

    log_info("Populated Database with new account - Account: " + full_name +
             " Social Security Number: " + social_security.substr(7, 10) +
             " Date Created: " + datetime + ".");
    return true;
}

std::string db::DataBase::get_name_by_account_id(unsigned account_id) const {

    log_info("Getting name of account: '" + std::to_string(account_id) + "'...");
    return data.at(account_id).full_name;

}

std::vector<unsigned> db::DataBase::search_name(const std::string& name) const {

    std::vector<unsigned> search_results;

    // Find exact
    log_info("Searching for account with exact name: '" + name + "'...");
    for (const auto& [account_id, account_values] : data) {
        if (account_values.full_name == name) {
            search_results.push_back(account_id);
            log_info("Account with exact name found.");
            break;
        }
    }

    // Find Similar
    log_info("Searching for account with similar name: '" + name + "'...");
    for (const auto& [account_id, account_values] : data) {
        if (levenshtein_distance(account_values.full_name, name) < 4) {
            log_info("Account with similar name found.");
            search_results.push_back(account_id);
        }
    }
    
    log_info("Returning results...");
    return search_results;
}

void db::DataBase::display_account(unsigned int account_id) const {

    log_info("Attempting to display account: '" + std::to_string(account_id) + "'.");
    if (data.find(account_id) == data.end()) {
        std::cerr << "Error: invalid account.\n"
                  << "\n" << std::flush;
        log_warning("Unable find account: '" + std::to_string(account_id) + "'.");
        return;
    }

    log_info("Displaying account: '" + std::to_string(account_id) + "' details.");
    const auto& account_values = data.at(account_id);
    std::cout << "Customer Name:\t" << account_values.full_name << "\n"
              << "SSN:\t\t"         << "***-**-"
              << account_values.social_security.substr(account_values.social_security.length() - 4) << "\n"
              << "Date Opened:\t"   << account_values.date_created_dt << "\n"
              << "Account:\t"       << account_id << "\n"
              << "\n" << std::flush;

}

void db::DataBase::close_account(unsigned int account_id) {

    auto original_size = data.size();

    log_info("Attempting to display account: '" + std::to_string(account_id) + "'.");
    data.erase(data.find(account_id));
    if (original_size == data.size()) {
        log_error("Failed to remove account: '" + std::to_string(account_id) + "'.");
    } else {
        log_info("Successfully removed account: '" + std::to_string(account_id) + "'.");
    }

}

void db::DataBase::show_accounts() const {

    log_info("Attempting to show all accounts.");

    // Header
    std::cout << "Customer Name\t\tAccount\t\tDate Opened\n";

    // Data
    for (const auto& [account_id, account_values] : data) {
        std::cout << account_values.full_name << "\t\t"
                  << account_id << "\t"
                  << account_values.date_created_dt
                  << "\n";
    }
    std::cout << "\n" << std::flush;

    log_info("Successfully shown all accounts.");
}

bool db::DataBase::populate_database(std::string _file_name) {

    std::ifstream fs(_file_name);
    if (!fs) {
        std::cerr << "Could not open '" << _file_name << "'.\n";
        return false;
    } else {
        std::cout << "Extracting data from '" << _file_name << "'.\n";
    }

    log_info("Attempting to populate database using '" + _file_name + "'.");
    // TODO
    // Take in data
    
    std::cout << "Data extracted from '" << _file_name << "'.\n"
              << "\n" << std::flush;

    log_info("Successfully populatep database using '" + _file_name + "'.");

    return true;
}

///////////////////////////////
// Virtual functions - start //
///////////////////////////////
void db::DataBase::log_info(const std::string_view& info) const {

    std::string prefix = "[" + get_current_time() + "]: ";
    std::ofstream ofs(log_file, std::ios_base::app);

    ofs << prefix << info << std::endl;

}

void _Noreturn db::DataBase::log_error(const std::string_view& error) const {

    std::cerr << error << std::endl;

    std::string prefix = "[" + get_current_time() + "]: FATAL - ";
    std::ofstream ofs(log_file, std::ios_base::app);

    ofs << prefix << error << std::endl;

    std::cerr << "\nCheck error log: '" << log_file << "' for more details.\n"
              << "\nExiting...\n";
    exit(1);
}

void db::DataBase::log_warning(const std::string_view& warning) const {

    std::cerr << warning << std::endl;

    std::string prefix = "[" + get_current_time() + "]: WARNING - ";
    std::ofstream ofs(log_file, std::ios_base::app);

    ofs << prefix << warning << std::endl;

}
/////////////////////////////
// Virtual functions - end //
/////////////////////////////
