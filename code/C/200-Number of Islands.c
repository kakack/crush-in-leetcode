// Given an m x n 2D binary grid grid which represents a map of '1's (land) and '0's (water), return the number of islands.

// An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.

 

// Example 1:

// Input: grid = [
//   ["1","1","1","1","0"],
//   ["1","1","0","1","0"],
//   ["1","1","0","0","0"],
//   ["0","0","0","0","0"]
// ]
// Output: 1
// Example 2:

// Input: grid = [
//   ["1","1","0","0","0"],
//   ["1","1","0","0","0"],
//   ["0","0","1","0","0"],
//   ["0","0","0","1","1"]
// ]
// Output: 3
 

// Constraints:

// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 300
// grid[i][j] is '0' or '1'.

int directions[4][2] = {
        {1, 0},
        {-1, 0},
        {0, -1},
        {0, 1},
    };

void dfs(char** grid, int gridSize, int* gridColSize, int r, int c) {
    int m = gridSize;
    int n = gridColSize[0];
    grid[r][c] = '0';
    for (int i = 0; i < 4; i ++) {
        int nr = r + directions[i][0];
        int nc = c + directions[i][1];
        if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1') {
            dfs(grid, gridSize, gridColSize, nr, nc);
        }
    }
}

int numIslands(char** grid, int gridSize, int* gridColSize){
    int m = gridSize;
    if (m == 0) {
        return 0;
    }
    int n = gridColSize[0];
    int num_islands = 0;
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            if (grid[i][j] == '1') {
                num_islands ++;
                dfs(grid, gridSize, gridColSize, i, j);
            }
        }
    }
    return num_islands;
}