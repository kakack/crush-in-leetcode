# Given an n x n binary matrix grid, return the length of the shortest clear path in the matrix. If there is no clear path, return -1.

# A clear path in a binary matrix is a path from the top-left cell (i.e., (0, 0)) to the bottom-right cell (i.e., (n - 1, n - 1)) such that:

# All the visited cells of the path are 0.
# All the adjacent cells of the path are 8-directionally connected (i.e., they are different and they share an edge or a corner).
# The length of a clear path is the number of visited cells of this path.

 

# Example 1:


# Input: grid = [[0,1],[1,0]]
# Output: 2
# Example 2:


# Input: grid = [[0,0,0],[1,1,0],[1,1,0]]
# Output: 4
# Example 3:

# Input: grid = [[1,0,0],[1,1,0],[1,1,0]]
# Output: -1
 

# Constraints:

# n == grid.length
# n == grid[i].length
# 1 <= n <= 100
# grid[i][j] is 0 or 1

class Solution:
    def shortestPathBinaryMatrix(self, grid: List[List[int]]) -> int:
        dirs = [[-1, 0], [-1, 1], [0, 1], [1, 1], [1, 0], [1, -1], [0, -1], [-1, -1]]
        if grid[0][0] != 0:
            return -1
        n = len(grid)
        res = [[0] * n for _ in range(n)]
        q = list()
        q.append((0, 0))
        res[0][0] = 1
        while len(q) > 0:
            x, y = q[0]
            q.remove((x, y))
            for dir in dirs:
                next_x, next_y = x + dir[0], y + dir[1]
                if 0 <= next_x < n and 0 <= next_y < n and grid[next_x][next_y] == 0 and res[next_x][next_y] == 0:
                    res[next_x][next_y] = res[x][y] + 1
                    q.append((next_x, next_y))
        return -1 if res[n - 1][n - 1] == 0 else res[n - 1][n - 1]