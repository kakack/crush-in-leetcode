# -*- coding: utf-8 -*
"""
LeetCode 201 - Bitwise AND of Numbers Range

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
r"""
@author: Kai Chen
@file: 201-Bitwise AND of Numbers Range.py
@time: 2020/8/10 16:17
@desc:
Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.

Example 1:

Input: [5,7]
Output: 4
Example 2:

Input: [0,1]
Output: 0
"""


class Solution(object):
    # def rangeBitwiseAnd(self, m, n):
    #     """
    #     :type m: int
    #     :type n: int
    #     :rtype: int
    #     """
    #     shift = 0
    #     while m < n:
    #         m = m >> 1
    #         n = n >> 1
    #         shift += 1
    #     return m << shift

    def rangeBitwiseAnd(self, m, n):
        """
        :type m: int
        :type n: int
        :rtype: int
        """
        while m < n:
            n = n & (n - 1)
        return n
