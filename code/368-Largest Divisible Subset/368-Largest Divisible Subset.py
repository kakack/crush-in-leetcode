# -*- coding: utf-8 -*
"""
LeetCode 368 - Largest Divisible Subset

解题步骤（自动整理）
1. 定义状态（dp[i] 或 dp[i][j]）来表示子问题的最优解/可行性
2. 写出状态转移方程，并处理边界初始化
3. 按依赖顺序递推（必要时滚动数组优化空间），得到最终答案
"""
r"""
@author: Kaka Chen
@license: (C) Copyright Personal Uncommercial Limited.
@contact: kakachen1990@gmail.com
@file: 368-Largest Divisible Subset.py
@time: 2021/4/23 12:51 上午
@desc:
Given a set of distinct positive integers nums, return the largest subset answer such that every pair (answer[i], answer[j]) of elements in this subset satisfies:

answer[i] % answer[j] == 0, or
answer[j] % answer[i] == 0
If there are multiple solutions, return any of them.



Example 1:

Input: nums = [1,2,3]
Output: [1,2]
Explanation: [1,3] is also accepted.
Example 2:

Input: nums = [1,2,4,8]
Output: [1,2,4,8]


Constraints:

1 <= nums.length <= 1000
1 <= nums[i] <= 2 * 109
All the integers in nums are unique.

"""


class Solution(object):
    def largestDivisibleSubset(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        n = len(nums)
        nums = sorted(nums)
        dp = [1] * n
        maxSize = 1
        maxVal = dp[0]
        for i in range(1, n):
            for j in range(i):
                if nums[i] % nums[j] == 0:
                    dp[i] = max(dp[i], dp[j] + 1)
            if dp[i] > maxSize:
                maxSize = dp[i]
                maxVal = nums[i]
        res = []
        if maxSize == 1:
            res.append(nums[0])
            return res
        i = n - 1
        while i >= 0 and maxSize > 0:
            if dp[i] == maxSize and maxVal % nums[i] == 0:
                res.append(nums[i])
                maxVal = nums[i]
                maxSize -= 1
            i -= 1
        return res
