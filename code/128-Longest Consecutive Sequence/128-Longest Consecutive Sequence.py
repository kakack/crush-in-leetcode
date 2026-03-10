# -*- coding: utf-8 -*
"""
LeetCode 128 - Longest Consecutive Sequence

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""

# Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
#
# Your algorithm should run in O(n) complexity.
#
# Example:
#
# Input: [100, 4, 200, 1, 3, 2]
# Output: 4
# Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.

class Solution(object):
    def longestConsecutive(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        length = len(nums)
        if length == 0:
            return 0
        elif length == 1:
            return 1
        nums.sort()
        max_len, len_ = 0, 1
        pre = nums[0]
        for item in nums[1:]:
            if item - 1 == pre:
                len_ += 1
            elif item != pre:
                len_ = 1
            max_len = max(max_len, len_)
            pre = item
        return max_len

if __name__ == '__main__':
    s = Solution()
    nums = [1,2,0,1]
    print(s.longestConsecutive(nums))
