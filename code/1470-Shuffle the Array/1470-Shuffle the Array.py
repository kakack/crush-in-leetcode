# -*- coding: utf-8 -*
"""
LeetCode 1470 - Shuffle the Array

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
r"""
@author: Kai Chen
@file: 1470-Shuffle the Array.py
@time: 2020/9/19 10:28
@desc:
"""


class Solution(object):
    def shuffle(self, nums, n):
        """
        :type nums: List[int]
        :type n: int
        :rtype: List[int]
        """
        res = []
        n = len(nums)
        for i in range(n/2):
            res.append(nums[i])
            res.append(nums[i + n/2])
        return res
