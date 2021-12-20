#ifndef TEST_SUITE_HPP
#define TEST_SUITE_HPP

#ifndef TEST
#define TEST(X) std::cout << "Testing: " << #X << std::endl;\
                std::cout << "Test " << ( X() ? "passed" : "failed") << ".\n\n"
#endif // TEST

#ifndef ASSERT
#define ASSERT(ASSERTION) ( ASSERTION ? g_tests_passed++ : g_tests_failed++ )
#endif // ASSERT

#endif // TEST_SUITE_HPP
