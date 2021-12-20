#include "Authentication.hpp"
#include "Client.hpp"
#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>

static void displayHelp() {

    std::cout << "You can enter the following commands:\n"
                 "  show accounts:\tshows all accounts in database.\n"
                 "  display account:\tdisplays accounts details.\n"
                 "  search name:\t\tparses database for users with specified name.\n"
                 "  new account:\t\tcreates a new account.\n"
                 "  close account:\tremoves an account if it exists.\n"
                 "  quit:\t\t\texits the application without saving.\n"
                 "  help:\t\t\tdisplay this menu again.\n"
                 "\n" << std::flush;

}

static inline char* rstrip(char* buffer, size_t size) {

    size_t i = size;
    while (i--) {
        if ((buffer[i] >= 'A' && buffer[i] <= 'Z') ||
            (buffer[i] >= 'a' && buffer[i] <= 'z') ||
            (buffer[i] >= '1' && buffer[i] <= '9')) {
            break;
        }

        if (buffer[i] == '\t' || buffer[i] == '\n' || buffer[i] == ' ') {
            buffer[i] = '\0';
        }
    }

    return buffer;
}

static inline bool valid_name(std::string name) {

    // If non-alphanumeric
    int spaces = 0;
    for (const auto& c : name) {
        if ((c >= '1' && c <= '9')) {
            return false;
        }

        if ((spaces += (c == '-')) > 1) {
            return false;
        }
    }

    return true;
}

static inline bool valid_ssn(const std::string ssn) {

    // Temp
    std::string tmp = ssn;

    // Strip hyphen if any
    tmp.erase(std::remove(tmp.begin(), tmp.end(), '-'), tmp.end());

    // Make sure it is exactly 9 digits
    if (tmp.size() != 9) {
        return false;
    }

    // If non-numeric
    for (const auto& c : tmp) {
        if (!(c >= '1' && c <= '9')) {
            return false;
        }
    }

    return true;
}

void client::app(db::DataBase& db) {

    std::string query;

    std::cout << "Welcome to VPR's bank-cli application.\n";
    displayHelp();

    char buffer[256]{0};
    while (true) {
        std::cout << "command > " << std::flush;
        fgets(buffer, sizeof(buffer), stdin);
        query = rstrip(buffer, sizeof(buffer));

        if (!query.compare("show accounts") && query.length() == 13) {
            db.show_accounts();
        } else if (!query.compare("display account") && query.length() == 15) {
            std::cout << "command > account > " << std::flush; 

            unsigned int account_id;

            memset(buffer, 0, sizeof(buffer));
            fgets(buffer, sizeof(buffer), stdin);
            query = rstrip(buffer, sizeof(buffer));

            try {
                account_id = std::stoul(query);
            } catch (...) {
                std::cerr << "Error: input error.\n";
                continue;
            }

            db.display_account(account_id);
            
            // Transaction prompt
            std::cout << "Add a transaction? (yes/no) > ";

            memset(buffer, 0, sizeof(buffer));
            fgets(buffer, sizeof(buffer), stdin);
            query = rstrip(buffer, sizeof(buffer));

            if (!query.compare("yes")) {
                // Get transaction
                std::cout << "command > account > " << account_id << " > amount " << std::flush; 
                memset(buffer, 0, sizeof(buffer));
                fgets(buffer, sizeof(buffer), stdin);
                double transaction = std::atof(rstrip(buffer, sizeof(buffer)));

                db.add_transaction(account_id, transaction);
            } else if (!query.compare("no")) {
                std::cerr << "Aborting.\n" << std::flush;
            } else {
                std::cerr << "Error: unknown option. Aborting.\n" << std::flush;
            }
        } else if (!query.compare("search name") && query.length() == 11) {
            std::cout << "command > search name > " << std::flush; 

            memset(buffer, 0, sizeof(buffer));
            fgets(buffer, sizeof(buffer), stdin);
            std::string name = rstrip(buffer, sizeof(buffer));
            if (!valid_name(name)) {
                std::cerr << "Error: invalid name.\nAborting.\n\n" << std::flush;
                continue;
            }
            std::vector<unsigned> results = db.search_name(name);
            size_t size = results.size();

            // Display results
            unsigned i;
            for (i = 0; i < size; i++) {
                std::cout << i << ") " << db.get_name_by_account_id(results[i]) << "\n";
            } 
            std::cout << size << ") " << "Home" << "\n";

            // Get input
            std::cout << "command > search name > selection > " << std::flush; 
            memset(buffer, 0, sizeof(buffer));
            fgets(buffer, sizeof(buffer), stdin);
            query = rstrip(buffer, sizeof(buffer));

            // Convert to int
            try {
                unsigned selection = std::stoul(query = rstrip(buffer, sizeof(buffer)));

                if (selection == size) {
                    std::cout << "returning to main menu...\n" << std::flush;
                    continue;
                } else if (selection < size && selection >= 0) {
                    db.display_account(results[selection]);
                }
            } catch (...) {
                std::cerr << "Error: invalid number.\n";
                continue;
            }
        } else if (!query.compare("new account") && query.length() == 11) {
            std::cout << "command > new account > name > " << std::flush; 

            memset(buffer, 0, sizeof(buffer));
            fgets(buffer, sizeof(buffer), stdin);
            std::string name = rstrip(buffer, sizeof(buffer));
            if (!valid_name(name)) {
                std::cerr << "Error: invalid name.\nAborting.\n\n" << std::flush;
                continue;
            }

            std::cout << "command > new account > ssn > " << std::flush; 

            memset(buffer, 0, sizeof(buffer));
            fgets(buffer, sizeof(buffer), stdin);
            std::string ssn = rstrip(buffer, sizeof(buffer));
            if (!valid_ssn(ssn)) {
                std::cerr << "Error: invalid ssn.\nAborting.\n\n" << std::flush;
                continue;
            }

            if (!db.add_account(name, ssn)) {
                std::cerr << "Error: account with credentials already exists.\nAborting.\n\n" << std::flush;
                continue;
            }

            std::cout << "Account for '" << name << "' created.\n" << std::flush;

        } else if (!query.compare("close account") && query.length() == 13) {
            std::cout << "command > close account > " << std::flush; 
            unsigned int account_id;
            
            memset(buffer, 0, sizeof(buffer));
            fgets(buffer, sizeof(buffer), stdin);
            query = rstrip(buffer, sizeof(buffer));

            try {
                account_id = std::stoul(query);
            } catch (...) {
                std::cerr << "Error: input error.\n";
                continue;
            }

            if (db.find_account(account_id)) {
                std::cout << "You sure bro? (yes/no) > ";

                memset(buffer, 0, sizeof(buffer));
                fgets(buffer, sizeof(buffer), stdin);
                query = rstrip(buffer, sizeof(buffer));

                if (!query.compare("yes")) {
                    std::cout << "Closing account '" << account_id << "'...\n" << std::flush;
                    db.close_account(account_id);
                } else if (!query.compare("no")) {
                    std::cerr << "Aborting.\n" << std::flush;
                } else {
                    std::cerr << "Error: unknown option. Aborting.\n" << std::flush;
                }
            }
        } else if (!query.compare("quit") && query.length() == 4) {
            std::cout << "Exiting...\n";
            break;
        } else if (!query.compare("help") && query.length() == 4) {
            displayHelp();
        } else if (query.length() > 0) {
            std::cout << "Unknown query: " << "'" << query << "'" << std::endl; 
        }

        memset(buffer, 0, sizeof(buffer));
    }

}
