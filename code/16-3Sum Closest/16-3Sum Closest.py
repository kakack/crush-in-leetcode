# Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

# Return the sum of the three integers.

# You may assume that each input would have exactly one solution.

 

# Example 1:

# Input: nums = [-1,2,1,-4], target = 1
# Output: 2
# Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
# Example 2:

# Input: nums = [0,0,0], target = 1
# Output: 0
 

# Constraints:

# 3 <= nums.length <= 1000
# -1000 <= nums[i] <= 1000
# -10^4 <= target <= 10^4

class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        nums.sort()
        n = len(nums)
        best = 10**7
        
        def update(cur):
            nonlocal best
            if abs(cur - target) < abs(best - target):
                best = cur
        
        for i in range(n):
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            j, k = i + 1, n - 1
            while j < k:
                s = nums[i] + nums[j] + nums[k]
                if s == target:
                    return target
                update(s)
                if s > target:
                    k0 = k - 1
                    while(j < k0 and nums[k0] == nums[k]):
                        k0 -= 1
                    k = k0
                else:
                    j0 = j + 1
                    while(j0 < k and nums[j0] == nums[j]):
                        j0 += 1
                    j = j0
        return best