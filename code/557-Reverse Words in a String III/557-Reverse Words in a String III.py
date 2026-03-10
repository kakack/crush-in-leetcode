"""
LeetCode 557 - Reverse Words in a String III

解题步骤（自动整理）
1. 维护栈（或单调栈）保存候选元素的下标/值
2. 遍历序列时根据出栈条件更新答案，再将当前元素入栈
3. 遍历结束后处理剩余元素（如需要）并返回结果
"""
# Given a string, you need to reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.
#
# Example 1:
# Input: "Let's take LeetCode contest"
# Output: "s'teL ekat edoCteeL tsetnoc"
# Note: In the string, each word is separated by single space and there will not be any extra space in the string.

class Solution(object):
    def reverseWords(self, s):
        """
        :type s: str
        :rtype: str
        """
        s += ' '
        stack = []
        res = ''
        for item in s:
            if item == ' ':
                for char in reversed(stack):
                    res += char
                res += ' '
                stack = []
            else:
                stack.append(item)

        return res[0: -1]

if __name__ == '__main__':
    s = Solution()
    print(s.reverseWords("Let's take LeetCode contest"))
