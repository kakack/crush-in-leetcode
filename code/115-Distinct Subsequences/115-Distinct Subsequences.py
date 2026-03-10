# -*- coding: utf-8 -*
"""
LeetCode 115 - Distinct Subsequences

解题步骤（自动整理）
1. 定义状态（dp[i] 或 dp[i][j]）来表示子问题的最优解/可行性
2. 写出状态转移方程，并处理边界初始化
3. 按依赖顺序递推（必要时滚动数组优化空间），得到最终答案
"""
r"""
@author: Kai Chen
@file: 115-Distinct Subsequences.py
@time: 2021/3/17 9:06
@desc:
Given two strings s and t, return the number of distinct subsequences of s which equals t.

A string's subsequence is a new string formed from the original string by deleting some (can be none) of the characters without disturbing the remaining characters' relative positions. (i.e., "ACE" is a subsequence of "ABCDE" while "AEC" is not).

It is guaranteed the answer fits on a 32-bit signed integer.



Example 1:

Input: s = "rabbbit", t = "rabbit"
Output: 3
Explanation:
As shown below, there are 3 ways you can generate "rabbit" from S.
rabbbit
rabbbit
rabbbit
Example 2:

Input: s = "babgbag", t = "bag"
Output: 5
Explanation:
As shown below, there are 5 ways you can generate "bag" from S.
babgbag
babgbag
babgbag
babgbag
babgbag


Constraints:

0 <= s.length, t.length <= 1000
s and t consist of English letters.
"""


class Solution:
    def numDistinct(self, s, t):
        m, n = len(s), len(t)
        if m < n:
            return 0

        dp = [[0] * (n + 1) for _ in range(m + 1)]
        for i in range(m + 1):
            dp[i][n] = 1

        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if s[i] == t[j]:
                    dp[i][j] = dp[i + 1][j + 1] + dp[i + 1][j]
                else:
                    dp[i][j] = dp[i + 1][j]

        return dp[0][0]

