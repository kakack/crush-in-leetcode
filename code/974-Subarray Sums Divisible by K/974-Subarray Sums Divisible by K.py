"""
LeetCode 974 - Subarray Sums Divisible by K

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.
#
# Example 1:
#
# Input: A = [4,5,0,-2,-3,1], K = 5
# Output: 7
# Explanation: There are 7 subarrays with a sum divisible by K = 5:
# [4, 5, 0, -2, -3, 1], [5], [5, 0], [5, 0, -2, -3], [0], [0, -2, -3], [-2, -3]
#
#
# Note:
#
# 1 <= A.length <= 30000
# -10000 <= A[i] <= 10000
# 2 <= K <= 10000

class Solution(object):
    def subarraysDivByK(self, A, K):
        """
        :type A: List[int]
        :type K: int
        :rtype: int
        """
        map = [0] * K
        map[0] = 1
        preSum, count = 0, 0
        for i in range(len(A)):
            preSum = (preSum + A[i]) % K
            if preSum < 0:
                preSum += K
            count += map[preSum]
            map[preSum] += 1
        return count
