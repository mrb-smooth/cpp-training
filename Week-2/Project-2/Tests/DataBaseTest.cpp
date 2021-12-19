#include "DataBaseTest.hpp"
#include <cassert>

void test_db_find_account() {

    std::string file_name("data.csv");
    db::DataBase database(file_name);

    assert(database.find_account(1123456789) == true);

}
void test_db_add_account() {

    std::string file_name("data.csv");
    db::DataBase database(file_name);

    std::string name("Jack Harlow"), ssn("555-55-5551");
    assert(database.add_account(name, ssn) == true);

}

void test_db_search_name() {

    std::string file_name("data.csv");
    db::DataBase database(file_name);

    std::vector<unsigned> valid_results = { 1123456789, 2123456789 } ;

    std::string name("John Doe");
    assert(database.search_name(name) == valid_results);

}
void test_get_name_by_account_id() {

    std::string file_name("data.csv");
    db::DataBase database(file_name);

    std::string expected_name = "John Doe";

    unsigned account_id = 1123456789;
    assert(database.get_name_by_account_id(account_id) == expected_name);

}

void test_db_display_account() {

    std::string file_name("data.csv");
    db::DataBase database(file_name);

    // The actual test
}
void test_db_close_account() {

    std::string file_name("data.csv");
    db::DataBase database(file_name);

    size_t size_before = database.data.size();
    size_t size_after;

    unsigned account_id = 1123456789;
    database.close_account(account_id);
    size_after = database.data.size();

    assert(size_before > size_after);
    
}
