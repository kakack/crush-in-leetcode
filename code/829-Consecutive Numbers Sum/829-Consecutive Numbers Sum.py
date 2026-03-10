"""
LeetCode 829 - Consecutive Numbers Sum

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given an integer n, return the number of ways you can write n as the sum of consecutive positive integers.



# Example 1:

# Input: n = 5
# Output: 2
# Explanation: 5 = 2 + 3
# Example 2:

# Input: n = 9
# Output: 3
# Explanation: 9 = 4 + 5 = 2 + 3 + 4
# Example 3:

# Input: n = 15
# Output: 4
# Explanation: 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5


# Constraints:

# 1 <= n <= 10^9

class Solution:
    def consecutiveNumbersSum(self, n: int) -> int:
        res, bound, k = 0, 2 * n, 1
        while k * (k + 1) <= bound:
            def isConsecutive(n: int, k: int) -> bool:
                return n % k == 0 if k % 2 else n % k != 0 and 2 * n % k == 0
            if isConsecutive(n, k):
                res += 1
            k += 1
        return res
