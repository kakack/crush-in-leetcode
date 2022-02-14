# Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

# Each element in the array represents your maximum jump length at that position.

# Your goal is to reach the last index in the minimum number of jumps.

# You can assume that you can always reach the last index.

 

# Example 1:

# Input: nums = [2,3,1,1,4]
# Output: 2
# Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
# Example 2:

# Input: nums = [2,3,0,1,4]
# Output: 2
 

# Constraints:

# 1 <= nums.length <= 10^4
# 0 <= nums[i] <= 1000


# 后向

class Solution:
    def jump(self, nums: List[int]) -> int:
        pos = len(nums) - 1
        steps = 0
        while pos:
            for i in range(pos):
                if nums[i] + i >= pos:
                    pos = i
                    steps += 1
                    break
        return steps

#  前向

class Solution:
    def jump(self, nums: List[int]) -> int:
        maxPos, end, steps = 0, 0, 0
        n = len(nums)
        for i in range(n - 1):
            if maxPos >= i:
                maxPos = max(maxPos, nums[i] + i)
                if i == end:
                    end = maxPos
                    steps += 1
        return steps