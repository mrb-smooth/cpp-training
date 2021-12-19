#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include "Transactions.hpp"

#include <string>
#include <vector>

namespace accounts {
    struct Account;
}

struct accounts::Account
{
    std::string full_name;
    std::string social_security;
    std::string date_created_dt;
    std::vector<transaction::Transaction> transactions;
};

#endif // ACCOUNT_HPP
