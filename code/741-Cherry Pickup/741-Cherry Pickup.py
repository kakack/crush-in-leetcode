# You are given an n x n grid representing a field of cherries, each cell is one of three possible integers.

# 0 means the cell is empty, so you can pass through,
# 1 means the cell contains a cherry that you can pick up and pass through, or
# -1 means the cell contains a thorn that blocks your way.
# Return the maximum number of cherries you can collect by following the rules below:

# Starting at the position (0, 0) and reaching (n - 1, n - 1) by moving right or down through valid path cells (cells with value 0 or 1).
# After reaching (n - 1, n - 1), returning to (0, 0) by moving left or up through valid path cells.
# When passing through a path cell containing a cherry, you pick it up, and the cell becomes an empty cell 0.
# If there is no valid path between (0, 0) and (n - 1, n - 1), then no cherries can be collected.
 

# Example 1:


# Input: grid = [[0,1,-1],[1,0,-1],[1,1,1]]
# Output: 5
# Explanation: The player started at (0, 0) and went down, down, right right to reach (2, 2).
# 4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
# Then, the player went left, up, up, left to return home, picking up one more cherry.
# The total number of cherries picked up is 5, and this is the maximum possible.
# Example 2:

# Input: grid = [[1,1,-1],[1,-1,1],[-1,1,1]]
# Output: 0
 

# Constraints:

# n == grid.length
# n == grid[i].length
# 1 <= n <= 50
# grid[i][j] is -1, 0, or 1.
# grid[0][0] != -1
# grid[n - 1][n - 1] != -1

class Solution:
    def cherryPickup(self, grid: List[List[int]]) -> int:
        n = len(grid)
        f = [[-inf] * n for _ in range(n)]
        f[0][0] = grid[0][0]
        for k in range(1, n * 2 - 1):
            for x1 in range(min(k, n - 1), max(k - n, -1), -1):
                for x2 in range(min(k, n - 1), x1 - 1, -1):
                    y1, y2 = k - x1, k - x2
                    if grid[x1][y1] == -1 or grid[x2][y2] == -1:
                        f[x1][x2] = -inf
                        continue
                    res = f[x1][x2]  # 都往右
                    if x1:
                        res = max(res, f[x1 - 1][x2])  # 往下，往右
                    if x2:
                        res = max(res, f[x1][x2 - 1])  # 往右，往下
                    if x1 and x2:
                        res = max(res, f[x1 - 1][x2 - 1])  # 都往下
                    res += grid[x1][y1]
                    if x2 != x1:  # 避免重复摘同一个樱桃
                        res += grid[x2][y2]
                    f[x1][x2] = res
        return max(f[-1][-1], 0)
