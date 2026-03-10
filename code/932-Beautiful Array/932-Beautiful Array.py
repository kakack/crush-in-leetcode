"""
LeetCode 932 - Beautiful Array

解题步骤（自动整理）
1. 定义状态（dp[i] 或 dp[i][j]）来表示子问题的最优解/可行性
2. 写出状态转移方程，并处理边界初始化
3. 按依赖顺序递推（必要时滚动数组优化空间），得到最终答案
"""
# For some fixed n, an array nums is beautiful if it is a permutation of the integers 1, 2, ..., n, such that:
#
# For every i < j, there is no k with i < k < j such that nums[k] * 2 = nums[i] + nums[j].
#
# Given n, return any beautiful array nums.  (It is guaranteed that one exists.)
#
#
#
# Example 1:
#
# Input: n = 4
# Output: [2,1,4,3]
# Example 2:
#
# Input: n = 5
# Output: [3,1,2,5,4]
#
#
# Note:
#
# 1 <= n <= 1000

class Solution(object):
    def beautifulArray(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        memo = {1: [1]}

        def f(N):
            if N not in memo:
                odds = f((N + 1) / 2)
                evens = f(N / 2)
                memo[N] = [2 * x - 1 for x in odds] + [2 * x for x in evens]
            return memo[N]

        return f(n)
