#include <iostream>
#include <cstdint>

int main() {
    int    x;
    double y;
    char   z;

    std::cout << "Enter an integer, a double, and a character"
              << "Separated by spaces and/or lines:\n";
    std::cin >> x >> y >> z;
    std::cout << "\n";

#if (INTPTR_MAX == INT64_MAX)
    std::cout << "64 bit machine detected.\n";
#else
    std::cout << "32 bit machine detected.\n";
#endif

    std::cout << "size of x:\t" << sizeof(x) << std::endl;
    std::cout << "size of y:\t" << sizeof(y) << std::endl;
    std::cout << "size of z:\t" << sizeof(z) << "\n" << std::endl;

    int a_i = 0x6FFFFFFF;
    float a_f = *(float *)(&a_i);
    std::cout << "Floating point accuracy demonstation:\n";
    std::cout << "Large float initial value: " << a_f << "\n\n";
    for (int i = 1; i <= 3; i++)
    {
        float temp = i * 10000000;
        std:: cout << a_f << " - " << temp << " = " << a_f - temp << "\n";
    }
    std::cout << "\n";

    return 0;
}
