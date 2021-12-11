#include "authentication.hpp"
#include "encryption.hpp"

// TODO: Save username somewhere
bool verify_username(std::string username) {

    if (!username.compare("admin")) {
        return true;
    }

    return false;
}

// TODO: Save password somewhere
bool verify_password(std::string password) {

    if (!password.compare("password")) {
        return true;
    }

    return false;
}
