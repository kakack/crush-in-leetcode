"""
LeetCode 945 - Minimum Increment to Make Array Unique

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given an array of integers A, a move consists of choosing any A[i], and incrementing it by 1.
#
# Return the least number of moves to make every value in A unique.
#
# Example 1:
# Input: [1,2,2]
# Output: 1
# Explanation:  After 1 move, the array could be [1, 2, 3].
#
# Example 2:
# Input: [3,2,1,2,1,7]
# Output: 6
# Explanation:  After 6 moves, the array could be [3, 4, 1, 2, 5, 7].
#
#  It can be shown with 5 or less moves that it is impossible for the array to have all unique values.
#
#
# Note:
#
# 0 <= A.length <= 40000
# 0 <= A[i] < 40000


class Solution(object):
    def minIncrementForUnique(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        A.sort()
        res, curMax = 0, -1
        for i in range(len(A)):
            if A[i] <= curMax:
                res += curMax + 1 - A[i]
                A[i] = curMax + 1
            curMax = max(curMax, A[i])
        return res


if __name__ == '__main__':
    s = Solution()
    # print(s.minIncrementForUnique([1, 2, 2]))
    print(s.minIncrementForUnique([3, 2, 1, 2, 1, 7]))
