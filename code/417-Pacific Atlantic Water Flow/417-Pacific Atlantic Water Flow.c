// There is an m x n rectangular island that borders both the Pacific Ocean and Atlantic Ocean. The Pacific Ocean touches the island's left and top edges, and the Atlantic Ocean touches the island's right and bottom edges.

// The island is partitioned into a grid of square cells. You are given an m x n integer matrix heights where heights[r][c] represents the height above sea level of the cell at coordinate (r, c).

// The island receives a lot of rain, and the rain water can flow to neighboring cells directly north, south, east, and west if the neighboring cell's height is less than or equal to the current cell's height. Water can flow from any cell adjacent to an ocean into the ocean.

// Return a 2D list of grid coordinates result where result[i] = [ri, ci] denotes that rain water can flow from cell (ri, ci) to both the Pacific and Atlantic oceans.

 

// Example 1:


// Input: heights = [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
// Output: [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
// Example 2:

// Input: heights = [[2,1],[1,2]]
// Output: [[0,0],[0,1],[1,0],[1,1]]
 

// Constraints:

// m == heights.length
// n == heights[r].length
// 1 <= m, n <= 200
// 0 <= heights[r][c] <= 10^5



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

static const int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void dfs(int row, int col, bool **ocean, const int ** heights, int m, int n) {
    if (ocean[row][col]) {
        return;
    }
    ocean[row][col] = true;
    for (int i = 0; i < 4; i ++) {
        int nr = row + dirs[i][0], nc = col + dirs[i][1];
        if (nr >= 0 && nr < m && nc >= 0 && nc < n && heights[nr][nc] >= heights[row][col]) {
            dfs(nr, nc, ocean, heights, m, n);
        }
    }
}


int** pacificAtlantic(int** heights, int heightsSize, int* heightsColSize, int* returnSize, int** returnColumnSizes){
    int m = heightsSize;
    int n = heightsColSize[0];
    bool ** pacific = (bool **)malloc(sizeof(bool *) * m);
    bool ** atlantic = (bool **)malloc(sizeof(bool *) * m);
    for (int i = 0; i < m; i++) {
            pacific[i] = (bool *)malloc(sizeof(bool) * n);
            atlantic[i] = (bool *)malloc(sizeof(bool) * n);
            memset(pacific[i], 0, sizeof(bool) * n);
            memset(atlantic[i], 0, sizeof(bool) * n);
        }
    for (int i = 0; i < m; i++) {
        dfs(i, 0, pacific, heights, m, n);
    }
    for (int j = 1; j < n; j++) {
        dfs(0, j, pacific, heights, m, n);
    }
    for (int i = 0; i < m; i++) {
        dfs(i, n - 1, atlantic, heights, m, n);
    }
    for (int j = 0; j < n - 1; j++) {
        dfs(m - 1, j, atlantic, heights, m, n);
    }
    int **res = (int**)malloc(sizeof(int *) * m * n);
    *returnColumnSizes = (int*)malloc(sizeof(int) * m * n);
    int pos = 0;
    for (int i = 0; i < m * n; i ++) {
        res[i] = (int *)malloc(sizeof(int) * 2);
        (*returnColumnSizes)[i] = 2;
    }
    for (int i = 0; i < m; i ++) {
        for (int j = 0; j < n; j ++) {
            if (pacific[i][j] && atlantic[i][j]) {
                res[pos][0] = i;
                res[pos][1] = j;
                pos ++;
            }
        }
        free(pacific[i]);
        free(atlantic[i]);
    }
    free(pacific);
    free(atlantic);
    *returnSize = pos;
    return res;
}