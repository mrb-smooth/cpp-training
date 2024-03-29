# Overview

## Exercises
- [x] Arithmetic expressions
- [x] Truth table for cast operators
      Exercise: Generate a truth table for cast operators, when arithmetic
      operations are performed between two variables. For example int + float 
      gives a float.  Consider the types: int, float, char, bool

- [x] Operators: List the binary, unary and ternary operators with examples
- [x] Increment Operators
- [x] Implement the truth table for AND, OR and NOT operators.

## Questions
### Question 1
Exercise: Which of the following expressions will fail at runtime? Why? Why not?
```cpp
#include <iostream>
#include <cassert>

using namespace std;

int main(void) {
    assert(3 == 3.0);
    x = 3.1;
    assert(x == 3.1);
    assert(3.1 == 3.1);
    assert(true == 1.0);
    assert('a' == 97);
    int* p = 0;
    assert(NULL == p);
    assert(NULL == 0);
}
```

**the variable x was never initialized.**

### Question 2
Exercise: Will below program work with no errors? Why?

```cpp
#include <cassert>
 
int main(void) {
   int x = 4;
   int y = x+++2;

   assert(y == 6);
   assert(x == 5);
}
```

**Yes. The +++ operator just increments x after the rvalue of x+2 is assigned  
to y.**

### Question 3
What is the order of precedence of operators above when y is initialized to x+++2?

**The +++ operator increments x after the rvalue of x+2 is assigned  
to y.**

### Build & Run
```bash
make && ./bin/expressions-and-truths
```
