/**
 * Creator: VPR
 * Created: December 5, 2021
 * Updated: December 5, 2021
 *
 * Description:
 *    [ ] Matrix stuff 
**/

#include <iostream>
#include <cstdlib>
#include <vector>

typedef std::vector<std::vector<int>> matrix;

matrix GenerateMatrix(int, int);
bool IsValidPair(matrix, matrix);
void DisplayMatrix(matrix);
matrix GetMatrixProduct(matrix, matrix);

int main() {

    srand(time(NULL));

    matrix m_a = GenerateMatrix(5, 6);
    matrix m_b = GenerateMatrix(5, 6);

    if (IsValidPair(m_a, m_b)) {
        std::cout << "Valid matrices.\n";
    } else {
        std::cerr << "Valid matrices.\n";
        return -1;
    }

    std::cout << "Matrix a:\n";
    DisplayMatrix(m_a);
    std::cout << "Matrix b:\n";
    DisplayMatrix(m_b);
    std::cout << "Product of Matrices a and b:\n";
    DisplayMatrix(GetMatrixProduct(m_a, m_b));

    return 0;
}

matrix GenerateMatrix(int row, int col) {
    
    matrix result(row);

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            result[i].push_back(rand() % 10);
        }
    }

    return result;
}

bool IsValidPair(matrix a, matrix b) {

    // Make sure size of matrix is the same
    if (a.size() != b.size()) {
        return false;
    }

    // Make sure sizes of sub-vectors are the same
    for (unsigned i = 0; i < a.size(); i++) {
        if (a[i].size() != b[i].size()) {
            return false;
        }
    }

    return true;
}

void DisplayMatrix(matrix m) {

    for (const auto& i : m) {
        for (const auto& v: i) {
            std::cout << v << (v < 10 ? "  " : " ");
        }
        std::cout << "\n";
    }
    std::cout << "\n";

}

matrix GetMatrixProduct(matrix a, matrix b) {

    matrix result(a.size());

    for (unsigned i = 0; i < a.size(); i++) {
        for (unsigned j = 0; j < a[i].size(); j++) {
            result[i].push_back(a[i][j] * b[i][j]);
        }
    }

    return result;
}
