#include <iostream>
#include <vector>

void rotate(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();

    // Transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            std::swap(matrix[i][j], matrix[j][i]);
        }
    }

    // Reverse each row
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n / 2; ++j) {
            std::swap(matrix[i][j], matrix[i][n - 1 - j]);
        }
    }
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::cout << "Original matrix:" << std::endl;
    printMatrix(matrix);

    rotate(matrix);

    std::cout << "\nMatrix after rotation:" << std::endl;
    printMatrix(matrix);

    return 0;
}
