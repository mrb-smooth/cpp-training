/**
 * Creator: VPR
 * Created: December 5, 2021
 * Updated: December 5, 2021
 *
 * Description:
 *     - [x] Funky masking tech
**/

#include <iostream>
#include <cstdio>

#define OPERATION_ADD 0x01
#define OPERATION_SUB 0x02
#define OPERATION_MUL 0x04
#define INDEX_ADD     0x00
#define INDEX_SUB     0x01
#define INDEX_MUL     0x02

struct FooBar {

    static int add(int a, int b) { printf("(%d + %d) = ", a, b); return a + b; }
    static int sub(int a, int b) { printf("(%d - %d) = ", a, b); return a - b; }
    static int mul(int a, int b) { printf("(%d * %d) = ", a, b); return a * b; }

};

int (*funcptrs[3])(int, int) = { FooBar::add,   // 0000 0001
                                 FooBar::sub,   // 0000 0010
                                 FooBar::mul }; // 0000 0100

int compute(int a, int b, unsigned char funcmask) {

    if (funcmask & OPERATION_ADD) {
        return funcptrs[INDEX_ADD](a, b);
    } else if (funcmask & OPERATION_SUB) {
        return funcptrs[INDEX_SUB](a, b);
    } else if (funcmask & OPERATION_MUL) {
        return funcptrs[INDEX_MUL](a, b);
    }

    std::cerr << "Error: Unknown operation\n" << std::flush;

    return -1;
}

int main() {

    // Func mask
    int a = 420, b = 69;
    for (int i = 0; i < 3; i++) {
        unsigned char funky_mask = (1<<i);
        std::cout << "funcmask = (1<<" << i << "): " << compute(a, b, funky_mask) << std::endl;
    }

    return 0;
}
