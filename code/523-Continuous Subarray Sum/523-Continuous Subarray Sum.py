# -*- coding: utf-8 -*
"""
LeetCode 523 - Continuous Subarray Sum

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
r"""
@author: Kai Chen
@file: 523-Continuous Subarray Sum.py
@time: 2021/6/2 11:32
@desc:
Given an integer array nums and an integer k, return true if nums has a continuous subarray of size at least two whose elements sum up to a multiple of k, or false otherwise.

An integer x is a multiple of k if there exists an integer n such that x = n * k. 0 is always a multiple of k.



Example 1:

Input: nums = [23,2,4,6,7], k = 6
Output: true
Explanation: [2, 4] is a continuous subarray of size 2 whose elements sum up to 6.
Example 2:

Input: nums = [23,2,6,4,7], k = 6
Output: true
Explanation: [23, 2, 6, 4, 7] is an continuous subarray of size 5 whose elements sum up to 42.
42 is a multiple of 6 because 42 = 7 * 6 and 7 is an integer.
Example 3:

Input: nums = [23,2,6,4,7], k = 13
Output: false


Constraints:

1 <= nums.length <= 105
0 <= nums[i] <= 109
0 <= sum(nums[i]) <= 231 - 1
1 <= k <= 231 - 1
"""


class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        m, remainder = len(nums), 0
        if m < 2:
            return False
        mp = {0: -1}
        for i in range(m):
            remainder = (remainder + nums[i]) % k
            if remainder in mp.getkeys():
                prevIndex = mp[remainder]
                if (i - prevIndex) >= 2:
                    return True
            else:
                mp[remainder] = i
        return False


