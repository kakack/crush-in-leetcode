//
// Created by c00453140 on 2021/8/2.
/*You are given a network of n nodes, labeled from 1 to n. You are also given times, a list of travel times as directed edges times[i] = (ui, vi, wi), where ui is the source node, vi is the target node, and wi is the time it takes for a signal to travel from source to target.

We will send a signal from a given node k. Return the time it takes for all the n nodes to receive the signal. If it is impossible for all the n nodes to receive the signal, return -1.

 

Example 1:


Input: times = [[2,1,1],[2,3,1],[3,4,1]], n = 4, k = 2
Output: 2
Example 2:

Input: times = [[1,2,1]], n = 2, k = 1
Output: 1
Example 3:

Input: times = [[1,2,1]], n = 2, k = 2
Output: -1
 

Constraints:

1 <= k <= n <= 100
1 <= times.length <= 6000
times[i].length == 3
1 <= ui, vi <= n
        ui != vi
0 <= wi <= 100
All the pairs (ui, vi) are unique. (i.e., no multiple edges.)
*/
//



int networkDelayTime(int** times, int timesSize, int* timesColSize, int n, int k){
    int g[n][n];
    const int inf = 0x3f3f3f3f;
    memset(g, 0x3f, sizeof(g));
    for (int i = 0; i < timesSize; i ++) {
        int x = times[i][0] - 1, y = times[i][1] - 1;
        g[x][y] = times[i][2];
    }
    int dist[n];
    memset(dist, 0x3f, sizeof(dist));
    dist[k - 1] = 0;
    int used[n];
    memset(used, 0, sizeof(used));
    int ans = 0;
    for  (int i = 0; i < n; ++i) {
        int x = -1;
        for (int y = 0; y < n; ++y) {
            if (!used[y] && (x == -1 || dist[y] < dist[x])) {
                x = y;
            }
        }
        used[x] = true;
        ans = fmax(ans, dist[x]);
        for (int y = 0; y < n; ++y) {
            dist[y] = fmin(dist[y], dist[x] + g[x][y]);
        }
    }
    return ans == inf ? -1 : ans;
}