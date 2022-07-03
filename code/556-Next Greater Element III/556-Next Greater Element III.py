# Given a positive integer n, find the smallest integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive integer exists, return -1.

# Note that the returned integer should fit in 32-bit integer, if there is a valid answer but it does not fit in 32-bit integer, return -1.

 

# Example 1:

# Input: n = 12
# Output: 21
# Example 2:

# Input: n = 21
# Output: -1
 

# Constraints:

# 1 <= n <= 2^31 - 1


class Solution:
    def nextGreaterElement(self, n: int) -> int:
        nums = list(str(n))
        i = len(nums) - 2
        while i >= 0 and nums[i] >= nums[i + 1]:
            i -= 1
        if i < 0:
            return -1
        j = len(nums) - 1
        while j >= 0 and nums[i] >= nums[j]:
            j -= 1
        nums[i], nums[j] = nums[j], nums[i]
        nums[i + 1:] = nums[i + 1:][::-1]
        ans = int(''.join(nums))
        return ans if ans < 2 ** 31 else -1
