Given an m x n integers matrix, return the length of the longest increasing path in matrix.

// From each cell, you can either move in four directions: left, right, up, or down. You may not move diagonally or move outside the boundary (i.e., wrap-around is not allowed).

 

// Example 1:


// Input: matrix = [[9,9,4],[6,6,8],[2,1,1]]
// Output: 4
// Explanation: The longest increasing path is [1, 2, 6, 9].
// Example 2:


// Input: matrix = [[3,4,5],[3,2,6],[2,2,1]]
// Output: 4
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
// Example 3:

// Input: matrix = [[1]]
// Output: 1
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= m, n <= 200
// 0 <= matrix[i][j] <= 2^31 - 1

const int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int rows, columns;

int dfs(int** matrix, int row, int column, int** memo) {
    if (memo[row][column] != 0) {
        return memo[row][column];
    }
    memo[row][column] ++;
    for (int i = 0; i < 4; i ++) {
        int newRow = row + dirs[i][0], newCol = column + dirs[i][1];
        if (newRow >= 0 && newRow < rows && newCol >= 0 && newCol < columns && matrix[newRow][newCol] > matrix[row][column]) {
            memo[row][column] = fmax(memo[row][column], dfs(matrix, newRow, newCol, memo) + 1);
        }
    }
    return memo[row][column];
}

int longestIncreasingPath(int** matrix, int matrixSize, int* matrixColSize){
    rows = matrixSize;
    columns = matrixColSize[0];
    if (rows == 0 || columns == 0) {
        return 0;
    }
    int** memo = (int**)malloc(sizeof(int*) * rows);
    for (int i = 0; i < rows; i++) {
        memo[i] = (int*)malloc(sizeof(int) * columns);
        memset(memo[i], 0, sizeof(int) * columns);
    }
    int res = 0;
    for (int i = 0; i < rows; i ++) {
        for (int j = 0; j < columns; j ++) {
            res = fmax(res, dfs(matrix, i, j, memo));
        }
    }
    free(memo);
    return res;
}