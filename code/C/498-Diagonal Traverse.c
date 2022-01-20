// Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.

 

// Example 1:


// Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,4,7,5,3,6,8,9]
// Example 2:

// Input: mat = [[1,2],[3,4]]
// Output: [1,2,3,4]
 

// Constraints:

// m == mat.length
// n == mat[i].length
// 1 <= m, n <= 10^4
// 1 <= m * n <= 10^4
// -10^5 <= mat[i][j] <= 10^5

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

 // 纯模拟
int* findDiagonalOrder(int** mat, int matSize, int* matColSize, int* returnSize){
    int row = matSize, col = matColSize[0], i = 0, j = 0;
    int* res = malloc(sizeof(int) * row * col);
    *returnSize = 0;
    bool up = true; // 往右上方向走
    while (i != row && j != col) {
        res[(*returnSize) ++] = mat[i][j];
        if (up) {
            i = i - 1; 
            j = j + 1;
            if (j >= col) {     // 到最右边了
                up = !up;
                i = i + 2;
                j = j - 1;
            } else if (i < 0) { // 到顶了
                up = !up;
                i ++;
            }
        } else {
            i = i + 1;
            j = j - 1;
            if ( i >= row) {    // 到底了
                up = !up;
                i = i - 1;
                j = j + 2;
            } else if (j < 0) {  // 到最左边了
                up = !up;
                j ++;
            }
        }
    }
    return res;
}