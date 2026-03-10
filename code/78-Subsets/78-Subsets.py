# -*- coding: utf-8 -*
"""
LeetCode 78 - Subsets

解题步骤（自动整理）
1. 用 DFS/回溯枚举所有可能选择，并维护当前路径/状态
2. 在递归过程中进行剪枝（如边界、重复、提前失败条件）
3. 到达终止条件时收集结果或返回，并回溯撤销选择
"""
r"""
@author: Kaka Chen
@license: (C) Copyright Personal Uncommercial Limited.
@contact: kakachen1990@gmail.com
@file: 78-Subsets.py
@time: 2020/9/6 1:06 下午
@desc:
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

"""


class Solution(object):
    # def subsets(self, nums):
    #     """
    #     :type nums: List[int]
    #     :rtype: List[List[int]]
    #     递归
    #     """
    #     n = len(nums)
    #     result = [[]]
    #     for num in nums:
    #         result += [curr + [num] for curr in result]
    #     return result

    def subsets(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        回溯
        """
        result = []
        n = len(nums)
        for k in range(n + 1):
            def backtrack(first=0, curr=[]):
                if len(curr) == k:
                    result.append(curr[:])
                for i in range(first, n):
                    curr.append(nums[i])
                    backtrack(1 + i, curr)
                    curr.pop()
            backtrack()
        return result


if __name__ == '__main__':
    s = Solution()
    ipt = [1, 2, 3, 4]
    print(s.subsets(ipt))
