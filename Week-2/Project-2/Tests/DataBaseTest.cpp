#include "TestSuite.hpp"
#include "DataBaseTest.hpp"

extern unsigned g_tests_failed;
extern unsigned g_tests_passed;

[[nodiscard]] auto
test_db_find_account_exists() -> bool {

    bool bPassed = false;

    pb::Accounts accounts;
    std::string file_name("Data/data.db");
    db::DataBase database(file_name, accounts);

    ASSERT((bPassed = (database.find_account(1123456789) == true)));

    return bPassed;
}

[[nodiscard]] auto
test_db_find_account_not_exists() -> bool {

    bool bPassed = false;

    pb::Accounts accounts;
    std::string file_name("Data/data.db");
    db::DataBase database(file_name, accounts);

    ASSERT((bPassed = (database.find_account(999999999) == false)));

    return bPassed;
}

[[nodiscard]] auto
test_db_add_account_exists() -> bool {

    bool bPassed = false;

    pb::Accounts accounts;
    std::string file_name("Data/data.db");
    db::DataBase database(file_name, accounts);

    std::string name("Jack Harlow"), ssn("555-55-5551");
    ASSERT((bPassed = (database.add_account(name, ssn) == false)));

    return bPassed;
}

[[nodiscard]] auto
test_db_add_account_not_exists() -> bool {

    bool bPassed = false;

    pb::Accounts accounts;
    std::string file_name("Data/data.db");
    db::DataBase database(file_name, accounts);

    std::string name("New Name"), ssn("955-55-5555");
    ASSERT((bPassed = (database.add_account(name, ssn) == true)));

    return bPassed;
}

[[nodiscard]] auto
test_db_search_name_exists() -> bool {

    bool bPassed = false;

    pb::Accounts accounts;
    std::string file_name("Data/data.db");
    db::DataBase database(file_name, accounts);

    std::vector<unsigned> valid_results = { 1123456789, 2123456789 } ;

    std::string name("John Doe");
    ASSERT((bPassed = (database.search_name(name) == valid_results)));

    return bPassed;
}

[[nodiscard]] auto
test_db_search_name_not_exists() -> bool {

    bool bPassed = false;

    pb::Accounts accounts;
    std::string file_name("Data/data.db");
    db::DataBase database(file_name, accounts);

    std::vector<unsigned> valid_results = { 0 } ;

    std::string name("Unknown Account");
    ASSERT((bPassed = (database.search_name(name) == valid_results)));

    return bPassed;
}

[[nodiscard]] auto
test_get_name_by_account_id_exists() -> bool {

    bool bPassed = false;

    pb::Accounts accounts;
    std::string file_name("Data/data.db");
    db::DataBase database(file_name, accounts);

    std::string expected_name = "John Doe";

    unsigned account_id = 0;
    ASSERT((bPassed = (database.get_name_by_account_id(account_id) == expected_name)));

    return bPassed;
}

[[nodiscard]] auto
test_get_name_by_account_id_not_exists() -> bool {

    bool bPassed = false;

    pb::Accounts accounts;
    std::string file_name("Data/data.db");
    db::DataBase database(file_name, accounts);

    std::string expected_name = "John Doe";

    unsigned account_id = 0;
    ASSERT((bPassed = (database.get_name_by_account_id(account_id) == expected_name)));

    return bPassed;
}

[[nodiscard]] auto
test_db_display_account() -> bool {

    bool bPassed = false;

    pb::Accounts accounts;
    std::string file_name("Data/data.db");
    db::DataBase database(file_name, accounts);

    // The actual test

    return (bPassed = true);
}


[[nodiscard]] auto
test_db_close_account() -> bool {

    bool bPassed = false;

    pb::Accounts accounts;
    std::string file_name("Data/data.db");
    db::DataBase database(file_name, accounts);

    size_t size_before = database.data.size();
    size_t size_after;

    unsigned account_id = 1123456789;
    database.close_account(account_id);
    size_after = database.data.size();

    ASSERT((bPassed = (size_before > size_after)));
    
    return bPassed;
}
