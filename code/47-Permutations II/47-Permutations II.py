# -*- coding: utf-8 -*
"""
LeetCode 47 - Permutations II

解题步骤（自动整理）
1. 用 DFS/回溯枚举所有可能选择，并维护当前路径/状态
2. 在递归过程中进行剪枝（如边界、重复、提前失败条件）
3. 到达终止条件时收集结果或返回，并回溯撤销选择
"""
r"""
@author: Kaka Chen
@license: (C) Copyright Personal Uncommercial Limited.
@contact: kakachen1990@gmail.com
@file: 47-Permutations II.py
@time: 2020/9/18 8:22 下午
@desc:
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

Example:

Input: [1,1,2]
Output:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
"""


class Solution(object):
    def permuteUnique(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        res = []

        def backtrack(left, history):
            nonlocal res
            if not left:
                res.append(history)
            for i in set(left):
                left.remove(i)
                left.append(i)
                backtrack(left[:-1], history + [i])

        backtrack(nums, [])
        return res


if __name__ == '__main__':
    s = Solution()
    ipt = [1, 1, 2]
    print(s.permuteUnique(ipt))
