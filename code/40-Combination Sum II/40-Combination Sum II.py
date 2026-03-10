# -*- coding: utf-8 -*
"""
LeetCode 40 - Combination Sum II

解题步骤（自动整理）
1. 用 DFS/回溯枚举所有可能选择，并维护当前路径/状态
2. 在递归过程中进行剪枝（如边界、重复、提前失败条件）
3. 到达终止条件时收集结果或返回，并回溯撤销选择
"""
r"""
@author: Kai Chen
@file: 40-Combination Sum II.py
@time: 2020/7/17 10:15
@desc:
Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:

Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]
Example 2:

Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]
]
"""


class Solution(object):
    def combinationSum2(self, candidates, target):
        """
        :type candidates: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        size = len(candidates)
        if size == 0:
            return []
        candidates.sort()
        res = []

        def dfs(begin, path, residue):
            if residue == 0:
                res.append(path[:])
                return
            for index in range(begin, size):
                if candidates[index] > residue:
                    break
                elif index > begin and candidates[index - 1] == candidates[index]:
                    continue
                path.append(candidates[index])
                dfs(index + 1, path, residue - candidates[index])
                path.pop()

        dfs(0, [], target)
        return res


if __name__ == '__main__':
    s = Solution()
    candidates = [10, 1, 2, 7, 6, 1, 5]
    target = 8
    print(s.combinationSum2(candidates, target))
