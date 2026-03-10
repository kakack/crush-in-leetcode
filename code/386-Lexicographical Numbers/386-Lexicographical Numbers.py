# -*- coding: utf-8 -*
"""
LeetCode 386 - Lexicographical Numbers

解题步骤（自动整理）
1. 用 DFS/回溯枚举所有可能选择，并维护当前路径/状态
2. 在递归过程中进行剪枝（如边界、重复、提前失败条件）
3. 到达终止条件时收集结果或返回，并回溯撤销选择
"""
r"""
@author: Kai Chen
@file: 386-Lexicographical Numbers.py
@time: 2020/11/2 9:38
@desc:
Given an integer n, return 1 - n in lexicographical order.

For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

Please optimize your algorithm to use less time and space.
The input size may be as large as 5,000,000.
"""


class Solution(object):
    def lexicalOrder(self, n):
        """
        :type n: int
        :rtype: List[int]
        """
        res = []

        def dfs(cur):
            if cur > n:
                return
            res.append(cur)
            for i in range(10):
                dfs(cur * 10 + i)

        for i in range(1, 10):
            dfs(i)
        return res


if __name__ == '__main__':
    s = Solution()
    print(s.lexicalOrder(13))
