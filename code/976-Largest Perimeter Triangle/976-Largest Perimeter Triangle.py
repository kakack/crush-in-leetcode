# -*- coding: utf-8 -*
"""
LeetCode 976 - Largest Perimeter Triangle

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
r"""
@author: Kaka Chen
@license: (C) Copyright Personal Uncommercial Limited.
@contact: kakachen1990@gmail.com
@file: 976-Largest Perimeter Triangle.py
@time: 2020/11/29 11:41 上午
@desc:
Given an array A of positive lengths, return the largest perimeter of a triangle with non-zero area, formed from 3 of these lengths.

If it is impossible to form any triangle of non-zero area, return 0.



Example 1:

Input: [2,1,2]
Output: 5
Example 2:

Input: [1,2,1]
Output: 0
Example 3:

Input: [3,2,3,4]
Output: 10
Example 4:

Input: [3,6,2,3]
Output: 8


Note:

3 <= A.length <= 10000
1 <= A[i] <= 10^6
"""


class Solution(object):
    def largestPerimeter(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        A.sort()
        n = len(A)
        for i in range(n - 1, 1, -1):
            if A[i] < (A[i - 1] + A[i - 2]):
                return A[i] + A[i - 1] + A[i - 2]
        return 0


if __name__ == '__main__':
    s = Solution()
    ipt = [1, 2, 1]
    print(s.largestPerimeter(ipt))
