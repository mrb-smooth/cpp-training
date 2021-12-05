/**
 * Creator: VPR
 * Created: December 5, 2021
 * Updated: December 5, 2021
 *
 * Description:
 *    [x] Convert array to vector
 *    [ ] Dissimilar arrays
**/

#include <iostream>
#include <variant>
#include <vector>

int main() {
    // Initialize array
    float arr[3] = { 1., 2., 3. };
    size_t size = 3; // size of space that array occupies
    
    // Reference array's start and end addresses
    std::vector<float> vec_of_arr(arr, arr + size);

    // Compare the two arrays
    for (const auto& i : vec_of_arr) {
        std::cout << i << " ";
    }
    std::cout << "\n"; // formatiing
    for (const auto& i : arr) {
        std::cout << i << " ";
    }
    std::cout << "\n\n" << std::flush; // formatting

    // Create dissimilar array
    std::vector<std::variant<int, float, double>> dissimilar_arr;

    dissimilar_arr.push_back((int)1);            // int
    dissimilar_arr.push_back((float)2.0);          // float
    dissimilar_arr.push_back((double)3.0000000001); // double

    for (const auto& i : dissimilar_arr) {
        // try with get_if:
        if (const auto intPtr (std::get_if<int>(&i)); intPtr) {
            std::cout << "(int) i = " << *intPtr << "\n";
        } else if (const auto floatPtr (std::get_if<float>(&i)); floatPtr) {
            std::cout << "(float) i = " << *floatPtr << "\n";
        } else if (const auto doublePtr (std::get_if<double>(&i)); doublePtr) {
            std::cout << "(double) i = " << *doublePtr << "\n";
        }
    }

    return 0;
}
