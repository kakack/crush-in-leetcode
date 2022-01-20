# Given an integer, write a function to determine if it is a power of three.
#
# Example 1:
# Input: 27
# Output: true
#
# Example 2:
# Input: 0
# Output: false
#
# Example 3:
# Input: 9
# Output: true
#
# Example 4:
# Input: 45
# Output: false
#
# Follow up:
# Could you do it without using any loop / recursion?

import math
class Solution(object):

    def isPowerOfThree(self, n):
        """
        :type n: int
        :rtype: bool
        """
        if n < 1:
            return False
        else:
            return (math.log10(n) / math.log10(3)) % 1 == 0