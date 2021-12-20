#include "DataBase.hpp"

#include <algorithm>
#include <fstream>
#include <sstream>
#include <ctime>

#define BASE_ACCOUNT_SIZE 1'000'000'000

//////////////////////////////
// Helper functions - start //
//////////////////////////////
static inline unsigned levenshtein_distance(const std::string_view& s1, const std::string_view& s2) {

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

static inline uint64_t generate_next_account_id(const db::DataBase& db) {

    uint64_t generated_id = BASE_ACCOUNT_SIZE + 1;
    for (uint64_t i = 0; i < db.data.size(); i++) {
        if (!db.data.contains(generated_id + i)) {
            return generated_id + i;
        }
    }

    return generated_id;
}
////////////////////////////
// Helper functions - end //
////////////////////////////


bool db::DataBase::find_account(uint64_t account_id) const {

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

    // Generate next account number
    int account_id = generate_next_account_id(*this);

    // Verify that data is unique
    log_info("Verifying that data is unique...");
    bool bDuplicate = false;
    for (auto [account_id, account_values] : data) {
        if (account_values.full_name() == full_name) {
            log_warning("Existing Account with name '" + full_name + "' found.");
            bDuplicate = true;
        }

        if (account_values.social_security() == social_security) {
            log_warning("Existing Account with Social Security Number '" + social_security + "' found.");
            bDuplicate = true;
        }

        if (bDuplicate) {
        log_warning("Failed to create new account - Account: " + full_name +
                 " Social Security Number: " + social_security.substr(7, 10) +
                 " at: " + get_current_time() + ".");
            return false;
        }
    }
    
    // Populate values
    log_info("Attempting to populate database with new account...");
    data[account_id].set_full_name(full_name);
    data[account_id].set_date_created_dt(get_current_time());
    data[account_id].set_social_security(social_security);

    log_info("Populated Database with new account - Account: " + full_name +
             " Social Security Number: " + social_security.substr(7, 10) +
             " Date Created: " + get_current_time() + ".");

    (void)update_database();
    
    return true;
}

bool db::DataBase::add_transaction(uint64_t account_id, double transaction) {

    log_info("Attempting to execute transaction: "
             "Account ID: " + std::to_string(account_id) +
             "; Amount: " + std::to_string(transaction) + ".");

    // Assert account exists
    if (!data.contains(account_id)) {
        log_error("Account '" + std::to_string(account_id) + "' not found.");
        return false;
    }

    // Actually add transaction
    if (data.at(account_id).balance() + transaction < 0) {
        // Record ledger 
        data.at(account_id).mutable_ledger()->set_amount(transaction);
        data.at(account_id).mutable_ledger()->set_successful(false);
        data.at(account_id).mutable_ledger()->set_transaction_dt(get_current_time());

        log_warning("Insufficient funds: Account '" + std::to_string(account_id) +
                "' balance = " + std::to_string(data.at(account_id).balance()) + ".");

        return false;
    } else {
        // Adjust balance
        double previous_balance = data.at(account_id).balance();
        data.at(account_id).set_balance(previous_balance + transaction);

        // Record ledger 
        data.at(account_id).mutable_ledger()->set_amount(transaction);
        data.at(account_id).mutable_ledger()->set_successful(true);
        data.at(account_id).mutable_ledger()->set_transaction_dt(get_current_time());

        log_info("Transaction successful: Account '" + std::to_string(account_id) +
                "' balance = " + std::to_string(data.at(account_id).balance()) + ".");
    }

    return true;
}

std::string db::DataBase::get_name_by_account_id(unsigned account_id) const {

    log_info("Getting name of account: '" + std::to_string(account_id) + "'...");
    if (!data.contains(account_id)) {
        log_warning("Account ID: '" + std::to_string(account_id) + "' not found.");
        return "";
    }

    return data.at(account_id).full_name();

}

std::vector<unsigned> db::DataBase::search_name(const std::string& name) const {

    std::vector<unsigned> search_results = { };

    // Find exact
    log_info("Searching for account with exact name: '" + name + "'...");
    for (const auto& [account_id, account_values] : data) {
        if (account_values.full_name() == name) {
            search_results.push_back(account_id);
            log_info("Account with exact name found.");
            break;
        }
    }

    // Find Similar
    log_info("Searching for account with similar name: '" + name + "'...");
    for (const auto& [account_id, account_values] : data) {
        if ((levenshtein_distance(account_values.full_name(), name) < 4) &&
            (std::find(search_results.begin(), search_results.end(), account_id) == search_results.end()))
        {
            log_info("Account with similar name found.");
            search_results.push_back(account_id);
        }
    }
    
    log_info("Returning results...");
    return search_results;
}

void db::DataBase::display_account(unsigned int account_id) const {

    log_info("Attempting to display account: '" + std::to_string(account_id) + "'...");
    if (data.find(account_id) == data.end()) {
        std::cerr << "Error: invalid account.\n"
                  << "\n" << std::flush;
        log_warning("Unable find account: '" + std::to_string(account_id) + "'.");
        return;
    }

    log_info("Displaying account: '" + std::to_string(account_id) + "' details.");
    const auto& account_values = data.at(account_id);
    std::cout << "Customer Name:\t" << account_values.full_name() << "\n"
              << "SSN:\t\t"         << "***-**-"
              << account_values.social_security().substr(account_values.social_security().length() - 4) << "\n"
              << "Date Opened:\t"   << account_values.date_created_dt() << "\n"
              << "Account:\t"       << account_id << "\n"
              << "Balance:\t"       << account_values.balance() << "\n"
              << "\n" << std::flush;

}

void db::DataBase::close_account(unsigned int account_id) {

    auto original_size = data.size();

    log_info("Attempting to display account: '" + std::to_string(account_id) + "'...");
    if (!data.contains(account_id)) {
        log_warning("Account ID: '" + std::to_string(account_id) + "' not found.");
        return;
    }

    data.erase(data.find(account_id));
    if (original_size == data.size()) {
        log_error("Failed to remove account: '" + std::to_string(account_id) + "'.");
    } else {
        log_info("Successfully removed account: '" + std::to_string(account_id) + "'.");
    }

    (void)update_database();

}

void db::DataBase::show_accounts() const {

    log_info("Attempting to show all accounts...");

    // Header
    std::cout << "Customer Name\t\tAccount\t\tDate Opened\n";

    // Data
    for (const auto& [account_id, account_values] : data) {
        std::cout << account_values.full_name() << "\t\t"
                  << account_id << "\t"
                  << account_values.date_created_dt()
                  << "\n";
    }
    std::cout << "\n" << std::flush;

    log_info("Successfully shown all accounts.");
}

[[nodiscard]] auto
db::DataBase::generate_database() -> bool {

    log_info("Attempting to generate data for '" + data_source + "'...");

    // Hardcoded data
    data[BASE_ACCOUNT_SIZE + 1].set_full_name("John Doe");
    data[BASE_ACCOUNT_SIZE + 1].set_social_security("155555555");
    data[BASE_ACCOUNT_SIZE + 1].set_date_created_dt("2021-12-19 00:00:00");
    data[BASE_ACCOUNT_SIZE + 1].set_balance(25.0l);

    data[BASE_ACCOUNT_SIZE + 2].set_full_name("Jane Doe");
    data[BASE_ACCOUNT_SIZE + 2].set_social_security("255555555");
    data[BASE_ACCOUNT_SIZE + 2].set_date_created_dt("2021-12-19 00:00:00");
    data[BASE_ACCOUNT_SIZE + 2].set_balance(25.0l);

    data[BASE_ACCOUNT_SIZE + 3].set_full_name("George Doe");
    data[BASE_ACCOUNT_SIZE + 3].set_social_security("355555555");
    data[BASE_ACCOUNT_SIZE + 3].set_date_created_dt("2021-12-19 00:00:00");
    data[BASE_ACCOUNT_SIZE + 3].set_balance(25.0l);

    if (update_database(); !data.size()) {
        log_warning("Failed to generate data for '" + data_source + "'.");
        return false;
    } 

    log_info("Successfully generated data for '" + data_source + "'.");
    return true;
}

[[nodiscard]] auto
db::DataBase::update_database() -> bool {

    log_info("Attempting to update data for '" + data_source + "'...");
    std::ofstream ofs(data_source, std::ios::out | std::ios::trunc | std::ios::binary);

    if (!db.SerializeToOstream(&ofs)) {
        log_warning("Failed to update data for '" + data_source + "'.");
        return false;
    } 

    log_info("Successfully updated data for '" + data_source + "'.");
    return true;
}

[[nodiscard]] auto
db::DataBase::populate_database() -> bool {

    std::ifstream ifs(data_source);
    if (!ifs) {
        std::cerr << "Could not open '" << data_source << "'.\n";
        return false;
    }

    log_info("Attempting to parse data from '" + data_source + "'...");
    if (!db.ParseFromIstream(&ifs)) {
        log_warning("Failed to read data from '" + data_source + "'.");
        return false;
    }

    if (!data.size()) {
        log_warning("Failed to parse data from '" + data_source + "'.");
        return false;
    }

    log_info("Successfully parsed data from '" + data_source + "'.");

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
