# Given two strings S and T, return if they are equal when both are typed into empty text editors. # means a backspace character.
#
# Example 1:
# Input: S = "ab#c", T = "ad#c"
# Output: true
# Explanation: Both S and T become "ac".
#
# Example 2:
# Input: S = "ab##", T = "c#d#"
# Output: true
# Explanation: Both S and T become "".
#
# Example 3:
# Input: S = "a##c", T = "#a#c"
# Output: true
# Explanation: Both S and T become "c".
#
# Example 4:
# Input: S = "a#c", T = "b"
# Output: false
#
# Explanation: S becomes "c" while T becomes "b".
# Note:
#
# - 1 <= S.length <= 200
# - 1 <= T.length <= 200
# - S and T only contain lowercase letters and '#' characters.
#
# Follow up:
# Can you solve it in O(N) time and O(1) space?

class Solution(object):
    def backspaceCompare(self, S, T):
        """
        :type S: str
        :type T: str
        :rtype: bool
        """
        def result(S):
            stack = []
            for char in S:
                if char == '#' and len(stack) > 0:
                    stack.pop(-1)
                elif char != '#':
                    stack.append(char)
            res = ''
            for char in stack:
                res += char
            return res

        return True if result(S) == result(T) else False


class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        i, j, skipS, skipT = len(s) - 1, len(t) - 1, 0, 0
        while j >= 0 or i >= 0:
            while i >= 0:
                if s[i] == '#':
                    skipS += 1
                    i -= 1
                elif skipS > 0:
                    skipS -= 1
                    i -= 1
                else:
                    break
            while j >= 0:
                if t[j] == '#':
                    skipT += 1
                    j -= 1
                elif skipT > 0:
                    skipT -= 1
                    j -= 1
                else:
                    break
            if i >= 0 and j >= 0:
                if s[i] != t[j]:
                    return False
            elif i >= 0 or j >= 0:
                return False
            i -= 1
            j -= 1
        return True