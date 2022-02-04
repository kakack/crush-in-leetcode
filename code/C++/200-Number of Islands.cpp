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


// dfs
class Solution {
private:
    int directions[4][2] = {
        {1, 0},
        {-1, 0},
        {0, -1},
        {0, 1},
    };
    void dfs(vector<vector<char>>& grid, int r, int c) {
        int m = grid.size();
        int n = grid[0].size();

        grid[r][c] = '0';
        for (int i = 0; i < 4; i ++) {
            int nr = r + directions[i][0];
            int nc = c + directions[i][1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1') {
                dfs(grid, nr, nc);
            }
        }
    }

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (!m) {
            return 0;
        }
        int n = grid[0].size();
        int num_islands = 0;
        for (int r = 0; r < m; r ++) {
            for (int c = 0; c < n; c ++){
                if (grid[r][c] == '1') {
                    num_islands ++;
                    dfs(grid, r, c);
                }
            }
        }
        return num_islands;
    }
};


// bfs


class Solution {
private:
    int directions[4][2] = {
        {1, 0},
        {-1, 0},
        {0, -1},
        {0, 1},
    };

public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        if (!m) {
            return 0;
        }
        int n = grid[0].size();

        int numIsland = 0;
        for (int r = 0; r < m; r ++) {
            for (int c = 0; c < n; c ++) {
                if (grid[r][c] == '1') {
                    numIsland ++;
                    grid[r][c] = '0';
                    queue<pair<int, int>> neighbors;
                    neighbors.push({r, c});
                    while (!neighbors.empty()) {
                        int row = neighbors.front().first;
                        int col = neighbors.front().second;
                        neighbors.pop();
                        for (int i = 0; i < 4; i++) {
                            int nr = row + directions[i][0];
                            int nc = col + directions[i][1];
                            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == '1') {
                                neighbors.push({nr, nc});
                                grid[nr][nc] = '0';
                            }
                        }
                    }
                }
            }
        }
        return numIsland;
    }
};