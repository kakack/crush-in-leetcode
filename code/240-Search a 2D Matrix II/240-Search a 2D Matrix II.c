// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
 

// Example 1:


// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// Output: true
// Example 2:


// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
// Output: false
 

// Constraints:

// m == matrix.length
// n == matrix[i].length
// 1 <= n, m <= 300
// -10^9 <= matrix[i][j] <= 10^9
// All the integers in each row are sorted in ascending order.
// All the integers in each column are sorted in ascending order.
// -10^9 <= target <= 10^9



bool searchMatrix(int** matrix, int matrixSize, int* matrixColSize, int target){
    int m = matrixSize;
    int n = matrixColSize[0];
    int x = 0;
    int y = n - 1;
    while (x < m && y >= 0) {
        if (matrix[x][y] == target) {
            return true;
        } else if (matrix[x][y] > target) {
            y --;
        } else {
            x ++;
        }
    }
    return false;
}