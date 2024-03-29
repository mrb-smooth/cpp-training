#ifndef AUTHENTICATION_HPP
#define AUTHENTICATION_HPP

#include <string>

namespace auth {
    void login();
    bool verify_username(std::string);
    bool verify_password(std::string);
}


#endif // AUTHENTICATION_HPP
