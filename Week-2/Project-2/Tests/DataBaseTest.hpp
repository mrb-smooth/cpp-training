#ifndef DATABASE_TEST_HPP
#define DATABASE_TEST_HPP

#include "DataBase.hpp"

bool test_db_find_account_exists();
bool test_db_find_account_not_exists();
bool test_db_add_account_exists();
bool test_db_add_account_not_exists();

bool test_db_search_name_exists();
bool test_db_search_name_not_exists();
bool test_get_name_by_account_id_exists();
bool test_get_name_by_account_id_not_exists();

bool test_db_display_account_exists();
bool test_db_display_account_not_exists();
bool test_db_close_account_exists();
bool test_db_close_account_not_exists();

#endif // DATABASE_TEST_HPP
