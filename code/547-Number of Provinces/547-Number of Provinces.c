/*
There are n cities. Some of them are connected, while some are not. If city a is connected directly with city b, and city b is connected directly with city c, then city a is connected indirectly with city c.

A province is a group of directly or indirectly connected cities and no other cities outside of the group.

You are given an n x n matrix isConnected where isConnected[i][j] = 1 if the ith city and the jth city are directly connected, and isConnected[i][j] = 0 otherwise.

Return the total number of provinces.



Example 1:


Input: isConnected = [[1,1,0],[1,1,0],[0,0,1]]
Output: 2
Example 2:


Input: isConnected = [[1,0,0],[0,1,0],[0,0,1]]
Output: 3


Constraints:

1 <= n <= 200
n == isConnected.length
n == isConnected[i].length
isConnected[i][j] is 1 or 0.
isConnected[i][i] == 1
isConnected[i][j] == isConnected[j][i]
*/


int find(int* f, int x) {
    if (f[x] == x) {
        return x;
    } else {
        return f[x] = find(f, f[x]);
    }
}

void unioned(int* f, int x, int y) {
    int fx = find(f, x);
    int fy = find(f, y);
    if (fx == fy) {
        return;
    }
    f[fx] = fy;
}

int findCircleNum(int** isConnected, int isConnectedSize, int* isConnectedColSize){
    int* f = (int*)malloc(sizeof(int) * isConnectedSize);
    for (int i = 0; i < isConnectedSize; i ++) {
        f[i] = i;
    }
    for (int i = 0; i < isConnectedSize; i ++) {
        for (int j = 0; j < isConnectedSize; j ++) {
            if (isConnected[i][j] == 1) {
                unioned(f, i, j);
            }
        }
    }
    int count = 0;
    for (int i = 0; i < isConnectedSize; i ++) {
        if (f[i] == i) {
            count ++;
        }
    }
    return count;
}