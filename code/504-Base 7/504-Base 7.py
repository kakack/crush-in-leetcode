"""
LeetCode 504 - Base 7

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given an integer, return its base 7 string representation.
#
# Example 1:
# Input: 100
# Output: "202"
#
# Example 2:
# Input: -7
# Output: "-10"

# Note: The input will be in range of [-1e7, 1e7].

class Solution(object):
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        neg, ans, count = 1, 0, 0
        if num < 0:
            neg = -1
            num = -1 * num
        while num > 0:
            ans += num % 7 * pow(10, count)
            num = int(num / 7)
            count += 1
        return str(neg * ans)

if __name__ == '__main__':
    s = Solution()
    print(s.convertToBase7(100))
    print(s.convertToBase7(-7))


