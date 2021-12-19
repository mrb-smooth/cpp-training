#ifndef TRANSACTIONS_HPP
#define TRANSACTIONS_HPP

#include <cstdint>
#include <string>

namespace transaction {
    struct Transaction;
}

struct transaction::Transaction
{
    int64_t amount_sent;
    int64_t amount_recv;
    std::string transaction_dt;
};

#endif // TRANSACTIONS_HPP
