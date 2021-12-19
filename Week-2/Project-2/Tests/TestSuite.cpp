#include "AuthenticationTest.hpp"
#include "DataBaseTest.hpp"
#include <iostream>

#define TEST(X) std::cout << "Testing: " << #X << std::endl;\
                X();\
                std::cout << "Test passed.\n\n"

int main() {

    // Auth
    std::cout << "Performing Authentication Tests...\n";
    TEST(test_verify_username_correct);
    TEST(test_verify_username_incorrect);
    TEST(test_verify_password_correct);
    TEST(test_verify_password_incorrect);

    // DataBaseTest
    std::cout << "Performing Database Tests...\n";
    TEST(test_db_find_account);
    TEST(test_db_add_account);
    TEST(test_db_search_name);
    TEST(test_get_name_by_account_id);
    TEST(test_db_display_account);
    TEST(test_db_close_account);

}
