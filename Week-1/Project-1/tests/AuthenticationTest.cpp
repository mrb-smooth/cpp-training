#include "Authentication.hpp"
#include <cassert>

using auth::verify_username;
using auth::verify_password;

void test_verify_username_correct() {

    std::string username("admin");
    assert(verify_username(username) == true);

}
void test_verify_username_incorrect() {

    std::string username("badmin");
    assert(verify_username(username) == false);

}
void test_verify_password_correct() {

    std::string password("password");
    assert(verify_password(password) == true);

}
void test_verify_password_incorrect() {

    std::string password("incorrect");
    assert(verify_password(password) == false);

}
