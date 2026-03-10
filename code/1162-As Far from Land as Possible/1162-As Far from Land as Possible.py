"""
LeetCode 1162 - As Far from Land as Possible

解题步骤（自动整理）
1. 将起点/初始层入队，并用 visited 或原地标记避免重复访问
2. 按层或按队列弹出元素扩展相邻节点，满足条件时更新答案
3. 队列处理完毕后返回结果（或在首次到达目标时提前返回）
"""
# Given an N x N grid containing only values 0 and 1, where 0 represents water and 1 represents land, find a water cell such that its distance to the nearest land cell is maximized and return the distance.
#
# The distance used in this problem is the Manhattan distance: the distance between two cells (x0, y0) and (x1, y1) is |x0 - x1| + |y0 - y1|.
#
# If no land or water exists in the grid, return -1.
#
#
# Example 1:
# Input: [[1,0,1],[0,0,0],[1,0,1]]
# Output: 2
# Explanation:
# The cell (1, 1) is as far as possible from all the land with distance 2.
#
# Example 2:
# Input: [[1,0,0],[0,0,0],[0,0,0]]
# Output: 4
# Explanation:
# The cell (2, 2) is as far as possible from all the land with distance 4.
#
#
# Note:
# - 1 <= grid.length == grid[0].length <= 100
# - grid[i][j] is 0 or 1


class Solution(object):
    def maxDistance(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        from collections import deque
        tmp_queue = deque()
        n = len(grid)

        for row in range(n):
            for col in range(n):
                if grid[row][col] == 1:
                    tmp_queue.append([row, col])
        hasOcean = False
        tmpPoint = None

        while tmp_queue:
            tmpPoint = tmp_queue.popleft()
            x, y = tmpPoint
            for x_bias, y_bias in [[0, 1], [0, -1], [1, 0], [-1, 0]]:
                new_x = x + x_bias
                new_y = y + y_bias
                if new_x < 0 or new_y <0 or new_x >= n or new_y >= n or grid[new_x][new_y] != 0:
                    continue
                grid[new_x][new_y] = grid[x][y] + 1
                hasOcean = True
                tmp_queue.append([new_x, new_y])
        if tmpPoint == [] or not hasOcean:
            return -1
        else:
            return grid[tmpPoint[0]][tmpPoint[1]] - 1
