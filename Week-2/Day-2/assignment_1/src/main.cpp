/**
 * Creator: VPR
 * Created: December 5, 2021
 * Updated: December 5, 2021
 *
 * Description:
 *     - [x] Fibonacci via recursion
**/

#include <iostream>

int32_t Fib(unsigned i) {

    if (i < 2) {
        return i;
    } else {
        return Fib(i - 1) + Fib(i - 2);
    }

}

int main() {

    std::cout << "First 50 Fibonacci numbers:\n" << std::flush;

    unsigned i; 
    for (i = 0; i < 50; i++) {
        std::cout << i << (i < 10 ? ":  " : ": ") << Fib(i) << "\n";
    }

    return 0;
}
