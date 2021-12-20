#include "DataBaseTest.hpp"

#include "TestSuite.hpp"
#include "DataBase.hpp"

#include <filesystem>

extern unsigned g_tests_failed;
extern unsigned g_tests_passed;

static const std::string data_source = "Data/test.db";

[[nodiscard]] auto
test_db_find_account_exists() -> bool {

    bool bPassed = false;

    if (std::filesystem::exists(data_source)) {
        std::filesystem::remove(data_source);
    }

    pb::Accounts accounts;
    std::string file_name(data_source);
    db::DataBase database(file_name, accounts);

    ASSERT((bPassed = (database.find_account(1000000001) == true)));

    return bPassed;
}

[[nodiscard]] auto
test_db_find_account_not_exists() -> bool {

    bool bPassed = false;

    if (std::filesystem::exists(data_source)) {
        std::filesystem::remove(data_source);
    }

    pb::Accounts accounts;
    std::string file_name(data_source);
    db::DataBase database(file_name, accounts);

    ASSERT((bPassed = (database.find_account(999999999) == false)));

    return bPassed;
}

[[nodiscard]] auto
test_db_add_account_exists() -> bool {

    bool bPassed = false;

    if (std::filesystem::exists(data_source)) {
        std::filesystem::remove(data_source);
    }

    pb::Accounts accounts;
    std::string file_name(data_source);
    db::DataBase database(file_name, accounts);

    std::string name("John Doe"), ssn("555-55-1234");
    ASSERT((bPassed = (database.add_account(name, ssn) == false)));

    return bPassed;
}

[[nodiscard]] auto
test_db_add_account_not_exists() -> bool {

    bool bPassed = false;

    if (std::filesystem::exists(data_source)) {
        std::filesystem::remove(data_source);
    }

    pb::Accounts accounts;
    std::string file_name(data_source);
    db::DataBase database(file_name, accounts);

    std::string name("New Account"), ssn("955-55-5555");
    ASSERT((bPassed = (database.add_account(name, ssn) == true)));

    return bPassed;
}

[[nodiscard]] auto
test_db_search_name_exists() -> bool {

    bool bPassed = false;

    if (std::filesystem::exists(data_source)) {
        std::filesystem::remove(data_source);
    }

    pb::Accounts accounts;
    std::string file_name(data_source);
    db::DataBase database(file_name, accounts);

    std::vector<unsigned> valid_results = { 1'000'000'001, 1'000'000'002 } ;

    std::string name("John Doe");
    ASSERT((bPassed = (database.search_name(name) == valid_results)));

    return bPassed;
}

[[nodiscard]] auto
test_db_search_name_not_exists() -> bool {

    bool bPassed = false;

    if (std::filesystem::exists(data_source)) {
        std::filesystem::remove(data_source);
    }

    pb::Accounts accounts;
    std::string file_name(data_source);
    db::DataBase database(file_name, accounts);

    std::vector<unsigned> valid_results = { } ;

    std::string name("Unknown Account");
    ASSERT((bPassed = (database.search_name(name) == valid_results)));

    return bPassed;
}

[[nodiscard]] auto
test_db_add_transaction_sufficient_funds() -> bool {

    bool bPassed = false;

    if (std::filesystem::exists(data_source)) {
        std::filesystem::remove(data_source);
    }

    pb::Accounts accounts;
    std::string file_name(data_source);
    db::DataBase database(file_name, accounts);

    ASSERT((bPassed = (database.add_transaction(1000000001, 100) == true)));

    return bPassed;
}

[[nodiscard]] auto
test_db_add_transaction_insufficient_funds() -> bool {

    bool bPassed = false;

    if (std::filesystem::exists(data_source)) {
        std::filesystem::remove(data_source);
    }

    pb::Accounts accounts;
    std::string file_name(data_source);
    db::DataBase database(file_name, accounts);

    ASSERT((bPassed = (database.add_transaction(1000000001, -101) == false)));
    
    return bPassed;
}

[[nodiscard]] auto
test_db_get_name_by_account_id_exists() -> bool {

    bool bPassed = false;

    if (std::filesystem::exists(data_source)) {
        std::filesystem::remove(data_source);
    }

    pb::Accounts accounts;
    std::string file_name(data_source);
    db::DataBase database(file_name, accounts);

    std::string expected_name = "John Doe";

    unsigned account_id = 1000000001;
    ASSERT((bPassed = (database.get_name_by_account_id(account_id) == expected_name)));

    return bPassed;
}


[[nodiscard]] auto
test_db_get_name_by_account_id_not_exists() -> bool {

    bool bPassed = false;

    if (std::filesystem::exists(data_source)) {
        std::filesystem::remove(data_source);
    }

    pb::Accounts accounts;
    std::string file_name(data_source);
    db::DataBase database(file_name, accounts);

    std::string expected_name = "";

    unsigned account_id = 0;
    ASSERT((bPassed = (database.get_name_by_account_id(account_id) == expected_name)));

    return bPassed;
}

[[nodiscard]] auto
test_db_close_account_exists() -> bool {

    bool bPassed = false;

    if (std::filesystem::exists(data_source)) {
        std::filesystem::remove(data_source);
    }

    pb::Accounts accounts;
    std::string file_name(data_source);
    db::DataBase database(file_name, accounts);

    size_t size_before = database.data.size();
    size_t size_after;

    unsigned account_id = 1000000001;
    database.close_account(account_id);
    size_after = database.data.size();

    ASSERT((bPassed = (size_before > size_after)));
    
    return bPassed;
}

[[nodiscard]] auto
test_db_close_account_not_exists() -> bool {

    bool bPassed = false;

    if (std::filesystem::exists(data_source)) {
        std::filesystem::remove(data_source);
    }

    pb::Accounts accounts;
    std::string file_name(data_source);
    db::DataBase database(file_name, accounts);

    size_t size_before = database.data.size();
    size_t size_after;

    unsigned account_id = 0;
    database.close_account(account_id);
    size_after = database.data.size();

    ASSERT((bPassed = (size_before == size_after)));
    
    return bPassed;
}
