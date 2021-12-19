#include "Authentication.hpp"
#include "DataBase.hpp"
#include "Client.hpp"
#include "Utils.hpp"

#include <Account.pb.h>

std::string file_name;

int main(int argc, char* argv[]) {

    if (argc < 2) {
        __usage_error(argv[0]);
        return -1;
    } else {
        file_name = argv[1];
    }

    // Initialize dataBase
    //db::DataBase dataBase(file_name);

    db::Accounts a;
    a.set_account_number(1234567890);
    a.set_full_name(std::string("Test Name"));

    std::cout << a.account_number() << " " << a.full_name() << std::endl;

    std::ofstream ofs("db.data", std::ios_base::out | std::ios_base::binary);
    a.SerializeToOstream(&ofs);
    
    //auth::login();          // Verify username and password
    //client::app(dataBase);  // Main loop 

    return 0;
}
