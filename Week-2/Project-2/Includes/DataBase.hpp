#ifndef DATABASE_HPP
#define DATABASE_HPP

#include "Accounts.hpp"
#include "Logging.hpp"

#include <Account.pb.h>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

namespace db {
    class DataBase;
}

class db::DataBase : public logging::Logger
{
public:
    pb::Accounts& db;
    std::string data_source;
    google::protobuf::Map<uint64_t, pb::Account>& data;
public:
    DataBase(std::string_view data_source, pb::Accounts& db)
        : logging::Logger(), db(db), data_source(data_source), data(*db.mutable_accounts())
    {

        if (!populate_database()) {
            log_info("Generating a new database...");
            generate_database();
        }

    }
    ~DataBase()
    {
        update_database();
    }
public: // Const
    std::vector<unsigned> search_name(const std::string& name) const;
    std::string get_name_by_account_id(unsigned account_id) const;

    void display_account(unsigned int account) const;

    bool find_account(uint64_t account) const;
    bool add_account(std::string, std::string);
    bool add_transaction(uint64_t account_id, double transaction);
public: // Non-const
    void close_account(unsigned account);
    void show_accounts() const;
public: // Inherited
    void log_info(const std::string_view& info) const;
    void log_error(const std::string_view& error) const;
    void log_warning(const std::string_view& warning) const;
private: // Private
    bool update_database();
    bool generate_database();
    bool populate_database();
};

#endif // DATABASE_HPP
