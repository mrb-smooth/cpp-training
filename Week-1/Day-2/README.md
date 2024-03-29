# Overview
- [x] Working with types
Write a program that takes as input a type such as "int", "double" and "char" using cin,
and your program computes the size of that type and outputs the size using cout.  
So for instance, the sizeof(int) may print as 4.

- [x] C++ type idiosyncrasies
Point out the limitations of your solution? Compare it with other programming languages you are aware of. 
(200 words max).

**Answer: Overflow possible. Haskell and Python handle these dynamically, for the most part.**

- [x] C++ Debugging
What C++ compiler option you need to use to make your C++ program ready for debugging?
You can use the https://linux.die.net/man/1/g++ for reference, and most g++ options are compatible with clang++.

**Answer: -g**

- [x] C++ Compiler Options
What C++ compiler option you need to use to suppress generating only object code and not final executable?

**Answer: -c**

- [x] Float Precision
How would you measure the precision of a floating point number? Write a program to demonstrate how the
precision decreases as a float gets larger.

**Answer: I would test to see if the difference between the two numbers is arbitrarily small.**  
$$| a - b | < 1^{-9}$$

### Build & Run
```bash
make
echo "1 2 3" | ./bin/type-magic
```
