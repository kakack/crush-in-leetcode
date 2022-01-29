// You are given an m x n grid rooms initialized with these three possible values.

// -1 A wall or an obstacle.
// 0 A gate.
// INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

//  

// Example 1:


// Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
// Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
// Example 2:

// Input: rooms = [[-1]]
// Output: [[-1]]
//  

// Constraints:

// m == rooms.length
// n == rooms[i].length
// 1 <= m, n <= 250
// rooms[i][j] is -1, 0, or 2^31 - 1.


class Solution {
private:
    const int WALL = -1;
    const int DOOR = 0;
    const int INF = 2147483647;
    const int directions[4][2] = {
        {1, 0},
        {-1, 0},
        {0, -1},
        {0, 1},
    };
    
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m = rooms.size(), n = rooms[0].size();
        queue<pair<int, int>> que;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (rooms[i][j] == DOOR) {
                    que.emplace(make_pair(i, j));
                }
            }
        }
        while (!que.empty()) {
            auto top = que.front();
            que.pop();
            int row = top.first;
            int col = top.second;
            for (int i = 0; i < 4; i ++) {
                int newRow = row + directions[i][0];
                int newCol = col + directions[i][1];
                if (newRow < 0 || newRow >= m || newCol < 0 || newCol >= n || rooms[newRow][newCol] != INF) {
                    continue;
                }
                rooms[newRow][newCol] = rooms[row][col] + 1;
                que.emplace(make_pair(newRow, newCol));
            }
        }
    }
};