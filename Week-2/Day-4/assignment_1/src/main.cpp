/**
 * Creator: VPR
 * Created: December 5, 2021
 * Updated: December 5, 2021
 *
 * Description:
 *     - [x] Write a class which implements Grade with 
 *           4 possible scores.
**/


#include <iostream>

#define GRADE_A 40
#define GRADE_B 30
#define GRADE_C 20
#define GRADE_D 10

[[nodiscard]] auto
grade(const int&& score) -> char {

    return (score == GRADE_A) * 'A' +
           (score == GRADE_B) * 'B' +
           (score == GRADE_C) * 'C' +
           (score == GRADE_D) * 'D';

}

int main() {

    std::cout << "Calculate scores with no if statements:\n\n";

    int scores[4] = { 10, 30, 20, 20 };
    for (const auto& x : scores) {
        auto f = [](auto x){ return x; };
        std::cout << "Grade of " << x << " = " << grade( f(x) ) << std::endl;
    }

    return 0;
}
