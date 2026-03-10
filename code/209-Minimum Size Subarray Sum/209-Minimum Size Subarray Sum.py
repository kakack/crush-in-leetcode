# -*- coding: utf-8 -*
"""
LeetCode 209 - Minimum Size Subarray Sum

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
r"""
@author: Kai Chen
@file: 209-Minimum Size Subarray Sum.py
@time: 2020/6/28 10:33
@desc:
Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.

Example:

Input: s = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: the subarray [4,3] has the minimal length under the problem constraint.
Follow up:
If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).

"""
import bisect

class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        ans = len(nums) + 1
        subsum = [0]
        for i in range(len(nums)):
            subsum.append(subsum[-1] + nums[i])

        for i in range(1, len(nums) + 1):
            target = s + sum[i - 1]
            bound = bisect.bisect_left(subsum, target)
            if bound != len(subsum):
                ans = min(ans, bound - (i - 1))
        return 0 if ans == len(nums) + 1 else ans


