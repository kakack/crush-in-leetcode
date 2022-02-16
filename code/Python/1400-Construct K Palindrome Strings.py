# Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.

 

# Example 1:

# Input: s = "annabelle", k = 2
# Output: true
# Explanation: You can construct two palindromes using all characters in s.
# Some possible constructions "anna" + "elble", "anbna" + "elle", "anellena" + "b"
# Example 2:

# Input: s = "leetcode", k = 3
# Output: false
# Explanation: It is impossible to construct 3 palindromes using all the characters of s.
# Example 3:

# Input: s = "true", k = 4
# Output: true
# Explanation: The only possible solution is to put each character in a separate string.
 

# Constraints:

# 1 <= s.length <= 10^5
# s consists of lowercase English letters.
# 1 <= k <= 10^5

class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        alphs = [0 for _ in range(26)]
        for ch in s:
            alphs[ord(ch) - ord('a')] += 1
        n, odd = len(s), 0
        for alph in alphs:
            if alph % 2 == 1:
                odd += 1
        odd = max(1, odd)
        return odd <= k and k <= n

class Solution:
    def canConstruct(self, s: str, k: int) -> bool:
        # 右边界为字符串的长度
        right = len(s)
        # 统计每个字符出现的次数
        occ = collections.Counter(s)
        # 左边界为出现奇数次字符的个数
        left = sum(1 for _, v in occ.items() if v % 2 == 1)
        # 注意没有出现奇数次的字符的特殊情况
        left = max(left, 1)
        return left <= k <= right
