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


// dfs
class Solution {
public:
    unordered_map<int, vector<int>> mp;
    bool dfs(vector<int> &visited, int id, int color) {
        if (visited[id] != 0) {
            return visited[id] == color;
        }
        visited[id] = color;
        for (auto c : mp[id]) {
            if (!dfs(visited, c, -color)) {
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for (int i = 0; i < dislikes.size(); i ++) {
            mp[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1);
            mp[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
        }
        vector<int> visited(n, 0);
        for (int i  = 0; i < n; i ++) {
            if (visited[i] == 0 && !dfs(visited, i, 1)) {
                return false;
            }
        }
        return true;
    }
};


// bfs

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int> > &dislikes) {
        unordered_map<int, vector<int>> mp;
        for (int i = 0; i < dislikes.size(); i ++) {
            mp[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1);
            mp[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
        }
        queue<int> qu;
        vector<int> visited(n, 0);
        for (int i = 0; i < n; i ++) {
            if (visited[i] != 0) {
                continue;
            }
            qu.push(i);
            visited[i] = 1;
            while (!qu.empty()) {
                int m = qu.size();
                for (int j = 0; j < m; j ++) {
                    auto id = qu.front();
                    qu.pop();
                    for (auto c : mp[id]) {
                        if (visited[c] == visited[id]) {
                            return false;
                        }
                        if (visited[c] == 0) {
                            visited[c] = -visited[id];
                            qu.push(c);
                        }
                    }
                }
            }
        }
        return true;
    }
};

// 并查集

class UnionFound {
public:
    vector<int> F;
    
    UnionFound(int n) {
        F = vector<int>(n, 0);
        for (int i = 0; i < n; i ++) {
            F[i] = i;
        }
    }
    
    int Find(int x) {
        if (x == F[x]) {
            return x;
        }
        return F[x] = Find(F[x]);
    }

    void Union(int x, int y) {
        x = Find(x);
        y = Find(y);
        if (x != y) {
            F[x] = y;
        }
    }
};

class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int> > &dislikes) {
        unordered_map<int, vector<int> > mp;

        for (int i = 0; i < dislikes.size(); i++) {
            mp[dislikes[i][0] - 1].push_back(dislikes[i][1] - 1);
            mp[dislikes[i][1] - 1].push_back(dislikes[i][0] - 1);
        }

        UnionFound uf(n);
        for (int i = 0; i < n; i ++) {
            for (auto c : mp[i]) {
                if (uf.Find(i) == uf.Find(c)) {
                    return false;
                }
                uf.Union(mp[i][0], c);
            }
        }
        return true;
    }
};