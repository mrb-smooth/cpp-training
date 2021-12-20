#include "TestSuite.hpp"
#include "Authentication.hpp"

using auth::verify_username;
using auth::verify_password;

extern unsigned g_tests_failed;
extern unsigned g_tests_passed;

[[nodiscard]] auto
test_auth_verify_username_correct() -> bool {

    bool bPassed = false;

    std::string username("demo");
    ASSERT( (bPassed = (verify_username(username) == true)) );

    return bPassed;
}

[[nodiscard]] auto
test_auth_verify_username_incorrect() -> bool {

    bool bPassed = false;

    std::string username("badmin");
    ASSERT((bPassed = (verify_username(username) == false)));

    return bPassed;
}

[[nodiscard]] auto
test_auth_verify_password_correct() -> bool {

    bool bPassed = false;

    std::string password("demo");
    ASSERT((bPassed = (verify_password(password) == true)));

    return bPassed;
}

[[nodiscard]] auto
test_auth_verify_password_incorrect() -> bool {

    bool bPassed = false;

    std::string password("incorrect");
    ASSERT((bPassed = (verify_password(password) == false)));

    return bPassed;
}
