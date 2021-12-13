#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>

namespace db {
    class DataBase;
}

class db::DataBase
{
public:
    std::string file_name;
    std::map<unsigned, std::vector<std::string>> data;

public:
    DataBase(std::string file_name) {
        this->file_name = file_name;

        if (!populate_database(file_name)) {
            // delete this;
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

private:
    bool populate_database(std::string file_name);
};

#endif // DATABASE_HPP
