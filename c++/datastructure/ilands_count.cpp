#include <iostream>
#include <cmath>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

const int directions[][2] = {
                                {-1, 0},
                                {1, 0},
                                {0, -1},
                                {0, 1}
                            };
                            
void DFS(vector<vector<int> >& matrix, int row, int col)
{
    matrix[row][col] = 0;
    
    for (const auto& dir : directions)
    {
        int row_1 = row + dir[0];
        int col_1 = col + dir[1];
        
        
        if (row_1 >=0 && row_1 < matrix.size() &&
            col_1 >=0 && col_1 < matrix[0].size() &&
            matrix[row_1][col_1] == 1)
        {
            DFS(matrix, row_1, col_1);
        }
    }
}

int count_islands(vector<vector<int> >& matrix)
{
    int count = 0;
    
    for (int i=0; i < matrix.size(); ++i)
    {
        for(int j=0; j < matrix[0].size(); ++j)
        {
            if (matrix[i][j] == 1)
            {
                DFS(matrix, i, j);
                ++count;
            }        
        }
    }
    return count;
}

int main(void)
{
    vector<vector<int>> matrix = {
        {1,1,0,1,0},
        {1,1,0,1,0},
        {1,1,0,0,0},
        {0,0,0,0,1}
        };

    cout << "number of islands: " << count_islands(matrix) << endl;
 
    return(0);
}


// matrix2 = { {0,1,0,0,0},
//             {1,1,0,0,0},
//             {0,0,0,0,1},
//             {0,0,0,1,1}
//             };

// Your old code in python3 has been preserved below.
// '''
// Matrix of m x n size represents a map of '1's (land) and '0's (water). Task is to return the number of unique islands.
// Definition of island: An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. All four edges of the matrix are all surrounded by water.

// Input1: grid = [
//   ["1","1","0","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","1"]
// ]
// Output: 3

// Input2: grid = [
//   ["0","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","1"],
//   ["0","0","0","1","1"]
// ]
// Output: 1

// Input3: grid = [
//   ["0","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","1","1"],
//   ["0","0","0","1","0"]
// ]
// Output: 2
// '''
