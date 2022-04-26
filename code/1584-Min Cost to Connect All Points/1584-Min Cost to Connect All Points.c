/*
You are given an array points representing integer coordinates of some points on a 2D-plane, where points[i] = [xi, yi].

The cost of connecting two points [xi, yi] and [xj, yj] is the manhattan distance between them: |xi - xj| + |yi - yj|, where |val| denotes the absolute value of val.

Return the minimum cost to make all points connected. All points are connected if there is exactly one simple path between any two points.



Example 1:



Input: points = [[0,0],[2,2],[3,10],[5,2],[7,0]]
Output: 20
Explanation:

We can connect the points as shown above to get the minimum cost of 20.
Notice that there is a unique path between every pair of points.
Example 2:

Input: points = [[3,12],[-2,5],[-4,1]]
Output: 18
Example 3:

Input: points = [[0,0],[1,1],[1,0],[-1,1]]
Output: 4
Example 4:

Input: points = [[-1000000,-1000000],[1000000,1000000]]
Output: 4000000
Example 5:

Input: points = [[0,0]]
Output: 0


Constraints:

1 <= points.length <= 1000
-106 <= xi, yi <= 106
All pairs (xi, yi) are distinct.
*/

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

struct Edge {
    int len;
    int x;
    int y;
}

int cmp(struct Edge *a, struct Edge *b) {
    return a->len - b->len;
}

int find(int *f, int x) {
    return f[x] == x ? x : (f[x] = find(f, f[x]));
}

bool unionSet(int *f, int *rank, int x, int y) {
    int fx = find(f, x), fy = find(f, y);
    if (fx == fy) {
        return false;
    }
    if (rank[fx] < rank[fy]) {
        swap(&fx, &fy);
    }
    rank[fx] += rank[fy];
    f[fy] = fx;
    return true;
}

int minCostConnectPoints(int** points, int pointsSize, int* pointsColSize){
    int n = pointsSize;
    struct Edge edges[(n + 1) * n / 2];
    int edgesSize = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges[edgesSize].x = i;
            edges[edgesSize].y = j;
            edges[edgesSize++].len = fabs(points[i][0] - points[j][0]) + fabs(points[i][1] - points[j][1]);
        }
    }
    qsort(edges, edgesSize, sizeof(struct Edge), cmp);
    int f[n], rank[n];
    for (int i = 0; i < n; i++) {
        f[i] = i;
        rank[i] = 1;
    }
    int ret = 0, num = 1;
    for (int i = 0; i < edgesSize; i ++) {
        if (unionSet(f, rank, edges[i].x, edges[i].y)) {
            ret += edges[i].len;
            num ++;
            if (num == n) {
                break;
            }
        }
    }
    return ret;
}