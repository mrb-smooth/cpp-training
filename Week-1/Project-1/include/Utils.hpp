#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>

void _Noreturn __usage_error(const char* exe) {

    std::cerr << "Usage error.\n"
                 "\n"
                 "Usage:\n"
                 "  " << exe << " path/to/file.txt";

    exit(1);
}

#endif // UTILS_HPP
