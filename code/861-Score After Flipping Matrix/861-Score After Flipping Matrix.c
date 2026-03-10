/*
LeetCode 861 - Score After Flipping Matrix

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// You are given an m x n binary matrix grid.

// A move consists of choosing any row or column and toggling each value in that row or column (i.e., changing all 0's to 1's, and all 1's to 0's).

// Every row of the matrix is interpreted as a binary number, and the score of the matrix is the sum of these numbers.

// Return the highest possible score after making any number of moves (including zero moves).



// Example 1:


// Input: grid = [[0,0,1,1],[1,0,1,0],[1,1,0,0]]
// Output: 39
// Explanation: 0b1111 + 0b1001 + 0b1111 = 15 + 9 + 15 = 39
// Example 2:

// Input: grid = [[0]]
// Output: 1


// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 20
// grid[i][j] is either 0 or 1.


// 先翻转行，使得第一位都变1
// 再依次翻转列，使得每一列中1比0多


int matrixScore(int** grid, int gridSize, int* gridColSize){
    int m = gridSize, n = gridColSize[0];
    int ret = m * (1 << (n - 1));
    for (int j = 1; j < n; j ++) {
        int nOnes = 0;
        for (int i = 0; i < m; i ++) {
            if (grid[i][0] == 1) {
                nOnes += grid[i][j];
            } else {
                nOnes += (1 - grid[i][j]);
            }
        }
        int k = fmax(nOnes, m - nOnes);
        ret += k * (1 << (n - j - 1));
    }
    return ret;
}
