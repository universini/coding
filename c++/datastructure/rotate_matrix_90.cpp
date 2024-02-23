#include <iostream>
#include <vector>

void rotateMatrix(std::vector<std::vector<int>>& matrix) {
    int n = matrix.size();

    // Transpose the matrix
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
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
    for (const auto& row : matrix) {
        for (int value : row) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::cout << "Original Matrix:" << std::endl;
    printMatrix(matrix);

    rotateMatrix(matrix);

    std::cout << "\nMatrix After 90-degree Clockwise Rotation:" << std::endl;
    printMatrix(matrix);

    return 0;
}
