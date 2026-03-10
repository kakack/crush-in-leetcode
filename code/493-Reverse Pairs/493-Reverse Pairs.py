# -*- coding: utf-8 -*
"""
LeetCode 493 - Reverse Pairs

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
r"""
@author: Kai Chen
@file: 493-Reverse Pairs.py
@time: 2020/11/28 10:40
@desc:
Given an array nums, we call (i, j) an important reverse pair if i < j and nums[i] > 2*nums[j].

You need to return the number of important reverse pairs in the given array.

Example1:

Input: [1,3,2,3,1]
Output: 2
Example2:

Input: [2,4,3,5,1]
Output: 3
Note:
The length of the given array will not exceed 50,000.
All the numbers in the input array are in the range of 32-bit integer.
"""


class Solution(object):
    def reversePairs(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """

        def reversePairsRecursive(nums, left, right):
            if left == right:
                return 0
            else:
                mid = (left + right) // 2
                n1 = reversePairsRecursive(nums, left, mid)
                n2 = reversePairsRecursive(nums, mid + 1, right)
                ret = n1 + n2
                i, j = left, mid + 1
                while i <= mid:
                    while j <= right and nums[i] > 2 * nums[j]:
                        j += 1
                    ret += (j - mid - 1)
                    i += 1

                sortedarr = []
                p1, p2 = left, mid + 1
                while p1 <= mid or p2 <= right:
                    if p1 > mid:
                        sortedarr.append(nums[p2])
                        p2 += 1
                    elif p2 > right:
                        sortedarr.append(nums[p1])
                        p1 += 1
                    else:
                        if nums[p1] < nums[p2]:
                            sortedarr.append(nums[p1])
                            p1 += 1
                        else:
                            sortedarr.append(nums[p2])
                            p2 += 1
                nums[left: left + len(sortedarr)] = sortedarr[:]
                return ret

        if len(nums) == 0:
            return 0
        else:
            return reversePairsRecursive(nums, 0, len(nums) - 1)
