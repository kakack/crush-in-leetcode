# -*- coding: utf-8 -*
"""
LeetCode 283 - Move Zeroes

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
r"""
@author: Kai Chen
@file: 283-Move Zeroes.py
@time: 2020/11/19 9:32
@desc:
Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Example:

Input: [0,1,0,3,12]
Output: [1,3,12,0,0]
Note:

You must do this in-place without making a copy of the array.
Minimize the total number of operations.
"""

# class Solution(object):
#     def moveZeroes(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: None Do not return anything, modify nums in-place instead.
#         """
#         count = nums.count(0)
#         for i in range(count):
#             nums.remove(0)
#         print(nums)
#         nums += [0 for _ in range(count)]

class Solution(object):
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: None Do not return anything, modify nums in-place instead.
        """
        nums.sort(key=lambda x: x == 0)
        print(nums)
        # return nums


if __name__ == '__main__':
    s = Solution()
    ipt = [0, 1, 0, 3, 12]
    s.moveZeroes(ipt)
