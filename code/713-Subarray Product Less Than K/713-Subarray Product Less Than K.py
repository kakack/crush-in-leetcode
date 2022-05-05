# Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

 

# Example 1:

# Input: nums = [10,5,2,6], k = 100
# Output: 8
# Explanation: The 8 subarrays that have product less than 100 are:
# [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
# Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
# Example 2:

# Input: nums = [1,2,3], k = 0
# Output: 0
 

# Constraints:

# 1 <= nums.length <= 3 * 10^4
# 1 <= nums[i] <= 1000
# 0 <= k <= 10^6

class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        if k == 0:
            return 0
        ans, n = 0, len(nums)
        logPrefix = [0] * (n + 1)
        for i, num in enumerate(nums):
            logPrefix[i + 1] = logPrefix[i] + log(num)
        logK = log(k)
        for j in range(1, n + 1):
            l = bisect_right(logPrefix, logPrefix[j] - logK + 1e-10, 0, j)
            ans += j - l
        return ans
            