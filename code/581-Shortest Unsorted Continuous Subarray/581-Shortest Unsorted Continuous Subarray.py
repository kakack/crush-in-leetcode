"""
LeetCode 581 - Shortest Unsorted Continuous Subarray

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

# Return the shortest such subarray and output its length.



# Example 1:

# Input: nums = [2,6,4,8,10,9,15]
# Output: 5
# Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
# Example 2:

# Input: nums = [1,2,3,4]
# Output: 0
# Example 3:

# Input: nums = [1]
# Output: 0


# Constraints:

# 1 <= nums.length <= 10^4
# -10^5 <= nums[i] <= 10^5


# Follow up: Can you solve it in O(n) time complexity?

class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        numsS = sorted(nums)
        n = len(nums)
        if numsS == nums:
            return 0
        left, right = 0, n - 1
        while nums[left] == numsS[left]:
            left += 1
        while nums[right] == numsS[right]:
            right -= 1
        return right - left + 1

# nums_i >= min^{n-1}_{j=i+1} nums_j

class Solution:
    def findUnsortedSubarray(self, nums: List[int]) -> int:
        n = len(nums)
        maxn, right = float("-inf"), -1
        minn, left = float("inf"), -1

        for i in range(n):
            if maxn > nums[i]:
                right = i
            else :
                maxn = nums[i]
            if minn < nums[n - i - 1]:
                left = n - i - 1
            else:
                minn = nums[n - i - 1]
        return 0 if right == -1 else right - left + 1
