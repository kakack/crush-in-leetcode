"""
LeetCode 917 - Reverse Only Letters

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given a string S, return the "reversed" string where all characters that are not a letter stay in the same place, and all letters reverse their positions.
# Example 1:

# Input: "ab-cd"
# Output: "dc-ba"
# Example 2:

# Input: "a-bC-dEf-ghIj"
# Output: "j-Ih-gfE-dCba"
# Example 3:

# Input: "Test1ng-Leet=code-Q!"
# Output: "Qedo1ct-eeLg=ntse-T!"


# Note:

# - S.length <= 100
# - 33 <= S[i].ASCIIcode <= 122
# - S doesn't contain \ or "

class Solution(object):
    def reverseOnlyLetters(self, S):
        """
        :type S: str
        :rtype: str
        """
        style = []
        letters = []
        res = ''

        for item in S:
            if item.isalpha():
                letters.append(item)
                style.append('a')
            else:
                style.append(item)
        for item in style:
            if item == 'a':
                res += letters.pop()
            else:
                res += item
        return res
