# Overview
- [x] Working with types
Write a program that takes as input a type such as "int", "double" and "char" using cin,
and your program computes the size of that type and outputs the size using cout.  
So for instance, the sizeof(int) may print as 4.

- [x] C++ type idiosyncrasies
Point out the limitations of your solution? Compare it with other programming languages you are aware of. 
(200 words max).

**Overflow possible. Haskell and Python handle these dynamically, for the most part.**

- [x] C++ Debugging
What C++ compiler option you need to use to make your C++ program ready for debugging?
You can use the https://linux.die.net/man/1/g++ for reference, and most g++ options are compatible with clang++.

- [x] C++ Compiler Options
What C++ compiler option you need to use to suppress generating only object code and not final executable?

**-o**

- [x] Float Precision
How would you measure the precision of a floating point number? Write a program to demonstrate how the
precision decreases as a float gets larger.

### Build & Run
```bash
make && ./bin/type-magic
```

### Expected output
```
Enter an integer, a double, and a characterSeparated by spaces and/or lines:
1 2 c

64 bit machine detected.
size of x:      4
size of y:      8
size of z:      1

Floating point accuracy demonstation:
Large float initial value: 1.58456e+29

1.58456e+29 - 1e+07 = 1.58456e+29
1.58456e+29 - 2e+07 = 1.58456e+29
1.58456e+29 - 3e+07 = 1.58456e+29
```
