#include "authentication.hpp"
#include "prompt.hpp"
#include <iostream>
#include <cstring>
#include <cstdio>

void login() {

    std::string username;
    std::string password;
    
    bool bUserFound = false;
    while (true) {
        std::cout << "Enter username: "; std::cin >> username;
        if (!(bUserFound = verify_username(username))) {
            std::cout << "User not found.\n\n";
        } else {
            std::cout << "User found.\n\n" << std::flush;
            break;
        }
    }

    bool bPasswordVerified = false;
    for (int i = 1; i <= 3; i++) {
        std::cout << "Enter password: "; std::cin >> password;
        if (!(bPasswordVerified = verify_password(password))) { 
            std::cout << "Incorrect password. Attempt " << i << " of 3.\n";
        } else {
            std::cout << "Access granted.\n\n" << std::flush;
            return;
        }
    }
    std::cout << "Access denied.\n\n" << std::flush;

    exit(1);
}

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
        if (buffer[i] >= 'A' && buffer[i] <= 'z') {
            break;
        }

        if (buffer[i] == '\t' || buffer[i] == '\n' || buffer[i] == ' ') {
            buffer[i] = '\0';
        }
    }

    return buffer;
}

void prompt() {

    std::string query;

    std::cout << "Welcome to VPR's bank-cli application.\n";
    displayHelp();

    char buffer[256]{0};
    while (true) {
        std::cout << ":> " << std::flush;
        fgets(buffer, sizeof(buffer), stdin);
        query = rstrip(buffer, sizeof(buffer));

        if (!query.compare("show accounts")) {
            std::cout << query << std::endl; 
        } else if (!query.compare("display account")) {
            std::cout << query << std::endl; 
        } else if (!query.compare("search name")) {
            std::cout << query << std::endl; 
        } else if (!query.compare("new account")) {
            std::cout << query << std::endl; 
        } else if (!query.compare("close account")) {
            std::cout << query << std::endl; 
        } else if (!query.compare("quit")) {
            std::cout << "Exiting...\n";
            break;
        } else if (!query.compare("help")) {
            displayHelp();
        } else if (query.length() > 0) {
            std::cout << "Unknown query: " << "'" << query << "'" << std::endl; 
        }

        memset(buffer, 0, sizeof(buffer));
    }

}
