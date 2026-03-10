"""
LeetCode 1344 - Angle Between Hands of a Clock

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given two numbers, hour and minutes. Return the smaller angle (in sexagesimal units) formed between the hour and the minute hand.

# Example 1:
# Input: hour = 12, minutes = 30
# Output: 165

# Example 2:
# Input: hour = 3, minutes = 30
# Output: 75

# Example 3:
# Input: hour = 3, minutes = 15
# Output: 7.5

# Example 4:
# Input: hour = 4, minutes = 50
# Output: 155

# Example 5:
# Input: hour = 12, minutes = 0
# Output: 0


# Constraints:

# 1 <= hour <= 12
# 0 <= minutes <= 59
# Answers within 10^-5 of the actual value will be accepted as correct.

class Solution(object):
    def angleClock(self, hour, minutes):
        """
        :type hour: int
        :type minutes: int
        :rtype: float
        """
        angleHour = 30.0 * hour + minutes / 2.0
        angleMin = 6.0 * minutes
        res = max(angleHour, angleMin)  - min(angleHour, angleMin)
        return res if res >= 0 and res <= 180 else 360 - res
