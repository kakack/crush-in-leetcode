"""
LeetCode 1010 - Pairs of Songs With Total Durations Divisible by 60

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# In a list of songs, the i-th song has a duration of time[i] seconds.

# Return the number of pairs of songs for which their total duration in seconds is divisible by 60.
# Formally, we want the number of indices i < j with (time[i] + time[j]) % 60 == 0.


# Example 1:

# Input: [30,20,150,100,40]
# Output: 3
# Explanation: Three pairs have a total duration divisible by 60:
# (time[0] = 30, time[2] = 150): total duration 180
# (time[1] = 20, time[3] = 100): total duration 120
# (time[1] = 20, time[4] = 40): total duration 60
# Example 2:

# Input: [60,60,60]
# Output: 3
# Explanation: All three pairs have a total duration of 120, which is divisible by 60.


# Note:

# 1 <= time.length <= 60000
# 1 <= time[i] <= 500


class Solution(object):
    def numPairsDivisibleBy60(self, time):
        """
        :type time: List[int]
        :rtype: int
        """
        res = 0
        store = [0] * 60
        for item in time:
            store[item % 60] += 1
        res += int(store[0] * (store[0] - 1) / 2) + int(store[30] * (store[30] - 1) / 2)
        for i in range(1, 30):
            res += store[i] * store[60 - i]
        return res


if __name__ == '__main__':
    s = Solution()
    list_input = [30,20,150,100,40]
    print(s.numPairsDivisibleBy60(list_input))
    list_input = [60, 60, 60]
    print(s.numPairsDivisibleBy60(list_input))


