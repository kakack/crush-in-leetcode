# -*- coding: utf-8 -*
"""
LeetCode 67 - Add Binary

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
r"""
@author: Kai Chen
@file: 67-Add Binary.py
@time: 2020/6/24 11:00
@desc:
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:

Input: a = "11", b = "1"
Output: "100"
Example 2:

Input: a = "1010", b = "1011"
Output: "10101"


Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
"""

class Solution(object):
    def addBinary(self, a, b):
        """
        :type a: str
        :type b: str
        :rtype: str
        """
        ans, carry = [], 0
        a, b = a[::-1], b[::-1]
        for i in range(max(len(a), len(b))):
            int_a = int(a[i]) if i < len(a) else 0
            int_b = int(b[i]) if i < len(b) else 0
            val = (int_a + int_b + carry) % 2
            carry = (int_a + int_b + carry) // 2
            ans.insert(0, str(val))
        if carry == 1:
            ans.insert(0, '1')
        return ''.join(ans)


if __name__ == '__main__':
    s = Solution()
    print(s.addBinary("1010", "1011"))
