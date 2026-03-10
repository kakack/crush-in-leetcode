"""
LeetCode 151 - Reverse Words in a String

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given an input string, reverse the string word by word.
#
# Example 1:
# Input: "the sky is blue"
# Output: "blue is sky the"
#
# Example 2:
# Input: "  hello world!  "
# Output: "world! hello"
# Explanation: Your reversed string should not contain leading or trailing spaces.
#
# Example 3:
# Input: "a good   example"
# Output: "example good a"
# Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
#
# Note:
# A word is defined as a sequence of non-space characters.
# Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
# You need to reduce multiple spaces between two words to a single space in the reversed string.
#
# Follow up:
# For C programmers, try to solve it in-place in O(1) extra space.

class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        words = s.split()
        ans = ''
        for word in reversed(words):
            ans += ' ' + word
        return ans[1:]


if __name__ == '__main__':
    s = Solution()
    print(s.reverseWords("the sky is blue"))
    print(s.reverseWords("  hello world!  "))
