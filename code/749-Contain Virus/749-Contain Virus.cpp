// A virus is spreading rapidly, and your task is to quarantine the infected area by installing walls.

// The world is modeled as an m x n binary grid isInfected, where isInfected[i][j] == 0 represents uninfected cells, and isInfected[i][j] == 1 represents cells contaminated with the virus. A wall (and only one wall) can be installed between any two 4-directionally adjacent cells, on the shared boundary.

// Every night, the virus spreads to all neighboring cells in all four directions unless blocked by a wall. Resources are limited. Each day, you can install walls around only one region (i.e., the affected area (continuous block of infected cells) that threatens the most uninfected cells the following night). There will never be a tie.

// Return the number of walls used to quarantine all the infected regions. If the world will become fully infected, return the number of walls used.

 

// Example 1:


// Input: isInfected = [[0,1,0,0,0,0,0,1],[0,1,0,0,0,0,0,1],[0,0,0,0,0,0,0,1],[0,0,0,0,0,0,0,0]]
// Output: 10
// Explanation: There are 2 contaminated regions.
// On the first day, add 5 walls to quarantine the viral region on the left. The board after the virus spreads is:

// On the second day, add 5 walls to quarantine the viral region on the right. The virus is fully contained.

// Example 2:


// Input: isInfected = [[1,1,1],[1,0,1],[1,1,1]]
// Output: 4
// Explanation: Even though there is only one cell saved, there are 4 walls built.
// Notice that walls are only built on the shared boundary of two different cells.
// Example 3:

// Input: isInfected = [[1,1,1,0,0,0,0,0,0],[1,0,1,0,1,1,1,1,1],[1,1,1,0,0,0,0,0,0]]
// Output: 13
// Explanation: The region on the left only builds two new walls.
 

// Constraints:

// m == isInfected.length
// n == isInfected[i].length
// 1 <= m, n <= 50
// isInfected[i][j] is either 0 or 1.
// There is always a contiguous viral region throughout the described process that will infect strictly more uncontaminated squares in the next round.

class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    int containVirus(vector<vector<int>>& isInfected) {
        auto pair_hash = [fn = hash<int>()](const pair<int, int>& o) {
            return (fn(o.first) << 16) ^ fn(o.second);
        };

        int m = isInfected.size(), n = isInfected[0].size();
        int ans = 0;
        while (true) {
            vector<unordered_set<pair<int, int>, decltype(pair_hash)>> neighbors;
            vector<int> firewalls;
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (isInfected[i][j] == 1) {
                        queue<pair<int, int>> q;
                        unordered_set<pair<int, int>, decltype(pair_hash)> neighbor(0, pair_hash);
                        int firewall = 0, idx = neighbors.size() + 1;
                        q.emplace(i, j);
                        isInfected[i][j] = -idx;

                        while (!q.empty()) {
                            auto [x, y] = q.front();
                            q.pop();
                            for (int d = 0; d < 4; ++d) {
                                int nx = x + dirs[d][0];
                                int ny = y + dirs[d][1];
                                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                                    if (isInfected[nx][ny] == 1) {
                                        q.emplace(nx, ny);
                                        isInfected[nx][ny] = -idx;
                                    }
                                    else if (isInfected[nx][ny] == 0) {
                                        ++firewall;
                                        neighbor.emplace(nx, ny);
                                    }
                                }
                            }
                        }
                        neighbors.push_back(move(neighbor));
                        firewalls.push_back(firewall);
                    }
                }
            }
            
            if (neighbors.empty()) {
                break;
            }

            int idx = max_element(neighbors.begin(), neighbors.end(), [](const auto& v0, const auto& v1) { return v0.size() < v1.size(); }) - neighbors.begin();
            ans += firewalls[idx];
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (isInfected[i][j] < 0) {
                        if (isInfected[i][j] != -idx - 1) {
                            isInfected[i][j] = 1;
                        }
                        else {
                            isInfected[i][j] = 2;
                        }
                    }
                }
            }
            for (int i = 0; i < neighbors.size(); ++i) {
                if (i != idx) {
                    for (const auto& [x, y]: neighbors[i]) {
                        isInfected[x][y] = 1;
                    }
                }
            }
            if (neighbors.size() == 1) {
                break;
            }
        }
        return ans;
    }
};
