# -*- coding: utf-8 -*
"""
LeetCode 1137 - N-th Tribonacci Number

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
r"""
@author: Kai Chen
@file: 1137-N-th Tribonacci Number.py
@time: 2021/7/5 14:11
@desc:
The Tribonacci sequence Tn is defined as follows:

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.



Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4
Example 2:

Input: n = 25
Output: 1389537


Constraints:

0 <= n <= 37
The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.
"""


class Solution(object):
    def tribonacci(self, n):
        """
        :type n: int
        :rtype: int
        """
        tribo = [-1] * 38
        tribo[0] = 0
        tribo[1] = 1
        tribo[2] = 1
        if n < 3:
            return tribo[n]
        for i in range(3, n + 1):
            tribo[i] = tribo[i - 1] + tribo[i - 2] + tribo[i - 3]
        return tribo[n]
