# -*- coding: utf-8 -*
"""
LeetCode 316 - Remove Duplicate Letters

解题步骤（自动整理）
1. 使用哈希表记录已遍历元素（或频次/索引）以支持 O(1) 查询
2. 遍历输入并在哈希表中查找所需互补/状态，命中时更新答案
3. 遍历结束后返回答案或默认值
"""
r"""
@author: Kai Chen
@file: 316-Remove Duplicate Letters.py
@time: 2020/12/2 11:56
@desc:

Given a string s, remove duplicate letters so that every letter appears once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.

Note: This question is the same as 1081: https://leetcode.com/problems/smallest-subsequence-of-distinct-characters/



Example 1:

Input: s = "bcabc"
Output: "abc"
Example 2:

Input: s = "cbacdcbc"
Output: "acdb"


Constraints:

1 <= s.length <= 104
s consists of lowercase English letters.

"""

import collections

class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        letters = []
        counts = collections.Counter(s)

        for c in s:
            if c not in letters:
                while letters and c < letters[-1] and counts[letters[-1]] > 0:
                    letters.pop()
                letters.append(c)
            counts[c] -= 1
        return "".join(letters)
