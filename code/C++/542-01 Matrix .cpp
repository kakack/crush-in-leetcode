//
// Created by c00453140 on 2021/7/29.
//

/*
 * Given an m x n binary matrix mat, return the distance of the nearest 0 for each cell.

The distance between two adjacent cells is 1.



Example 1:


Input: mat = [[0,0,0],[0,1,0],[0,0,0]]
Output: [[0,0,0],[0,1,0],[0,0,0]]
Example 2:


Input: mat = [[0,0,0],[0,1,0],[1,1,1]]
Output: [[0,0,0],[0,1,0],[1,2,1]]


Constraints:

m == mat.length
n == mat[i].length
1 <= m, n <= 104
1 <= m * n <= 104
mat[i][j] is either 0 or 1.
There is at least one 0 in mat.
 *
 * */


// bfs

class Solution {
private:
    const int dirs[4][2] = {
        {1, 0},
        {-1, 0},
        {0, 1},
        {0, -1}
    };
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        vector<vector<int>> seen(m, vector<int>(n));
        queue<pair<int, int>> que;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (mat[i][j] == 0) {
                    que.emplace(i, j);
                    seen[i][j] = 1;
                }
            }
        }

        while (!que.empty()) {
            auto [i, j] = que.front();
            que.pop();
            for (int k = 0; k < 4; k ++) {
                int ni = i + dirs[k][0];
                int nj = j + dirs[k][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !seen[ni][nj]) {
                    res[ni][nj] = res[i][j] + 1;
                    que.emplace(ni, nj);
                    seen[ni][nj] = 1;
                }
            }
        }
        return res;
    }
};

// dynamic 

#include "vector"


using namespace std;

class Solution {
public:
    vector <vector<int>> updateMatrix(vector <vector<int>> &matrix) {
        int rows = matrix.size();
        if (rows == 0)
            return matrix;
        int cols = matrix[0].size();
        vector <vector<int>> dist(rows, vector<int>(cols, INT_MAX - 100000));

        //First pass: check for left and top
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (matrix[i][j] == 0)
                    dist[i][j] = 0;
                else {
                    if (i > 0)
                        dist[i][j] = min(dist[i][j], dist[i - 1][j] + 1);
                    if (j > 0)
                        dist[i][j] = min(dist[i][j], dist[i][j - 1] + 1);
                }
            }
        }

        //Second pass: check for bottom and right
        for (int i = rows - 1; i >= 0; i--) {
            for (int j = cols - 1; j >= 0; j--) {
                if (i < rows - 1)
                    dist[i][j] = min(dist[i][j], dist[i + 1][j] + 1);
                if (j < cols - 1)
                    dist[i][j] = min(dist[i][j], dist[i][j + 1] + 1);
            }
        }

        return dist;
    }
};