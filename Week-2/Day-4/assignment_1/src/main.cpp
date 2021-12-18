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

char grade(const int&& score) {

    return (score == GRADE_A) * 'A' +
           (score == GRADE_B) * 'B' +
           (score == GRADE_C) * 'C' +
           (score == GRADE_D) * 'D';
}

int main() {

    std::cout << "Calculate scores with no if statements:\n\n";

    int scores[4] = { 10, 30, 20, 20 };
    for (const auto& score : scores) {
        auto f = [&score]{ return score; };
        std::cout << "Grade of " << score << " = " << grade( f() ) << std::endl;
    }

    return 0;
}
