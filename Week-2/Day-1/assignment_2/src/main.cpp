/*
 * Creator: VPR
 * Created: December 5, 2021
 * Updated: December 5, 2021
 *
 * Description:
 *     - [x] Non-const function
 *     - [x] Const function
**/

#include <iostream>

struct Fptr {

    void foo(float f) {
        f += 1.0f;
        std::cout << "f = " << f << std::endl;
    }

    void bar(float f) const {
        f -= 69.0f;
        std::cout << "f = " << f << std::endl;
    }

};

int main() {
    
    Fptr fptr;
    const Fptr const_fptr;

    int f = 420;

    // Will not work with const_fptr
    std::cout << "fptr.foo(" << f << ");\n";
    fptr.foo(f);

    // Will work with either const_fptr or fptr
    std::cout << "const_fptr.bar(" << f << ");\n";
    const_fptr.bar(f);

    return 0;
}
