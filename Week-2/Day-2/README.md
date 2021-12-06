# Overview

## 1. Fibonacci series and recursion
Write a program to generate an array of 50 Fibonacci terms of type int recursively.
What problems did you encounter while computing this? At what point? How do you detect
the problem? Does your compute give an error?

Note: You must use recursion to solve this problem.

## 2. Integer overflow
2. Given a b-bit int (for int32, b = 31), how would you determine the index of the largest
Fibonacci term that you can fit in int32? Solve this without brute computing the Fibonacci series
above. Verify your answer for a long.

Note: The Fibonacci series goes 1, 1, 2, 3, 5, 8, 21,...... So 5 is the index for 8.

Hint: There is a closed-form expression for the n-th Fibonacci number, Binet's formula,

F(n) = (phi^n - psi^n) / (phi - psi)

where

phi = (1 + 5^0.5)/2 and psi = (1-phi) = -1/phi

### Build & Run
```bash
make
./bin/fibonacci # will take forever
./bin/overflow
```

### Expected output
```
First 50 Fibonacci numbers:
0:  0
1:  1
2:  1
3:  2
4:  3
5:  5
6:  8
7:  13
8:  21
9:  34
10: 55
11: 89
12: 144
13: 233
14: 377
15: 610
16: 987
17: 1597
18: 2584
19: 4181
20: 6765
21: 10946
22: 17711
23: 28657
24: 46368
25: 75025
26: 121393
27: 196418
28: 317811
29: 514229
30: 832040
31: 1346269
32: 2178309
33: 3524578
34: 5702887
35: 9227465
36: 14930352
37: 24157817
38: 39088169
39: 63245986
40: 102334155
41: 165580141
42: 267914296
43: 433494437
44: 701408733
45: 1134903170
46: 1836311903
47: -1323752223
48: 512559680
49: -811192543
```
