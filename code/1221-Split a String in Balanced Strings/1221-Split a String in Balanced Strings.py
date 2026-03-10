"""
LeetCode 1221 - Split a String in Balanced Strings

解题步骤（自动整理）
1. 维护栈（或单调栈）保存候选元素的下标/值
2. 遍历序列时根据出栈条件更新答案，再将当前元素入栈
3. 遍历结束后处理剩余元素（如需要）并返回结果
"""
# Balanced strings are those who have equal quantity of 'L' and 'R' characters.
#
# Given a balanced string s split it in the maximum amount of balanced strings.
#
# Return the maximum amount of splitted balanced strings.
#
#
#
# Example 1:
#
# Input: s = "RLRRLLRLRL"
# Output: 4
# Explanation: s can be split into "RL", "RRLL", "RL", "RL", each substring contains same number of 'L' and 'R'.
# Example 2:
#
# Input: s = "RLLLLRRRLR"
# Output: 3
# Explanation: s can be split into "RL", "LLLRRR", "LR", each substring contains same number of 'L' and 'R'.
# Example 3:
#
# Input: s = "LLLLRRRR"
# Output: 1
# Explanation: s can be split into "LLLLRRRR".
# Example 4:
#
# Input: s = "RLRRRLLRLL"
# Output: 2
# Explanation: s can be split into "RL", "RRRLLRLL", since each substring contains an equal number of 'L' and 'R'
#
#
# Constraints:
#
# 1 <= s.length <= 1000
# s[i] = 'L' or 'R'

class Solution(object):
    def balancedStringSplit(self, s):
        """
        :type s: str
        :rtype: int
        """
        # stack = []
        ans, sum = 0, 0
        for char in s:
            if char == 'R':
                sum += 1
            elif char == 'L':
                sum += -1
            if sum == 0:
                    ans += 1
        return ans

