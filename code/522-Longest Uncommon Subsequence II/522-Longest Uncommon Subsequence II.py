# Given an array of strings strs, return the length of the longest uncommon subsequence between them. If the longest uncommon subsequence does not exist, return -1.

# An uncommon subsequence between an array of strings is a string that is a subsequence of one string but not the others.

# A subsequence of a string s is a string that can be obtained after deleting any number of characters from s.

# For example, "abc" is a subsequence of "aebdc" because you can delete the underlined characters in "aebdc" to get "abc". Other subsequences of "aebdc" include "aebdc", "aeb", and "" (empty string).
#  

# Example 1:

# Input: strs = ["aba","cdc","eae"]
# Output: 3
# Example 2:

# Input: strs = ["aaa","aaa","aa"]
# Output: -1
#  

# Constraints:

# 2 <= strs.length <= 50
# 1 <= strs[i].length <= 10
# strs[i] consists of lowercase English letters.


class Solution:
    def findLUSlength(self, strs: List[str]) -> int:
        def is_subseq(s: str, t: str) -> bool:
            pt_s = pt_t = 0
            while pt_s < len(s) and pt_t < len(t):
                if s[pt_s] == t[pt_t]:
                    pt_s += 1
                pt_t += 1
            return pt_s == len(s)
        
        ans = -1
        for i, s in enumerate(strs):
            check = True
            for j, t in enumerate(strs):
                if i != j and is_subseq(s, t):
                    check = False
                    break
            if check:
                ans = max(ans, len(s))
        
        return ans
