"""
LeetCode 724 - Find Pivot Index

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given an array of integers nums, write a method that returns the "pivot" index of this array.

# We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.

# If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

# Example 1:

# Input:
# nums = [1, 7, 3, 6, 5, 6]
# Output: 3
# Explanation:
# The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
# Also, 3 is the first index where this occurs.
#

# Example 2:

# Input:
# nums = [1, 2, 3]
# Output: -1
# Explanation:
# There is no index that satisfies the conditions in the problem statement.
#

# Note:

# The length of nums will be in the range [0, 10000].
# Each element nums[i] will be an integer in the range [-1000, 1000].

class Solution(object):
    def pivotIndex(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        nums.insert(0, 0)
        sumNums = sum(nums)
        sumLeft = 0
        for i in range(1, len(nums)):
            sumLeft += nums[i - 1]
            if sumLeft * 2 == sumNums - nums[i]:
                return i - 1
        return -1

if __name__ == '__main__':
    s = Solution()
    print(s.pivotIndex([1, 7, 3, 6, 5, 6]))
    print(s.pivotIndex([1, 2, 3]))
    print(s.pivotIndex([-1,-1,-1,0,1,1]))
