"""
LeetCode 264 - Ugly Number II

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Write a program to find the n-th ugly number.
#
# Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
#
# Example:
# Input: n = 10
# Output: 12
# Explanation: 1, 2, 3, 4, 5, 6, 8, 9, 10, 12 is the sequence of the first 10 ugly numbers.
#
# Note:
# - 1 is typically treated as an ugly number.
# - n does not exceed 1690.

from heapq import heappop, heappush
class Ugly:
    def __init__(self):
        seen = {1,}
        self.nums = []
        heap = []
        heappush(heap, 1)
        for _ in range(1690):
            curr_ugly = heappop(heap)
            self.nums.append(curr_ugly)
            for i in [2, 3, 5]:
                new_ugly = curr_ugly * i
                if new_ugly not in seen:
                    seen.add(new_ugly)
                    heappush(heap, new_ugly)

class Solution(object):
    u = Ugly()
    def nthUglyNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        return self.u.nums[n - 1]

