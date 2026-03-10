# -*- coding: utf-8 -*
"""
LeetCode 1342 - Number of Steps to Reduce a Number to Zero

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
r"""
@author: Kai Chen
@file: 1342-Number of Steps to Reduce a Number to Zero.py
@time: 2020/10/13 9:19
@desc:
"""
class Solution(object):
    def numberOfSteps (self, num):
        """
        :type num: int
        :rtype: int
        """
        # count = 0
        # while num != 0:
        #     if num % 2 == 1:
        #         count += 1
        #         num -= 1
        #     else:
        #         num = num // 2
        #         count += 1
        # return count

        return max(0, bin(num).count('1') + num.bit_length() - 1)
