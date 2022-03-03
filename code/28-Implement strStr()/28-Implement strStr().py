#
# Implement strStr().
#
# Return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
#
# Example 1:
#
# Input: haystack = "hello", needle = "ll"
# Output: 2
# Example 2:
#
# Input: haystack = "aaaaa", needle = "bba"
# Output: -1
# Clarification:
#
# What should we return when needle is an empty string? This is a great question to ask during an interview.
#
# For the purpose of this problem, we will return 0 when needle is an empty string. This is consistent to C's strstr() and Java's indexOf().

class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        len_h = len(haystack)
        len_n = len(needle)
        if len_n == 0:
            return 0
        elif len_h < len_n:
            return -1
        i = 0
        while i + len_n <= len_h:
            if haystack[i:i+len_n] == needle:
                return i
            else:
                i += 1
        return -1

if __name__ == '__main__':
    s = Solution()
    print(s.strStr("hello", "ll"))