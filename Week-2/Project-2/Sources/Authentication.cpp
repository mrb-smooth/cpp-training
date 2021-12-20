#include "authentication.hpp"

#include <iostream>

void auth::login() {

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

// TODO: Save username somewhere
bool auth::verify_username(std::string username) {

    if (!username.compare("demo")) {
        return true;
    }

    return false;
}

// TODO: Save password somewhere
bool auth::verify_password(std::string password) {

    if (!password.compare("demo")) {
        return true;
    }

    return false;
}
