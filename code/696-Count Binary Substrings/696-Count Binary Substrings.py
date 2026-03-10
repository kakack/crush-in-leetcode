# -*- coding: utf-8 -*
"""
LeetCode 696 - Count Binary Substrings

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
r"""
@author: Kai Chen
@file: 696-Count Binary Substrings.py
@time: 2020/8/10 10:09
@desc:
Give a string s, count the number of non-empty (contiguous) substrings that have the same number of 0's and 1's, and all the 0's and all the 1's in these substrings are grouped consecutively.

Substrings that occur multiple times are counted the number of times they occur.

Example 1:
Input: "00110011"
Output: 6
Explanation: There are 6 substrings that have equal number of consecutive 1's and 0's: "0011", "01", "1100", "10", "0011", and "01".

Notice that some of these substrings repeat and are counted the number of times they occur.

Also, "00110011" is not a valid substring because all the 0's (and 1's) are not grouped together.
Example 2:
Input: "10101"
Output: 4
Explanation: There are 4 substrings: "10", "01", "10", "01" that have equal number of consecutive 1's and 0's.
Note:

s.length will be between 1 and 50,000.
s will only consist of "0" or "1" characters.
"""


class Solution(object):
    def countBinarySubstrings(self, s):
        """
        :type s: str
        :rtype: int
        """
        counts = []
        ptr, n = 0, len(s)
        while ptr < n:
            c = s[ptr]
            count = 0
            while ptr < n and s[ptr] == c:
                ptr += 1
                count += 1
            counts.append(count)
        ans = 0
        for i in range(1, len(counts)):
            ans += min(counts[i], counts[i - 1])
        return ans


if __name__ == '__main__':
    s = Solution()
    print(s.countBinarySubstrings("00110011"))
