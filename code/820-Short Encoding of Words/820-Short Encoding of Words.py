"""
LeetCode 820 - Short Encoding of Words

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given a list of words, we may encode it by writing a reference string S and a list of indexes A.
#
# For example,
# if the list of words is["time", "me", "bell"], we can write it as S = "time#bell#" and indexes =[0, 2, 5].
# Then for each index, we will recover the word by reading from the reference string from that index until we reach a "#" character.
# What is the length of the shortest reference string S possible that encodes the given words?
#
# Example:
# Input: words = ["time", "me", "bell"]
# Output: 10
# Explanation: S = "time#bell#" and indexes = [0, 2, 5].
#
# Note:
# - 1 <= words.length <= 2000.
# - 1 <= words[i].length <= 7.
# - Each word has only lowercase letters.
class Solution:
    def minimumLengthEncoding(self, words):
        good = set(words)
        for word in words:
            for k in range(1, len(word)):
                good.discard(word[k:])
        return sum(len(word) + 1 for word in good)
