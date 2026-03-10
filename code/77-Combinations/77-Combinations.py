# -*- coding: utf-8 -*
"""
LeetCode 77 - Combinations

解题步骤（自动整理）
1. 用 DFS/回溯枚举所有可能选择，并维护当前路径/状态
2. 在递归过程中进行剪枝（如边界、重复、提前失败条件）
3. 到达终止条件时收集结果或返回，并回溯撤销选择
"""
r"""
@author: Kai Chen
@file: 77-Combinations.py
@time: 2020/8/21 11:13
@desc:

Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

You may return the answer in any order.



Example 1:

Input: n = 4, k = 2
Output:
[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]
Example 2:

Input: n = 1, k = 1
Output: [[1]]


Constraints:

1 <= n <= 20
1 <= k <= n
"""


import itertools
class Solution(object):
    # def combine(self, n, k):
    #     """
    #     :type n: int
    #     :type k: int
    #     :rtype: List[List[int]]
    #     """
    #     return list(itertools.combinations(range(1, n + 1), k))

    def combine(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: List[List[int]]
        """
        res = []
        self.dfs(1, k, n, [], res)
        return res

    def dfs(self, start, k, n, pre, res):
        if len(pre) == k:
            res.append(pre[:])
            return
        for i in range(start, n + 1):
            pre.append(i)
            self.dfs(i + 1, k, n, pre, res)
            pre.pop()


if __name__ == '__main__':
    n, k = 4, 2
    s = Solution()
    print(s.combine(n, k))
