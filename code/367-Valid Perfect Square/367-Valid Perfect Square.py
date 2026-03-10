"""
LeetCode 367 - Valid Perfect Square

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given a positive integer num, write a function which returns True if num is a perfect square else False.
#
# Note: Do not use any built-in library function such as sqrt.
#
# Example 1:
# Input: 16
# Output: true
#
# Example 2:
# Input: 14
# Output: false

import math

class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        i = 1
        while num > 0:
            num -= i
            i += 2
        return True if num == 0 else False

if __name__ == '__main__':
    s = Solution()
    for i in [1, 2, 4, 9, 16, 25, 36, 81, 124]:
        print(s.isPerfectSquare(i))
