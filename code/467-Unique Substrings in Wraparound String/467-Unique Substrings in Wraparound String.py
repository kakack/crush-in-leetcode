"""
LeetCode 467 - Unique Substrings in Wraparound String

解题步骤（自动整理）
1. 定义状态（dp[i] 或 dp[i][j]）来表示子问题的最优解/可行性
2. 写出状态转移方程，并处理边界初始化
3. 按依赖顺序递推（必要时滚动数组优化空间），得到最终答案
"""
# We define the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this:

# "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
# Given a string p, return the number of unique non-empty substrings of p are present in s.



# Example 1:

# Input: p = "a"
# Output: 1
# Explanation: Only the substring "a" of p is in s.
# Example 2:

# Input: p = "cac"
# Output: 2
# Explanation: There are two substrings ("a", "c") of p in s.
# Example 3:

# Input: p = "zab"
# Output: 6
# Explanation: There are six substrings ("z", "a", "b", "za", "ab", and "zab") of p in s.


# Constraints:

# 1 <= p.length <= 10^5
# p consists of lowercase English letters.

from collections import defaultdict


class Solution:
    def findSubstringInWraproundString(self, p: str) -> int:
        dp = defaultdict(int)
        k = 0
        for i, ch in enumerate(p):
            if i > 0 and (ord(ch) - ord(p[i - 1])) % 26 == 1:
                k += 1
            else:
                k = 1
            dp[ch] = max(dp[ch], k)
        return sum(dp.values())
