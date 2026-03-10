/*
LeetCode 1091 - Shortest Path in Binary Matrix

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

// A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

// All the visited cells of the path are 0.
// All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
// The length of a clear path is the number of visited cells of this path.



// Example 1:


// Input: grid = [[0,1],[1,0]]
// Output: 2
// Example 2:


// Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
// Output: 4
// Example 3:

// Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
// Output: -1


// Constraints:

// n == grid.length
// n == grid[i].length
// 1 <= n <= 100
// grid[i][j] is 0 or 1



const int directions[8][2] = {
        {-1, 0}, {-1, 1}, {0, 1}, {1, 1},
        {1, 0}, {1, -1}, {0, -1}, {-1, -1}
        };

int shortestPathBinaryMatrix(int** grid, int gridSize, int* gridColSize){
    if (grid[0][0] != 0) {
        return -1;
    }
    int n = gridSize;
    int res[n][n];
    memset(res, -1, sizeof(int) * n * n);
    int q[n * n][2];
    int head = 0, tail = 0;
    q[tail][0] = 0;
    q[tail ++][1] = 0;
    res[0][0] = 1;
    while (head < tail) {
        int x = q[head][0];
        int y = q[head ++][1];
        for (int i = 0; i < 8; i ++) {
            int next_x = x + directions[i][0];
            int next_y = y + directions[i][1];
            if (next_x >= 0 && next_x < n && next_y >= 0 && next_y < n && grid[next_x][next_y]==0 && res[next_x][next_y] == -1) {
                q[tail][0] = next_x;
                q[tail ++][1] = next_y;
                res[next_x][next_y] = res[x][y] + 1;
            }
        }
    }
    return res[n - 1][n - 1];
}
