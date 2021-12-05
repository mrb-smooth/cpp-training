# Overview
### Arrays and vectors
- [x] Write a program that creates an array and converts it into a vector.
    - [x] Allocate an array of 3 floats.
    - [x] Initialize the array.
    - [x] Create a vector.
    - [x] Copy the elements of the array to the vector.
    - [x] Print out the vector elements on a single line and then an EOL at the end.
    - [x] Verify your result with the original array.

- Mixed arrays
    - [x] Dissimilar arrays
    - [x] Types in array

#### Dissimilar arrays
How would you store elements of dissimilar type in an array? Write a program to demonstrate 
that you can store int and float in the same array without using struct, or any class type.

**Using std::variant type**

#### Types in array
In the above example, once you have created the "mixed" array, is it possible to recognize the type
of each element automatically? If so, or if not, why? Show with a code example.

Yes
```cpp
#include <std::variant

(...)

// Try with std::get_if:
for (const auto& i : dissimilar_arr) {
    if (const auto intPtr (std::get_if<int>(&i)); intPtr) {
        std::cout << "(int) i = " << *intPtr << "\n";
    } else if (const auto floatPtr (std::get_if<float>(&i)); floatPtr) {
        std::cout << "(float) i = " << *floatPtr << "\n";
    } else if (const auto doublePtr (std::get_if<double>(&i)); doublePtr) {
        std::cout << "(double) i = " << *doublePtr << "\n";
    }
}

(...)
```

### Build & Run
```bash
make && ./bin/arrays-and-vectors
```
