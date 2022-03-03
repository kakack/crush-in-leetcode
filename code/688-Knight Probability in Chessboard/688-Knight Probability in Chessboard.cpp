// On an n x n chessboard, a knight starts at the cell (row, column) and attempts to make exactly k moves. The rows and columns are 0-indexed, so the top-left cell is (0, 0), and the bottom-right cell is (n - 1, n - 1).

// A chess knight has eight possible moves it can make, as illustrated below. Each move is two cells in a cardinal direction, then one cell in an orthogonal direction.


// Each time the knight is to move, it chooses one of eight possible moves uniformly at random (even if the piece would go off the chessboard) and moves there.

// The knight continues moving until it has made exactly k moves or has moved off the chessboard.

// Return the probability that the knight remains on the board after it has stopped moving.

 

// Example 1:

// Input: n = 3, k = 2, row = 0, column = 0
// Output: 0.06250
// Explanation: There are two moves (to (1,2), (2,1)) that will keep the knight on the board.
// From each of those positions, there are also two moves that will keep the knight on the board.
// The total probability the knight stays on the board is 0.0625.
// Example 2:

// Input: n = 1, k = 0, row = 0, column = 0
// Output: 1.00000
 

// Constraints:

// 1 <= n <= 25
// 0 <= k <= 100
// 0 <= row, column <= n

/*
    动态规划
    dp[step][i][j] 表示从（i， j）出发，走了step步之后还留在棋盘上的概率
    (i, j)不在棋盘内则 dp[step][i][j] = 0，当(i, j)在棋盘内则dp[0][i][j] = 1
    状态转移：
    dp[step][i][j]=1/8 * ∑dp[step - 1][i+di][j+dj]，其中（di, dj）表示走法对坐标的偏移量，具体为：
    (−2,−1),(−2,1),(2,−1),(2,1),(−1,−2),(−1,2),(1,−2),(1,2) 共 88 种
*/

class Solution {
public:
    vector<vector<int>> dirs = 
    {
        {-2, -1}, 
        {-2, 1}, 
        {2, -1}, 
        {2, 1}, 
        {-1, -2}, 
        {-1, 2}, 
        {1, -2}, 
        {1, 2}
    };

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(k + 1, vector<vector<double>>(n, vector<double>(n)));
        for (int step = 0; step <= k; step ++) {
            for (int i = 0; i < n; i ++) {
                for (int j = 0; j < n; j ++) {
                    if (step == 0) {
                        dp[step][i][j] = 1;
                    } else {
                        for (auto & dir: dirs) {
                            int ni = i + dir[0];
                            int nj = j + dir[1];
                            if (ni >= 0 && ni < n && nj >= 0 && nj < n) {
                                dp[step][i][j] += dp[step - 1][ni][nj] / 8;
                            }
                        }
                    }
                }
            }
        }
        return dp[k][row][column];
    }
};