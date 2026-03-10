"""
LeetCode 326 - Power of Three

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given an integer, write a function to determine if it is a power of three.
#
# Example 1:
# Input: 27
# Output: true
#
# Example 2:
# Input: 0
# Output: false
#
# Example 3:
# Input: 9
# Output: true
#
# Example 4:
# Input: 45
# Output: false
#
# Follow up:
# Could you do it without using any loop / recursion?

import math
class Solution(object):

    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n < 1:
            return False
        else:
            return (math.log10(n) / math.log10(3)) % 1 == 0
