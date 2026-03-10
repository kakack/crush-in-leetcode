# -*- coding: utf-8 -*
"""
LeetCode 315 - Count of Smaller Numbers After Self

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
r"""
@author: Kaka Chen
@license: (C) Copyright Personal Uncommercial Limited.
@contact: kakachen1990@gmail.com
@file: 315-Count of Smaller Numbers After Self.py
@time: 2020/7/11 2:27 下午
@desc:
You are given an integer array nums and you have to return a new counts array. The counts array has the property where counts[i] is the number of smaller elements to the right of nums[i].

Example:

Input: [5,2,6,1]
Output: [2,1,1,0]
Explanation:
To the right of 5 there are 2 smaller elements (2 and 1).
To the right of 2 there is only 1 smaller element (1).
To the right of 6 there is 1 smaller element (1).
To the right of 1 there is 0 smaller element.

"""

import bisect


class Solution(object):
    def countSmaller(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        if not nums:
            return []
        sorted_num, res = [], []
        for num in nums[::-1]:
            index = bisect.bisect_left(sorted_num, num)
            res.insert(0, index)
            sorted_num.insert(index, num)
        return res


if __name__ == '__main__':
    s = Solution()
    print(s.countSmaller([5, 2, 6, 1]))
