/**
 * Creator: VPR
 * Created: December 5, 2021
 * Updated: December 11, 2021
 *
 * Description:
 *    [x] Matrix stuff 
**/

#include <iostream>
#include <cstdlib>
#include <vector>

typedef std::vector<std::vector<int>> matrix;

matrix GenerateMatrix(int, int);
bool IsValidPair(matrix, matrix);
void DisplayMatrix(matrix);
matrix GetMatrixCrossProduct(matrix, matrix);

int main() {

    srand(time(NULL));

    matrix m_a = GenerateMatrix(6, 5);
    matrix m_b = GenerateMatrix(5, 6);

    if (IsValidPair(m_a, m_b)) {
        std::cout << "Valid matrices.\n";
    } else {
        std::cerr << "Invalid matrices.\n";
        return -1;
    }

    std::cout << "Matrix a:\n";
    DisplayMatrix(m_a);
    std::cout << "Matrix b:\n";
    DisplayMatrix(m_b);
    std::cout << "Product of Matrices a and b:\n";
    DisplayMatrix(GetMatrixCrossProduct(m_a, m_b));

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

    // Make sure sizes of sub-vectors are the same
    for (unsigned i = 0; i < a.size(); i++) {
        if (a[i].size() != b.size()) {
            return false;
        }
    }

    return true;
}

void DisplayMatrix(matrix m) {

    for (const auto& i : m) {
        for (const auto& v: i) {
            std::cout << v << (v < 100 ? (v < 10 ? "   " : "  ") : " ");
        }
        std::cout << "\n";
    }
    std::cout << "\n";

}

matrix GetMatrixCrossProduct(matrix a, matrix b) {

    matrix result(a.size());

    // Zero Matrix
    for (auto& v : result) {
        for (unsigned i = 0; i < a.size(); i++) {
            v.push_back(i * 0);
        }
    }

    // Calculate cross product
    for (unsigned i = 0; i < result.size(); i++) {
        for (unsigned j = 0; j < a.size(); j++) {
            for (unsigned k = 0; k < b.size(); k++) {
                result[i][j] += a[i][k] * b[k][j];
            }
        }
    }

    return result;
}
