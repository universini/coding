#include <iostream>
#include <vector>

void setZeroes(std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();

    bool firstRowHasZero = false;
    bool firstColHasZero = false;

    // Check if the first row has a zero
    for (int j = 0; j < cols; ++j) {
        if (matrix[0][j] == 0) {
            firstRowHasZero = true;
            break;
        }
    }

    // Check if the first column has a zero
    for (int i = 0; i < rows; ++i) {
        if (matrix[i][0] == 0) {
            firstColHasZero = true;
            break;
        }
    }

    // Mark zeroes in the first row and column
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (matrix[i][j] == 0) {
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    // Set zeroes based on marks in the first row and column
    for (int i = 1; i < rows; ++i) {
        for (int j = 1; j < cols; ++j) {
            if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                matrix[i][j] = 0;
            }
        }
    }

    // Set zeroes for the first row and column if needed
    if (firstRowHasZero) {
        for (int j = 0; j < cols; ++j) {
            matrix[0][j] = 0;
        }
    }

    if (firstColHasZero) {
        for (int i = 0; i < rows; ++i) {
            matrix[i][0] = 0;
        }
    }
}

void printMatrix(const std::vector<std::vector<int>>& matrix) {
    int rows = matrix.size();
    int cols = matrix[0].size();
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            std::cout << matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    std::vector<std::vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    std::cout << "Original matrix:" << std::endl;
    printMatrix(matrix);

    setZeroes(matrix);

    std::cout << "\nMatrix after setting zeroes:" << std::endl;
    printMatrix(matrix);

    return 0;
}
