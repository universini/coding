
#include <iostream>
#include <vector>
#include <stdexcept>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cmath>
#include <sstream>
#include <iomanip>

using namespace std;

vector<vector<int>> matrixMultiplication(const vector<vector<int>>& m1, const vector<vector<int>>& m2)
{
    int rows1 = m1.size();
    int cols1 = m1[0].size();
    int rows2 = m2.size();
    int cols2 = m2[0].size();

    if (cols1 != rows2)
        throw runtime_error("Matrix dimensions are not compatible for multiplication");

    vector<vector<int>> result(rows1, vector<int>(cols2, 0));

    for (int i = 0; i < rows1; ++i)
        for (int j = 0; j < cols2; ++j)
            for (int k = 0; k < cols1; ++k)
                result[i][j] += m1[i][k] * m2[k][j];

    return result;
}

void printMatrix(const vector<vector<int>>& matrix)
{
    for (const auto& row : matrix)
    {
        for (int elem : row)
            cout << elem << " ";
        cout << endl;
    }
}

int main()
{
    vector<vector<int>> m1 = {{1, 2, 3},
                                   {4, 5, 6}};

    vector<vector<int>> m2 = {{7, 8},
                                   {9, 10},
                                   {11, 12}};

    cout << "Matrix 1:" << endl;
    printMatrix(m1);

    cout << "\nMatrix 2:" << endl;
    printMatrix(m2);

    try
    {
        vector<vector<int>> result = matrixMultiplication(m1, m2);
        cout << "\nResult of matrix multiplication:" << endl;
        printMatrix(result);
    }
    catch (const runtime_error& e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    return 0;
}