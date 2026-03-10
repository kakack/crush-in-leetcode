"""
LeetCode 852 - Peak Index in a Mountain Array

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Let's call an array A a mountain if the following properties hold:

# - A.length >= 3
# - There exists some 0 < i < A.length - 1 such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1]
# Given an array that is definitely a mountain, return any i such that A[0] < A[1] < ... A[i-1] < A[i] > A[i+1] > ... > A[A.length - 1].

# Example 1:

# Input: [0,1,0]
# Output: 1
# Example 2:

# Input: [0,2,1,0]
# Output: 1
# Note:

# - 3 <= A.length <= 10000
# - 0 <= A[i] <= 10^6
# - A is a mountain, as defined above.

class Solution(object):
    def peakIndexInMountainArray(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        first = 0
        second = len(A)
        if len(A) < 3:
            return None
        for i in range(1, len(A)):
            if A[i]  <= A[i - 1]:
                first = i - 1
                break
        for i in range(len(A) - 2, -1 , -1):
            if A[i] <= A[i + 1]:
                second = i + 1
                break
        return first if first == second else None
