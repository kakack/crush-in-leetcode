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

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

const int dirs[4][2] = {
    {1, 0},
    {-1, 0},
    {0, 1},
    {0, -1}
};

int** updateMatrix(int** mat, int matSize, int* matColSize, int* returnSize, int** returnColumnSizes){
    int m = matSize;
    int n = matColSize[0];
    *returnSize = m;
    (*returnColumnSizes) = (int*)malloc(matSize * sizeof(int));
    memcpy(*returnColumnSizes, matColSize, matSize * sizeof(int));

    // int res[m][n];
    // memset(res, 0, sizeof(int) * m * n);
    int **res=(int**)malloc(sizeof(int*)*matSize);
    int seen[m][n];
    memset(seen, 0, sizeof(int) * m * n);
    int que[m * n][2];
    int head = 0;
    int tail = 0;
    for (int i = 0; i < m; i ++) {
        res[i]=malloc(sizeof(int)*n);
        for (int j = 0; j < n; j ++) {
            res[i][j] = 0;
            if (mat[i][j] == 0) {
                que[tail][0] = i;
                que[tail ++][1] = j;
                seen[i][j] = 1;
            }
        }
    }
    while (head < tail) {
        int i = que[head][0];
        int j = que[head ++][1];
        for (int k = 0; k < 4; k ++) {
            int ni = i + dirs[k][0];
            int nj = j + dirs[k][1];
            if (ni >= 0 && ni < m && nj >= 0 && nj < n && seen[ni][nj] == 0) {
                res[ni][nj] = res[i][j] + 1;
                que[tail][0] = ni;
                que[tail ++][1] = nj;
                seen[ni][nj] = 1;
            }
        }
    }
    return res;
}