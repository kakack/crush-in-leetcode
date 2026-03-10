# -*- coding: utf-8 -*
"""
LeetCode 171 - Excel Sheet Column Number

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
r"""
@author: Kai Chen
@file: 171-Excel Sheet Column Number.py
@time: 2020/7/20 9:59
@desc:
Given a column title as appear in an Excel sheet, return its corresponding column number.

For example:

    A -> 1
    B -> 2
    C -> 3
    ...
    Z -> 26
    AA -> 27
    AB -> 28
    ...
Example 1:

Input: "A"
Output: 1
Example 2:

Input: "AB"
Output: 28
Example 3:

Input: "ZY"
Output: 701


Constraints:

1 <= s.length <= 7
s consists only of uppercase English letters.
s is between "A" and "FXSHRXW".
"""


class Solution(object):
    def titleToNumber(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        res = 0
        for i in range(n):
            c = ord(s[i])
            res = 26 * res + (c - ord('A') + 1)
        return res


if __name__ == '__main__':
    s = Solution()
    ipts = ['A', 'B', 'C', 'AB', 'BCD', 'ZY']
    for ipt in ipts:
        print(s.titleToNumber(ipt))
