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

    // Small float
    float small_num_f = 5.f;

    std::cout << "Floating point accuracy demonstration for small floating point numbers:\n";
    std::cout << "Small float initial value: " << small_num_f << "\n\n";
    for (int i = 1; i <= 3; i++)
    {
        float temp = i * 10000000;
        std::cout << small_num_f << " - " << temp << " = " << small_num_f - temp << "\n";
        std::cout << "small_num_f - i * 10000000 == small_num_f: " << (small_num_f - temp == small_num_f ? "True" : "False") << "\n\n";
    }
    std::cout << "\n";

    // Bit hacking for large float
    int large_num_i = 0x6FFFFFFF;
    float large_num_f = *(float *)(&large_num_i);

    std::cout << "Floating point accuracy demonstration for large floating point numbers:\n";
    std::cout << "Large float initial value: " << large_num_f << "\n\n";
    for (int i = 1; i <= 3; i++)
    {
        float temp = i * 10000000;
        std::cout << large_num_f << " - " << temp << " = " << large_num_f - temp << "\n";
        std::cout << "large_num_f - i * 10000000 == large_num_f: " << (large_num_f - temp == large_num_f ? "True" : "False") << "\n\n";
    }
    std::cout << "\n";

    return 0;
}
