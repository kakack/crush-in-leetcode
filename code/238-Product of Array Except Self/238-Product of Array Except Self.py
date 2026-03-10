"""
LeetCode 238 - Product of Array Except Self

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].
#
# Example:
#
# Input:  [1,2,3,4]
# Output: [24,12,8,6]
# Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.
#
# Note: Please solve it without division and in O(n).
#
# Follow up:
# Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)


class Solution(object):
    def productExceptSelf(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        # l_pd, r_pd, ans = [1] * len(nums), [1] * len(nums), [1] * len(nums)
        # for i in range(1, len(nums)):
        #     l_pd[i] = l_pd[i - 1] * nums[i - 1]
        # for i in reversed(range(len(nums) - 1)):
        #     r_pd[i] = r_pd[i + 1] * nums[i + 1]
        # for i in range(len(nums)):
        #     ans[i] = l_pd[i] * r_pd[i]
        # return ans

        length = len(nums)
        ans = [1] * length
        for i in range(1, length):
            ans[i] = nums[i - 1] * ans[i - 1]
        R = 1
        for i in reversed(range(length)):
            ans [i] = ans[i] * R
            R *= nums[i]
        return ans
