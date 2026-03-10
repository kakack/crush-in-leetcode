# -*- coding: utf-8 -*
"""
LeetCode 507 - Perfect Number

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
r"""
@author: Kai Chen
@file: 507-Perfect Number.py
@time: 2020/8/7 15:32
@desc:
We define the Perfect Number is a positive integer that is equal to the sum of all its positive divisors except itself.

Now, given an integer n, write a function that returns true when it is a perfect number and false when it is not.
Example:
Input: 28
Output: True
Explanation: 28 = 1 + 2 + 4 + 7 + 14
Note: The input number n will not exceed 100,000,000. (1e8)
"""

from math import sqrt


class Solution(object):
    def checkPerfectNumber(self, num):
        """
        :type num: int
        :rtype: bool
        """
        if num <= 0:
            return False
        res, i = 0, 1
        while i <= sqrt(num):
            if num % i == 0:
                res += i
                if i ** 2 != num:
                    res += (num / i)
            i += 1
        return True if res == 2 * num else False


if __name__ == '__main__':
    s = Solution()
    print(s.checkPerfectNumber(28))
