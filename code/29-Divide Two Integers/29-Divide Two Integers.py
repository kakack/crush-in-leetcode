"""
LeetCode 29 - Divide Two Integers

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
#
# Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
#
# Return the quotient after dividing dividend by divisor.
#
# The integer division should truncate toward zero, which means losing its fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) = -2.
#
# Example 1:
#
# Input: dividend = 10, divisor = 3
# Output: 3
# Explanation: 10/3 = truncate(3.33333..) = 3.
# Example 2:
#
# Input: dividend = 7, divisor = -3
# Output: -2
# Explanation: 7/-3 = truncate(-2.33333..) = -2.
# Note:
#
# Both dividend and divisor will be 32-bit signed integers.
# The divisor will never be 0.
# Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.

class Solution(object):
    def div(self, dividend, divisor):

        if dividend == divisor:
            return 1
        elif divisor > dividend:
            return 0
        tmp = divisor
        res = 1
        while dividend > divisor + divisor:
            divisor += divisor
            res += res
        res += self.div(dividend - divisor, tmp)
        return res

    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """

        dividend_ = abs(dividend)
        divisor_ =  abs(divisor)
        res = self.div(dividend_, divisor_)
        if (divisor < 0 and dividend > 0) or (dividend < 0 and divisor > 0):
            res = -res
        return min(max(-2 ** 31, res), 2 ** 31 - 1)
