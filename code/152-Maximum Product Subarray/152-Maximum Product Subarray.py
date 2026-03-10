"""
LeetCode 152 - Maximum Product Subarray

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
#
# Example 1:
#
# Input: [2,3,-2,4]
# Output: 6
# Explanation: [2,3] has the largest product 6.
# Example 2:
#
# Input: [-2,0,-1]
# Output: 0
# Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

class Solution:
    def maxProduct(self, nums):
        prodi = 0
        res = float('-inf')
        for i in range(len(nums)):
            if prodi == 0:
                prodi = 1
                pos = 1
                neg = 1
            prodi *= nums[i]
            res = max(res, prodi/pos) if prodi > 0 else max(res, prodi / neg)
            if prodi > 0 and abs(pos) > abs(prodi):
                pos = prodi
            if prodi < 0 and (abs(neg) > abs(prodi) or neg > 0):
                neg = prodi
        return int(res)
