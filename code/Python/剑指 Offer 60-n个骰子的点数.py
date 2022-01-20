# -*- coding: utf-8 -*
"""
@author: Kaka Chen
@license: (C) Copyright Personal Uncommercial Limited.
@contact: kakachen1990@gmail.com
@file: 剑指 Offer 60-n个骰子的点数.py
@time: 2020/7/26 1:04 下午
@desc:
把n个骰子扔在地上，所有骰子朝上一面的点数之和为s。输入n，打印出s的所有可能的值出现的概率。

 

你需要用一个浮点数数组返回答案，其中第 i 个元素代表这 n 个骰子所能掷出的点数集合中第 i 小的那个的概率。

 

示例 1:

输入: 1
输出: [0.16667,0.16667,0.16667,0.16667,0.16667,0.16667]
示例 2:

输入: 2
输出: [0.02778,0.05556,0.08333,0.11111,0.13889,0.16667,0.13889,0.11111,0.08333,0.05556,0.02778]

dp[i][j]表示在i个骰子下，能扔出j的值的个数
"""


class Solution(object):
    def twoSum(self, n):
        """
        :type n: int
        :rtype: List[float]
        """
        dp = [[0 for _ in range(6 * n + 1)] for _ in range(n + 1)]
        for i in range(1, 7):
            dp[1][i] = 1
        for i in range(2, n + 1):
            for j in range(i, i * 6 + 1):
                for k in range(1, 7):
                    if j >= k + 1:
                        dp[i][j] += dp[i - 1][j - k]
        res = []
        for i in range(n, n * 6 + 1):
            res.append(dp[n][i] * 1.0 / 6 ** n)
        return res
