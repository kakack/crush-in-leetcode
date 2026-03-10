"""
LeetCode 119 - Pascal's Triangle II

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given a non-negative index k where k ≤ 33, return the kth index row of the Pascal's triangle.
#
# Note that the row index starts from 0.
#
#
# In Pascal's triangle, each number is the sum of the two numbers directly above it.
#
# Example:
#
# Input: 3
# Output: [1,3,3,1]

class Solution(object):
    def getRow(self, rowIndex):
        """
        :type rowIndex: int
        :rtype: List[int]
        """
        ans = []
        cur = 1
        ans.append(cur)
        for i in range(1,rowIndex + 1):
            cur = int(cur * (rowIndex - i + 1)/i)
            ans.append(cur)
        return ans

if __name__ == '__main__':
    s = Solution()
    print(s.getRow(3))

