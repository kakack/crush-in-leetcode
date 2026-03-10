"""
LeetCode 41 - First Missing Positive

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
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
