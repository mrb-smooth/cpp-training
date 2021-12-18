/**
 * Creator: VPR
 * Created: December 5, 2021
 * Updated: December 18, 2021
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
#include <string>
#include <vector>

struct Student
{
    std::string studentId;
    int score;

    bool comparator(Student x, Student y) { return x.score < y.score; };
};

class MergeSort
{
private:
    static Student call;

public:
    static void sort(std::vector<Student>& students) {
       mergeSort(students , 0 , students.size()-1);
    }
    
private:
    static void merge(std::vector<Student>& students, int start , int mid , int end) {

        std::vector<Student> tmp;
        
        int i = start;
        int j = mid + 1;
        
        while (i <= mid && j <= end) {
            if (call.comparator(students[i] , students[j])) {
                tmp.push_back(students[i]);
                ++i;
            } else {
                tmp.push_back(students[j]);
                ++j;
            }
        }
        
        while (i <= mid) {
            tmp.push_back(students[i]);
            ++i;
        }

        while (j <= end) {
            tmp.push_back(students[j]);
            ++j;
        }
        
        for (int i = start; i <= end; ++i) {
            students[i].studentId = tmp[i - start].studentId;
            students[i].score = tmp[i-start].score;
        }
    }
    
    // Spliting vectors into halves
    static void mergeSort(std::vector<Student>& students,  int start , int end) {
        if (start < end) {
            int mid = (start + end) / 2;
            mergeSort(students, start, mid);
            mergeSort(students, mid + 1, end);
            merge(students, start , mid, end);
        }
    }

};

int main() {

    // Initialize students vector
    auto students = std::vector<Student>({
        Student{ "Josh", 90 },
        Student{ "VPR", 100 },
        Student{ "Manoj", 60 },
        Student{ "Jordan", 70 },
        Student{ "Calvin", 80 },
    });

    // MergeSort madness
    MergeSort::sort(students);
    
    // Display results
    for (const auto& s : students) {
        std::cout << s.studentId
                  << (s.studentId.size() < 7 ? "\t" : "\t\t")
                  << s.score << "\n";
    }

    return 0;
}
