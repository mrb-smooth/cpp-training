/**
 * Creator: VPR
 * Created: December 5th, 2021
 * Updated: December 13th, 2021
 *
 * Description:
 *     - [x] Floating point magic
**/

#include <iostream>
#include <iomanip>
#include <cmath>

struct dType {
    unsigned long bits:52;
    unsigned exponent:11;
    unsigned sign:1;
};

int main() {

    double numerator;
    double divisor;
    double x;

    // Get numerator
    std::cout << "Enter a two numbers (integers or floating point numbers):\n";
    std::cout << "Numerator: ";
    std::cin >> numerator;
    std::cout << std::endl;

    // Get divisor
    std::cout << "Divisor: ";
    std::cin >> divisor;
    std::cout << std::endl;

    if (divisor == 0) {
        std::cerr << "cmon bruh";
    }

    x = numerator / divisor;

    dType converted_x = *reinterpret_cast<dType *>(&x);
    unsigned long j_bits = (converted_x.bits ? converted_x.bits : 1);
    int exp = converted_x.exponent - 1023;

    std::cout << x << ": J = "        << j_bits << std::endl;
    std::cout << x << ": exponent = " << exp << std::endl;
    std::cout << x << ": approximate value = " << std::setprecision(15) << j_bits * std::pow(2, exp) << std::endl;

    return 0;
}
