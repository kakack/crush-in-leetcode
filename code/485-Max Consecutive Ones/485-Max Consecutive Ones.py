# -*- coding: utf-8 -*
"""
LeetCode 485 - Max Consecutive Ones

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
r"""
@author: Kaka Chen
@license: (C) Copyright Personal Uncommercial Limited.
@contact: kakachen1990@gmail.com
@file: 485-Max Consecutive Ones.py
@time: 2020/6/21 10:18 下午
@desc:

Given a binary array, find the maximum number of consecutive 1s in this array.

Example 1:
Input: [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s.
    The maximum number of consecutive 1s is 3.
Note:

The input array will only contain 0 and 1.
The length of input array is a positive integer and will not exceed 10,000

"""

class Solution(object):
    def findMaxConsecutiveOnes(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans, cur = 0, 0
        for char in nums:
            if char == 1:
                cur += 1
                ans = max(ans, cur)
            else:
                cur = 0
        return ans

if __name__ == '__main__':
    s = Solution()
    # nums = [1, 1, 0, 1, 1, 1]
    nums = [0]
    print(s.findMaxConsecutiveOnes(nums))
