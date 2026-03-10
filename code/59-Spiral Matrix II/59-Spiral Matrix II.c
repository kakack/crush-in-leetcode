/*
LeetCode 59 - Spiral Matrix II

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*
Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.



Example 1:


Input: n = 3
Output: [[1,2,3],[8,9,4],[7,6,5]]
Example 2:

Input: n = 1
Output: [[1]]


Constraints:

1 <= n <= 20
*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

const int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int** generateMatrix(int n, int* returnSize, int** returnColumnSizes){
    int **res = (int **)malloc(sizeof(int*) * n);
    *returnSize = n;
    *returnColumnSizes = (int*)malloc(sizeof(int) * n);
    for (int i = 0; i < n; i ++) {
        (*returnColumnSizes)[i] = n;
        res[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j ++) {
            res[i][j] = 0;
        }
    }
    int row = 0, col = 0, dirIndex = 0;
    for (int i = 1; i <= n * n; i ++) {
        res[row][col] = i;
        int nextRow = row + dirs[dirIndex][0], nextCol = col + dirs[dirIndex][1];
        if (nextRow < 0 || nextRow >= n || nextCol < 0 || nextCol >= n || res[nextRow][nextCol]) {
            dirIndex = (dirIndex + 1) % 4;
        }
        row += dirs[dirIndex][0];
        col += dirs[dirIndex][1];
    }
    return res;
}
