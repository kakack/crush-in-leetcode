# Given an unsorted integer array nums, return the smallest missing positive integer.

# You must implement an algorithm that runs in O(n) time and uses constant extra space.

 

# Example 1:

# Input: nums = [1,2,0]
# Output: 3
# Example 2:

# Input: nums = [3,4,-1,1]
# Output: 2
# Example 3:

# Input: nums = [7,8,9,11,12]
# Output: 1
 

# Constraints:

# 1 <= nums.length <= 5 * 10^5
# -2^31 <= nums[i] <= 2^31 - 1

class Solution:
    def firstMissingPositive(self, nums: List[int]) -> int:
        n = len(nums)
        for i in range(n):
            while 1 <= nums[i] <= n and nums[nums[i] - 1] != nums[i]:
                nums[nums[i] - 1], nums[i] = nums[i], nums[nums[i] - 1]
        for i in range(n):
            if nums[i] != i + 1:
                return i + 1
        return n + 1 
        