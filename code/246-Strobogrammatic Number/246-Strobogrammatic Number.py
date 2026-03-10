"""
LeetCode 246 - Strobogrammatic Number

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given a string num which represents an integer, return true if num is a strobogrammatic number.

# A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

#

# Example 1:

# Input: num = "69"
# Output: true
# Example 2:

# Input: num = "88"
# Output: true
# Example 3:

# Input: num = "962"
# Output: false
#

# Constraints:

# 1 <= num.length <= 50
# num consists of only digits.
# num does not contain any leading zeros except for zero itself.

class Solution:
    def isStrobogrammatic(self, num: str) -> bool:
        rev = {
            '0': '0',
            '1': '1',
            '2': '#',
            '3': '#',
            '4': '#',
            '5': '#',
            '6': '9',
            '7': '#',
            '8': '8',
            '9': '6'
        }
        i, j = 0, len(num) - 1
        while i <= j:
            if rev[num[i]] == num[j]:
                i += 1
                j -= 1
            else:
                return False
        return True
