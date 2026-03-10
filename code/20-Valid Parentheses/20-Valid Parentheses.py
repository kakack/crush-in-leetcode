"""
LeetCode 20 - Valid Parentheses

解题步骤（自动整理）
1. 维护栈（或单调栈）保存候选元素的下标/值
2. 遍历序列时根据出栈条件更新答案，再将当前元素入栈
3. 遍历结束后处理剩余元素（如需要）并返回结果
"""
# Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
#
# An input string is valid if:
#
# Open brackets must be closed by the same type of brackets.
# Open brackets must be closed in the correct order.
# Note that an empty string is also considered valid.
#
# Example 1:
#
# Input: "()"
# Output: true
# Example 2:
#
# Input: "()[]{}"
# Output: true
# Example 3:
#
# Input: "(]"
# Output: false
# Example 4:
#
# Input: "([)]"
# Output: false
# Example 5:
#
# Input: "{[]}"
# Output: true


class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        stack = []
        mapping = {'(': ')', '[': ']', '{': '}'}
        for c in s:
            if c in mapping.keys():
                stack.append(c)
            else:
                if len(stack) == 0 or c != mapping[stack.pop()]:
                    return False
        return True if len(stack) == 0 else False


if __name__ == '__main__':
    mapping = {'(': ')', '[': ']', '{': '}'}
    print(mapping.keys())

