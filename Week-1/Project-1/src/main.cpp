#include "Authentication.hpp"
#include "DataBase.hpp"
#include "Client.hpp"
#include "Utils.hpp"

std::string file_name;

int main(int argc, char* argv[]) {

    if (argc < 2) {
        __usage_error(argv[0]);
        return -1;
    } else {
        file_name = argv[1];
    }

    // Initialize dataBase
    db::DataBase dataBase(file_name);
    
    auth::login();          // Verify username and password
    client::app(dataBase);  // Main loop 

    return 0;
}
