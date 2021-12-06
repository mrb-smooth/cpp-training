/**
 * Creator: VPR
 * Created: December 5, 2021
 * Updated: December 5, 2021
 *
 * Description:
 *     - [x] Implement a merge sort class, that uses a comparator method as a  
 *           member function pointers.
 *
 *       You can sort Students by their scores in range ([1..100]);
 *       You should use recursion, but hide it in a private method. The entry point sort() method should
 *       not call itself.
 *       
 *       struct Student {
 *           string studentId; // studentId is unique
 *           int score; // between [1..100]
 *           bool comparator(Student x, Student y); // returns true if score of x is less than score of y
 *       }
 *       
 *       class MergeSort {
 *           public:
 *               void sort(vector<Student>& students) {};  // don't use recursion directly here!
 *       }
**/

#include <iostream>
#include <cstdint>
#include <string>
#include <vector>
#include <cmath>

struct Student {

    std::string studentId; // studentId is unique
    int         score; // between [1..100]
    bool comparator(Student x, Student y); // returns true if score of x is less than score of y

};

class MergeSort {

    public:
        void sort(std::vector<Student>& students);  // don't use recursion directly here!

    private:
        void private_sort();
};

int main() {

    // MergeSort madness

    return 0;
}
