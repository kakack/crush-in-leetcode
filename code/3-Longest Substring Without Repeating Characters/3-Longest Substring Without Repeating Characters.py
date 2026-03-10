"""
LeetCode 3 - Longest Substring Without Repeating Characters

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given a string, find the length of the longest substring without repeating characters.

# Examples:

# Given "abcabcbb", the answer is "abc", which the length is 3.
# Given "bbbbb", the answer is "b", with the length of 1.
# Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.

# 用hash表，也就是python中的字典dict来存储字符串中的内容

class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        dic, start, res = {}, 0, 0
        for i, ch in enumerate(s):
            # 这个enumerate用的很巧妙，精简了很多代码，不然要写成dict[s[i]]
            if ch in dic:
                res = max(res, i-start)
                start = max(start, dic[ch] + 1)
            dic[ch] = i
        return max(res, len(s)-start)
        # 小心没重复的substring


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        mp = set()
        n = len(s)
        start, res = -1, 0
        for i in range(n):
            if  i != 0:
                mp.remove(s[i - 1])
            while start + 1 < n and  s[start + 1] not in mp:
                mp.add(s[start + 1])
                start += 1
            res = max(res, start - i + 1)
        return res
