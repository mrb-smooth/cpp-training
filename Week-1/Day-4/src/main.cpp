/**
 * Creator: VPR
 * Created: December 5, 2021
 * Updated: December 5, 2021
 *
 * Description:
 *     - [ ] Arithmetic expressions
 *     - [ ] Truth table for cast operators
 *     - [ ] Operators: List the binary, unary and ternary operators with examples
 *     - [ ] Increment Operators
 *     - [ ] Implement the truth table for AND, OR and NOT operators.
**/

#include <iostream>

int main() {
    // Truth table for cast operators
    int x = 420;

    // Arithmetic expressions
    std::cout << "Arithmetic expressions:\n";
    std::cout << "Addition:\t"       << x << " + 69 = " << x + 69 << "\n";
    std::cout << "Subtraction:\t"    << x << " - 69 = " << x - 69 << "\n";
    std::cout << "Multiplication:\t" << x << " * 69 = " << x * 69 << "\n";
    std::cout << "Division:\t"       << x << " / 69 = " << x / 69 << "\n\n";

    ///////////////////////////////////////////////////////////////////////////

    // Truth table for cast operators
    // Exercise: Generate a truth table for cast operators, when arithmetic
    // operations are performed between two variables. For example int + float 
    // gives a float.  Consider the types: int, float, char, bool
    std::cout << "Truth table for cast operators(addition):\n";
    std::cout << "int\tfloat\tchar\tbool\tresult\n";
    // int + float
    std::cout << "1\t1\t0\t0\t" << typeid((int)69 + (float)420.0).name() << "\n";
    // int + char
    std::cout << "1\t0\t1\t0\t" << typeid((int)69 + (char)69.0).name() << "\n";
    // int + bool
    std::cout << "1\t0\t0\t1\t" << typeid((int)69 + (bool)true).name() << "\n";
    // float + char
    std::cout << "0\t1\t1\t0\t" << typeid((float)69.0 + (char)0x69).name() << "\n";
    // float + bool
    std::cout << "0\t1\t0\t1\t" << typeid((float)69 + (bool)true).name() << "\n";
    // char + bool
    std::cout << "0\t0\t1\t1\t" << typeid((char)0x69 + (bool)true).name() << "\n\n";

    ///////////////////////////////////////////////////////////////////////////

    std::cout << "Truth table for cast operators(increment):\n";
    std::cout << "int\tfloat\tchar\tbool\tresult\n";
    // int ++
    int tmp_i = 69; ++tmp_i;
    std::cout << "1\t0\t0\t0\t" << typeid(tmp_i).name() << "\n";
    // float ++
    float tmp_f = 69; ++tmp_f;
    std::cout << "0\t1\t0\t0\t" << typeid(tmp_f).name() << "\n";
    // char++
    char tmp_c = 0x69; ++tmp_c;
    std::cout << "0\t0\t1\t0\t" << typeid(tmp_c).name() << "\n";
    // bool++
    //bool tmp_b = false; //++tmp_b;
    std::cout << "0\t0\t0\t1\t" << "C++17 forbids this incrementation of bool per ISO standard.\n\n";

    ///////////////////////////////////////////////////////////////////////////

    std::cout << "Truth table for binary operators(&):\n";
    std::cout << "int\tfloat\tchar\tbool\tresult\n";
    // int & float
    std::cout << "1\t1\t0\t0\t" << "Invalid operands to expression ('int' and 'float')\n";
    // int & char
    std::cout << "1\t0\t1\t0\t" << typeid((int)69 & (char)69.0).name() << "\n";
    // int & bool
    std::cout << "1\t0\t0\t1\t" << typeid((int)69 & (bool)true).name() << "\n";
    // float & char
    std::cout << "0\t1\t1\t0\t" << "Invalid operands to expression ('float' and 'char')\n";
    // float & bool
    std::cout << "0\t1\t0\t1\t" << "Invalid operands to expression ('float' and 'bool')\n";
    // char & bool
    std::cout << "0\t0\t1\t1\t" << typeid((char)0x69 & (bool)true).name() << "\n\n";

    ///////////////////////////////////////////////////////////////////////////

    std::cout << "Truth table for binary operators(|):\n";
    std::cout << "int\tfloat\tchar\tbool\tresult\n";
    // int | float
    std::cout << "1\t1\t0\t0\t" << "Invalid operands to expression ('int' and 'float')\n";
    // int | char
    std::cout << "1\t0\t1\t0\t" << typeid((int)69 | (char)69.0).name() << "\n";
    // int | bool
    std::cout << "1\t0\t0\t1\t" << typeid((int)69 | (bool)true).name() << "\n";
    // float | char
    std::cout << "0\t1\t1\t0\t" << "Invalid operands to expression ('float' and 'char')\n";
    // float | bool
    std::cout << "0\t1\t0\t1\t" << "Invalid operands to expression ('float' and 'bool')\n";
    // char | bool
    std::cout << "0\t0\t1\t1\t" << typeid((char)0x69 | (bool)true).name() << "\n\n";

    ///////////////////////////////////////////////////////////////////////////

    std::cout << "Truth table for cast operators(!):\n";
    std::cout << "int\tfloat\tchar\tbool\tresult\n";
    // int ++
    std::cout << "1\t0\t0\t0\t" << typeid(!tmp_i).name() << "\n";
    // float ++
    std::cout << "0\t1\t0\t0\t" << typeid(!tmp_f).name() << "\n";
    // char++
    std::cout << "0\t0\t1\t0\t" << typeid(!tmp_c).name() << "\n";
    // bool++
    bool tmp_b = false; //++tmp_b;
    std::cout << "0\t0\t0\t1\t" << typeid(!tmp_b).name() << "\n";

    return 0;
}
