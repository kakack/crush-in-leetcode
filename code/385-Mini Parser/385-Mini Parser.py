"""
LeetCode 385 - Mini Parser

解题步骤（自动整理）
1. 用 DFS/回溯枚举所有可能选择，并维护当前路径/状态
2. 在递归过程中进行剪枝（如边界、重复、提前失败条件）
3. 到达终止条件时收集结果或返回，并回溯撤销选择
"""
# Given a string s represents the serialization of a nested list, implement a parser to deserialize it and return the deserialized NestedInteger.

# Each element is either an integer or a list whose elements may also be integers or other lists.



# Example 1:

# Input: s = "324"
# Output: 324
# Explanation: You should return a NestedInteger object which contains a single integer 324.
# Example 2:

# Input: s = "[123,[456,[789]]]"
# Output: [123,[456,[789]]]
# Explanation: Return a NestedInteger object containing a nested list with 2 elements:
# 1. An integer containing value 123.
# 2. A nested list containing two elements:
#     i.  An integer containing value 456.
#     ii. A nested list with one element:
#          a. An integer containing value 789


# Constraints:

# 1 <= s.length <= 5 * 10^4
# s consists of digits, square brackets "[]", negative sign '-', and commas ','.
# s is the serialization of valid NestedInteger.
# All the values in the input are in the range [-10^6, 10^6].

# """
# This is the interface that allows for creating nested lists.
# You should not implement it, or speculate about its implementation
# """
#class NestedInteger:
#    def __init__(self, value=None):
#        """
#        If value is not specified, initializes an empty list.
#        Otherwise initializes a single integer equal to value.
#        """
#
#    def isInteger(self):
#        """
#        @return True if this NestedInteger holds a single integer, rather than a nested list.
#        :rtype bool
#        """
#
#    def add(self, elem):
#        """
#        Set this NestedInteger to hold a nested list and adds a nested integer elem to it.
#        :rtype void
#        """
#
#    def setInteger(self, value):
#        """
#        Set this NestedInteger to hold a single integer equal to value.
#        :rtype void
#        """
#
#    def getInteger(self):
#        """
#        @return the single integer that this NestedInteger holds, if it holds a single integer
#        Return None if this NestedInteger holds a nested list
#        :rtype int
#        """
#
#    def getList(self):
#        """
#        @return the nested list that this NestedInteger holds, if it holds a nested list
#        Return None if this NestedInteger holds a single integer
#        :rtype List[NestedInteger]
#        """

class Solution:
    def deserialize(self, s: str) -> NestedInteger:
        index = 0
        def dfs() -> NestedInteger:
            nonlocal index
            if s[index] == '[':
                index += 1
                ni = NestedInteger()
                while s[index] != ']':
                    ni.add(dfs())
                    if s[index] == ',':
                        index += 1
                index += 1
                return ni
            else:
                neg = False
                if s[index] == '-':
                    neg = True
                    index += 1
                num = 0
                while index < len(s) and s[index].isdigit():
                    num *= 10
                    num += int(s[index])
                    index += 1
                if neg:
                    num = -num
                return NestedInteger(num)
        return dfs()
