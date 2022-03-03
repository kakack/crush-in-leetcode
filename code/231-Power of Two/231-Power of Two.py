# Given an integer, write a function to determine if it is a power of two.
#
# Example 1:
#
# Input: 1
# Output: true
# Explanation: 20 = 1
# Example 2:
#
# Input: 16
# Output: true
# Explanation: 24 = 16
# Example 3:
#
# Input: 218
# Output: false

class Solution(object):
    def isPowerOfTwo(self, n):
        """
        :type n: int
        :rtype: bool
        """
        # if n == 1:
        #     return True
        # else:
        #     return n % 2 == 0  and self.isPowerOfTwo(n/2)
        return (n & (n - 1)) == 0 if n > 0 else False