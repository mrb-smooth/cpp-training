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
    std::string file_name;
    //std::map<unsigned, std::vector<std::string>> data;
    google::protobuf::Map<uint32_t, accounts::Account> data;
public:
    DataBase(std::string file_name) : logging::Logger(), file_name(file_name) {

        if (!populate_database(file_name)) {
            log_error("Failed to parse database: '" + file_name + "'.");
        }

    }
    ~DataBase(){}
public:
    std::string FileName() const { return this->file_name; }
public:
    bool find_account(unsigned int account) const;
    bool add_account(std::string, std::string);

    std::vector<unsigned> search_name(const std::string& name) const;
    std::string get_name_by_account_id(unsigned account_id) const;

    void display_account(unsigned int account) const;
    void close_account(unsigned account);
    void show_accounts() const;
public:
    void log_info(const std::string_view& info) const;
    void log_error(const std::string_view& error) const;
    void log_warning(const std::string_view& warning) const;
private:
    bool populate_database(std::string file_name);
};

#endif // DATABASE_HPP
