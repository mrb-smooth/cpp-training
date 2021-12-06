/**
 * Creator: VPR
 * Created: December 5, 2021
 * Updated: December 5, 2021
 *
 * Description:
 *     - [ ] Floating point magic
**/

#include <iostream>
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

    std::cout << "Enter a two numbers (integers or floating point numbers):\n";
    std::cout << "Numerator: ";
    std::cin >> numerator;
    std::cout << std::endl;
    std::cout << "Divisor: ";
    std::cin >> divisor;
    std::cout << std::endl;

    x = numerator / divisor;

    // Formula = J / (2^N)
    // J = 450828337098296
    // N = 55
    // J = (2 ^ N ) = 0.125129999999999963478103381930850446224212646484375
    std::cout << x << ": mantissa = "     << std::pow(10, (*(dType *)&x).bits) << std::endl;
    std::cout << x << ": exponent = " << (*(dType *)&x).exponent - 1023 << std::endl;

    return 0;
}
