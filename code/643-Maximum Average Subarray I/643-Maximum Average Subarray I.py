# -*- coding: utf-8 -*
"""
LeetCode 643 - Maximum Average Subarray I

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
r"""
@author: Kai Chen
@file: 643-Maximum Average Subarray I.py
@time: 2021/2/4 9:18
@desc:
Given an array consisting of n integers, find the contiguous subarray of given length k that has the maximum average value. And you need to output the maximum average value.

Example 1:

Input: [1,12,-5,-6,50,3], k = 4
Output: 12.75
Explanation: Maximum average is (12-5-6+50)/4 = 51/4 = 12.75


Note:

1 <= k <= n <= 30,000.
Elements of the given array will be in the range [-10,000, 10,000].
"""

class Solution(object):
    def findMaxAverage(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: float
        """

        sums = sum(nums[:k])
        res = float(sums) / k
        for i in range(1, len(nums) - k + 1):
            sums = sums - nums[i - 1] + nums[i + k - 1]
            res = max(res, float(sums) / k)
        return res
