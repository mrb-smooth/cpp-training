/**
 * Creator: VPR
 * Created: December 5, 2021
 * Updated: December 5, 2021
 *
 * Description:
 *     - [x] Fibonacci overflow
 *
 *     2. Given a b-bit int (for int32, b = 31), how would you determine the index of the largest
 *     Fibonacci term that you can fit in int32? Solve this without brute computing the Fibonacci series
 *     above. Verify your answer for a long.
 *     
 *     Note: The Fibonacci series goes 1, 1, 2, 3, 5, 8, 21,...... So 5 is the index for 8.
 *     
 *     Hint: There is a closed-form expression for the n-th Fibonacci number, Binet's formula,
**/

#include <iostream>
#include <cstdint>
#include <cmath>

int64_t FastFib(unsigned i) {

    static const double phi = ( 1 + std::sqrt(5) ) / 2;

    return std::round( (std::pow(phi, i) - std::pow((1 - phi), i)) / std::sqrt(5) );
}

unsigned InverseFastFib(int32_t i) {

    static const double phi = ( 1 + std::sqrt(5) ) / 2;

    return std::floor( log(i * sqrt(5) + 1/2) / log(phi) );

}

int main() {

    // Calculate last idx before overflow
    unsigned res = InverseFastFib(INT32_MAX);
    std::cout << "Last index before overflow: " << res << "\n";

    return 0;
}
