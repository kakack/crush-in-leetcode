# -*- coding: utf-8 -*
"""
LeetCode 1047 - Remove All Adjacent Duplicates In String

解题步骤（自动整理）
1. 维护栈（或单调栈）保存候选元素的下标/值
2. 遍历序列时根据出栈条件更新答案，再将当前元素入栈
3. 遍历结束后处理剩余元素（如需要）并返回结果
"""
r"""
@author: Kai Chen
@file: 1047-Remove All Adjacent Duplicates In String.py
@time: 2020/8/11 15:16
@desc:
Given a string S of lowercase letters, a duplicate removal consists of choosing two adjacent and equal letters, and removing them.

We repeatedly make duplicate removals on S until we no longer can.

Return the final string after all such duplicate removals have been made.  It is guaranteed the answer is unique.



Example 1:

Input: "abbaca"
Output: "ca"
Explanation:
For example, in "abbaca" we could remove "bb" since the letters are adjacent and equal, and this is the only possible move.  The result of this move is that the string is "aaca", of which only "aa" is possible, so the final string is "ca".


Note:

1 <= S.length <= 20000
S consists only of English lowercase letters.
"""


class Solution(object):
    def removeDuplicates(self, S):
        """
        :type S: str
        :rtype: str
        """
        stack = []
        for c in S:
            if stack and stack[-1] == c:
                stack.pop()
            else:
                stack.append(c)
        return "".join(stack)


if __name__ == '__main__':
    s = Solution()
    print(s.removeDuplicates("abbaca"))
