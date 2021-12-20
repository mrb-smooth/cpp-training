/**
 * Creator: VPR
 * Created: December 16th, 2021
 * Updated: December 20th, 2021
 *
 * Description:
 *     An improved command line banking application that utilizes
 *     - [ ] AES password encryption
 *     - [x] Google Protobuf for data serialization
 *     - [x] Google Protobuf for data persistence
 *     - [x] Custom interfaces for enhanced logging capabilities
**/

#include "Authentication.hpp"
#include "DataBase.hpp"
#include "Client.hpp"
#include "Utils.hpp"

#include <Account.pb.h>

std::string file_name;

int main(int argc, char* argv[]) {

    GOOGLE_PROTOBUF_VERIFY_VERSION;

    if (argc < 2) {
        __usage_error(argv[0]);
        return -1;
    } else {
        file_name = argv[1];
    }

    // Initialize protobuf
    auto accounts = pb::Accounts();

    // Initialize dataBase
    db::DataBase dataBase(file_name, accounts);
    
    // Main Loop
    auth::login();          // Verify username and password
    client::app(dataBase);  // Main loop 

    return 0;
}
