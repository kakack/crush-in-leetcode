# Given an array of integers nums and an integer k, return the number of unique k-diff pairs in the array.

# A k-diff pair is an integer pair (nums[i], nums[j]), where the following are true:

# 0 <= i, j < nums.length
# i != j
# nums[i] - nums[j] == k
# Notice that |val| denotes the absolute value of val.

 

# Example 1:

# Input: nums = [3,1,4,1,5], k = 2
# Output: 2
# Explanation: There are two 2-diff pairs in the array, (1, 3) and (3, 5).
# Although we have two 1s in the input, we should only return the number of unique pairs.
# Example 2:

# Input: nums = [1,2,3,4,5], k = 1
# Output: 4
# Explanation: There are four 1-diff pairs in the array, (1, 2), (2, 3), (3, 4) and (4, 5).
# Example 3:

# Input: nums = [1,3,1,5,4], k = 0
# Output: 1
# Explanation: There is one 0-diff pair in the array, (1, 1).
 

# Constraints:

# 1 <= nums.length <= 10^4
# -10^7 <= nums[i] <= 10^7
# 0 <= k <= 10^7

class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        nums.sort()
        n, y, res = len(nums), 0, 0
        for x in range(n):
            if x == 0 or nums[x] != nums[x - 1]:
                while y < n and (nums[y] < nums[x] + k or y <= x):
                    y += 1
                if y < n and nums[y] == nums[x] + k:
                    res += 1
        return res