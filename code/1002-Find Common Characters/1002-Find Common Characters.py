# -*- coding: utf-8 -*
"""
LeetCode 1002 - Find Common Characters

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
r"""
@author: Kai Chen
@file: 1002-Find Common Characters.py
@time: 2020/10/14 9:08
@desc:
Given an array A of strings made only from lowercase letters, return a list of all characters that show up in all strings within the list (including duplicates).  For example, if a character occurs 3 times in all strings but not 4 times, you need to include that character three times in the final answer.

You may return the answer in any order.



Example 1:

Input: ["bella","label","roller"]
Output: ["e","l","l"]
Example 2:

Input: ["cool","lock","cook"]
Output: ["c","o"]


Note:

1 <= A.length <= 100
1 <= A[i].length <= 100
A[i][j] is a lowercase letter
"""


class Solution(object):
    def commonChars(self, A):
        """
        :type A: List[str]
        :rtype: List[str]
        """
        minfreq = [float("inf")] * 26
        for word in A:
            freq = [0] * 26
            for char in word:
                freq[ord(char) - ord('a')] += 1
            for i in range(26):
                minfreq[i] = min(minfreq[i], freq[i])
        res = list()
        for i in range(26):
            res.extend([chr(i + ord('a'))] * minfreq[i])
        return res


if __name__ == '__main__':
    ipt = ["bella", "label", "roller"]
    s = Solution()
    print(s.commonChars(ipt))
