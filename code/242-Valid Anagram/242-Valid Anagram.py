"""
LeetCode 242 - Valid Anagram

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given two strings s and t , write a function to determine if t is an anagram of s.
#
# Example 1:
# Input: s = "anagram", t = "nagaram"
# Output: true

# Example 2:
# Input: s = "rat", t = "car"
# Output: false

# Note:
# You may assume the string contains only lowercase alphabets.
#
# Follow up:
# What if the inputs contain unicode characters? How would you adapt your solution to such case?

class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        if len(s) != len(t):
            return False
        hash = [0] * 26
        for i in range(len(s)):
            hash[ord(s[i]) - ord('a')] += 1
            hash[ord(t[i]) - ord('a')] -= 1
        for item in hash:
            if item != 0:
                return False
        return True
