#include "TestSuite.hpp"
#include "AuthenticationTest.hpp"
#include "DataBaseTest.hpp"
#include <iostream>

unsigned g_tests_failed = 0;
unsigned g_tests_passed = 0;

int main() {

    // Authentication
    std::cout << "Performing Authentication Tests...\n";
    TEST(test_verify_username_correct);
    TEST(test_verify_username_incorrect);
    TEST(test_verify_password_correct);
    TEST(test_verify_password_incorrect);

    // DataBase
    std::cout << "Performing Database Tests...\n";
    TEST(test_db_find_account_exists);
    TEST(test_db_find_account_not_exists);
    TEST(test_db_add_account_exists);
    TEST(test_db_add_account_not_exists);

    TEST(test_db_search_name_exists);
    TEST(test_db_search_name_not_exists);
    TEST(test_get_name_by_account_id_exists);
    TEST(test_get_name_by_account_id_not_exists);

    TEST(test_db_display_account_exists);
    TEST(test_db_display_account_not_exists);
    TEST(test_db_close_account_exists);
    TEST(test_db_close_account_not_exists);
    // Transactions

    std::cout << std::endl;
    std::cout << "Tests failed: " << g_tests_failed << "\n";
    std::cout << "Tests passed: " << g_tests_passed << "\n" << std::flush;

}
