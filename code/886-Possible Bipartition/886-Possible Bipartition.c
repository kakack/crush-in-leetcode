// We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

// Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

 

// Example 1:

// Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
// Output: true
// Explanation: group1 [1,4] and group2 [2,3].
// Example 2:

// Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
// Output: false
// Example 3:

// Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
// Output: false
 

// Constraints:

// 1 <= n <= 2000
// 0 <= dislikes.length <= 10^4
// dislikes[i].length == 2
// 1 <= dislikes[i][j] <= n
// ai < bi
// All the pairs of dislikes are unique.

#define MAX_BUF_LEN 5000

int find(int *f, int a) {
    while (f[a] != a) {
        f[a] = f[f[a]];
        a = f[a];
    }
    return a;
}

void unioned(int *f, int a, int b) {
    if (find(f, a) == find(f, b)) {
        return;
    }
    f[find(f, a)] = find(f, b);
}

bool possibleBipartition(int N, int** dislikes, int dislikesSize, int* dislikesColSize) {
    int* f = malloc(sizeof(int) * (2 * N + 1));
    for (int i = 0; i < 2 * N + 1; i ++) {
        f[i] = i;
    }

    int a, b ,da, db;
    for (int i = 0 ; i < dislikesSize; i ++) {
        a = dislikes[i][0];
        b = dislikes[i][1];
        da = a + N;
        db = b + N;
        if (find(f, a) == find(f, b)) {
            return false;
        }
        unioned(f, a, db);
        unioned(f, b, da);
    }
    return true;
}