"""
LeetCode 137 - Single Number II

解题步骤（自动整理）
1. 定义状态（dp[i] 或 dp[i][j]）来表示子问题的最优解/可行性
2. 写出状态转移方程，并处理边界初始化
3. 按依赖顺序递推（必要时滚动数组优化空间），得到最终答案
"""
# Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
#
# Note:
#
# Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
#
# Example 1:
#
# Input: [2,2,3,2]
# Output: 3
# Example 2:
#
# Input: [0,1,0,1,0,1,99]
# Output: 99
#


class Solution:
    def singleNumber(self, nums):
        # return (3 * sum(set(nums)) - sum(nums)) // 2

        # first appearance:
        # add num to seen_once
        # don't add to seen_twice because of presence in seen_once

        # second appearance:
        # remove num from seen_once
        # add num to seen_twice

        # third appearance:
        # don't add to seen_once because of presence in seen_twice
        # remove num from seen_twice

        once = twice = 0
        for num in nums:
            once = ~twice & (once ^ num)
            twice = ~once & (twice ^ num)
        return once
