/*
LeetCode 73 - Set Matrix Zeroes

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*
Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?


Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
*/

void setZeroes(int** matrix, int matrixSize, int* matrixColSize){
    int m = matrixSize, n = matrixColSize[0];
    int rows[m];
    memset(rows, 0, m*sizeof(int));
    int cols[n];
    memset(cols, 0, n*sizeof(int));
    for (int i = 0 ; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            if (matrix[i][j] == 0) {
                rows[i] = 1;
                cols[j] = 1;
            }
        }
    }
    for (int i = 0 ; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            if (rows[i] == 1 || cols[j] == 1) {
                matrix[i][j] = 0;
            }
        }
    }
}
