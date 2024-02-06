#include <iostream>
#include <vector>

using namespace std;

// Function to search for an element in a sorted matrix
bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int rows = matrix.size();
    if (rows == 0) {
        return false;
    }

    int cols = matrix[0].size();
    if (cols == 0) {
        return false;
    }

    int row = 0;
    int col = cols - 1;

    // Start from the top-right corner
    while (row < rows && col >= 0) {
        if (matrix[row][col] == target) {
            return true;  // Element found
        } else if (matrix[row][col] < target) {
            // If the current element is less than the target, move down in the matrix
            row++;
        } else {
            // If the current element is greater than the target, move left in the matrix
            col--;
        }
    }

    return false;  // Element not found
}

int main() {
    vector<vector<int>> matrix = {
        {1, 4, 7, 11},
        {2, 5, 8, 12},
        {3, 6, 9, 16},
        {10, 13, 14, 17}
    };

    int target = 5;

    if (searchMatrix(matrix, target)) {
        cout << "Element " << target << " found in the matrix." << endl;
    } else {
        cout << "Element " << target << " not found in the matrix." << endl;
    }

    return 0;
}
