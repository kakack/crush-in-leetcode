/*
On an N x N grid, each square grid[i][j] represents the elevation at that point (i,j).

Now rain starts to fall. At time t, the depth of the water everywhere is t. You can swim from a square to another 4-directionally adjacent square if and only if the elevation of both squares individually are at most t. You can swim infinite distance in zero time. Of course, you must stay within the boundaries of the grid during your swim.

You start at the top left square (0, 0). What is the least time until you can reach the bottom right square (N-1, N-1)?

Example 1:

Input: [[0,2],[1,3]]
Output: 3
Explanation:
At time 0, you are in grid location (0, 0).
You cannot go anywhere else because 4-directionally adjacent neighbors have a higher elevation than t = 0.

You cannot reach point (1, 1) until time 3.
When the depth of water is 3, we can swim anywhere inside the grid.
Example 2:

Input: [[0,1,2,3,4],[24,23,22,21,5],[12,13,14,15,16],[11,17,18,19,20],[10,9,8,7,6]]
Output: 16
Explanation:
 0  1  2  3  4
24 23 22 21  5
12 13 14 15 16
11 17 18 19 20
10  9  8  7  6

The final route is marked in bold.
We need to wait until time 16 so that (0, 0) and (4, 4) are connected.
Note:

2 <= N <= 50.
grid[i][j] is a permutation of [0, ..., N*N - 1].
*/

typedef struct {
    int *f;
    int *size;
    int n;
    int setCount;
} DisjointSetUnion;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}


DisjointSetUnion *initUnion(int n) {
    int i;
    DisjointSetUnion *obj = malloc(sizeof(DisjointSetUnion));
    obj->f    = (int*)malloc(sizeof(int) * n);
    obj->size = (int*)malloc(sizeof(int) * n);
    obj->n    = n;
    obj->setCount = n;
    for (i = 0; i < n; i++) {
        obj->f[i]    = i;
        obj->size[i] = 1;
    }
    return obj;
}

/* 并查集查找 */
int find(DisjointSetUnion *obj, int x) {
    return (obj->f[x] == x) ? x : (obj->f[x] = find(obj, obj->f[x]));
}

/* 并查集连通 */
bool unionSet(DisjointSetUnion *obj, int x, int y) {
    int rootx = find(obj, x);
    int rooty = find(obj, y);
    if (rootx == rooty) {
        return false;
    }
    if (obj->size[rootx] < obj->size[rooty]) {
        swap(&rootx, &rooty);
    }
    obj->size[rootx] += obj->size[rooty];
    obj->f[rooty] = rootx;
    obj->setCount--;
    return true;
}

int cmp(const void *a, const void *b) {
    return ((int**)a)[0][2] - ((int**)b)[0][2];
}

int swimInWater(int** grid, int gridSize, int* gridColSize){
    int m = gridSize;
    int n = gridColSize[0];
    int i, j, idx;
    int len = 0;
    int **cost = (int**)malloc(sizeof(int*) * 2 * m * n);
    DisjointSetUnion *dsu = initUnion(m * n);
    
    /* 建立元素之间的连通关系, 相邻节点的最大值 */
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            idx = i * n + j;
            if (i + 1 < m) {
                cost[len]      = (int*)malloc(sizeof(int) * 3);
                cost[len][0]   = idx;
                cost[len][1]   = idx + n;
                cost[len++][2] = fmax(grid[i][j], grid[i + 1][j]);
            }
            if (j + 1 < n) {
                cost[len]      = (int*)malloc(sizeof(int) * 3);
                cost[len][0]   = idx;
                cost[len][1]   = idx + 1;
                cost[len++][2] = fmax(grid[i][j], grid[i][j + 1]);
            }
        }
    }
    
    /* 按连接关系从小到大排序, 再进行连通 */
    qsort(cost, len, sizeof(cost[0]), cmp);
    for (i = 0; i < len; i++) {
        unionSet(dsu, cost[i][0], cost[i][1]);
        if (find(dsu, 0) == find(dsu, m * n - 1)) {
            return cost[i][2];
        }
    }
    return 0;
}