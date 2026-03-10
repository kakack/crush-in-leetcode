"""
LeetCode 70 - Climbing Stairs

解题步骤（自动整理）
1. 定义状态（dp[i] 或 dp[i][j]）来表示子问题的最优解/可行性
2. 写出状态转移方程，并处理边界初始化
3. 按依赖顺序递推（必要时滚动数组优化空间），得到最终答案
"""
# You are climbing a stair case. It takes n steps to reach to the top.
#
# Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
#
# Note: Given n will be a positive integer.
#
# Example 1:
#
# Input: 2
# Output: 2
# Explanation: There are two ways to climb to the top.
# 1. 1 step + 1 step
# 2. 2 steps
# Example 2:
#
# Input: 3
# Output: 3
# Explanation: There are three ways to climb to the top.
# 1. 1 step + 1 step + 1 step
# 2. 1 step + 2 steps
# 3. 2 steps + 1 step

class Solution(object):
    def climbStairs(self, n):
        """
        :type n: int
        :rtype: int
        """
        memo = [0] * (n + 1)
        memo[0] = 1
        memo[1] = 1
        # memo[2] = 2
        def climb(m):
            if m == 0 or memo[m] != 0:
                return memo[m]
            memo[m] = climb(m - 1) + climb(m - 2)
            return memo[m]
        return climb(n)

        # pre, cur = 0, 1
        # for i in range(1, n+1):
        #     tmp = cur
        #     cur += pre
        #     pre = tmp
        # return cur
