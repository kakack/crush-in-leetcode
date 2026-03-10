"""
LeetCode 13 - Roman to Integer

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given a roman numeral, convert it to an integer.

# Input is guaranteed to be within the range from 1 to 3999.

# 将罗马数字转换成对应的整数。首先将罗马数字翻转，从小的开始累加，
# 如果遇到CM（M-C=1000-100=900）这种该怎么办呢？
# 因为翻转过来是MC，M=1000先被累加，所以使用一个last变量，把M记录下来，如果下一个数小于M，那么减两次C，然后将C累加上，
# 这个实现比较巧妙简洁。

class Solution(object):
    def romanToInt(self, s):
        """
        :type s: str
        :rtype: int
        """
        numerals = {"M": 1000, "D": 500, "C": 100, "L": 50, "X": 10, "V": 5, "I": 1}
        num = 0
        s = s[::-1]
        last = None
        for x in s:
            if last and numerals[x] < last:
                num -= numerals[x]*2
            num += numerals[x]
            last = numerals[x]
        return num
