# -*- coding: utf-8 -*
"""
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
