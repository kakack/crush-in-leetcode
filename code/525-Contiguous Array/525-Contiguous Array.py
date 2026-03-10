# -*- coding: utf-8 -*
"""
LeetCode 525 - Contiguous Array

解题步骤（自动整理）
1. 使用哈希表记录已遍历元素（或频次/索引）以支持 O(1) 查询
2. 遍历输入并在哈希表中查找所需互补/状态，命中时更新答案
3. 遍历结束后返回答案或默认值
"""
r"""
@author: Kai Chen
@file: 525-Contiguous Array.py
@time: 2021/6/3 11:15
@desc:
Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.



Example 1:

Input: nums = [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with an equal number of 0 and 1.
Example 2:

Input: nums = [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.


Constraints:

1 <= nums.length <= 105
nums[i] is either 0 or 1.
"""


class Solution:
    def findMaxLength(self, nums: List[int]) -> int:
        MaxLength, counter, n = 0, 0, len(nums)
        mp = {0: -1}
        for i in range(n):
            num = nums[i]
            if num == 1:
                counter += 1
            else:
                counter -= 1
            if counter in mp.keys():
                prevIndex = mp[counter]
                MaxLength = max(MaxLength, i - prevIndex)
            else:
                mp[counter] = i
        return MaxLength
