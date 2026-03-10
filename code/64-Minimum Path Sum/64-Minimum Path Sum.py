# -*- coding: utf-8 -*
"""
LeetCode 64 - Minimum Path Sum

解题步骤（自动整理）
1. 定义状态（dp[i] 或 dp[i][j]）来表示子问题的最优解/可行性
2. 写出状态转移方程，并处理边界初始化
3. 按依赖顺序递推（必要时滚动数组优化空间），得到最终答案
"""
r"""
@author: Kai Chen
@file: 64-Minimum Path Sum.py
@time: 2020/7/23 9:44
@desc:
Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

Example:

Input:
[
  [1,3,1],
  [1,5,1],
  [4,2,1]
]
Output: 7
Explanation: Because the path 1→3→1→1→1 minimizes the sum.
"""


class Solution(object):
    def minPathSum(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        if not grid or not grid[0]:
            return 0
        rows, cols = len(grid), len(grid[0])
        dp = [[-1] * cols for _ in range(rows)]
        dp[0][0] = grid[0][0]
        for i in range(1, rows):
            dp[i][0] = dp[i - 1][0] + grid[i][0]
        for j in range(1, cols):
            dp[0][j] = dp[0][j - 1] + grid[0][j]
        for i in range(1, rows):
            for j in range(1, cols):
                dp[i][j] = min(dp[i - 1][j], dp[i][j - 1]) + grid[i][j]
        return dp[rows - 1][cols - 1]


if __name__ == '__main__':
    s = Solution()
    ipt = [
        [1, 3, 1],
        [1, 5, 1],
        [4, 2, 1]
    ]
    print(s.minPathSum(ipt))
