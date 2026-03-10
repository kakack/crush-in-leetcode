# -*- coding: utf-8 -*
"""
LeetCode 1281 - Subtract the Product and Sum of Digits of an Integer

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
r"""
@author: Kaka Chen
@license: (C) Copyright Personal Uncommercial Limited.
@contact: kakachen1990@gmail.com
@file: 1281-Subtract the Product and Sum of Digits of an Integer.py
@time: 2020/10/1 11:25 上午
@desc:
Given an integer number n, return the difference between the product of its digits and the sum of its digits.


Example 1:

Input: n = 234
Output: 15
Explanation:
Product of digits = 2 * 3 * 4 = 24
Sum of digits = 2 + 3 + 4 = 9
Result = 24 - 9 = 15
Example 2:

Input: n = 4421
Output: 21
Explanation:
Product of digits = 4 * 4 * 2 * 1 = 32
Sum of digits = 4 + 4 + 2 + 1 = 11
Result = 32 - 11 = 21


Constraints:

1 <= n <= 10^5
"""


class Solution(object):
    def subtractProductAndSum(self, n):
        """
        :type n: int
        :rtype: int
        """
        sum, product = 0, 1
        while n > 0:
            tmp = n % 10
            sum += tmp
            product = product * tmp
            n = n / 10
            print(product, sum)

        print(product, sum, product - sum)
        return product - sum


if __name__ == '__main__':
    s = Solution()
    s.subtractProductAndSum(234)
