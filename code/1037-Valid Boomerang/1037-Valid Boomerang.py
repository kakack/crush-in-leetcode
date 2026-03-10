# -*- coding: utf-8 -*
"""
LeetCode 1037 - Valid Boomerang

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
r"""
@author: Kai Chen
@file: 1037-Valid Boomerang.py
@time: 2020/6/22 10:37
@desc:

A boomerang is a set of 3 points that are all distinct and not in a straight line.

Given a list of three points in the plane, return whether these points are a boomerang.



Example 1:

Input: [[1,1],[2,3],[3,2]]
Output: true
Example 2:

Input: [[1,1],[2,2],[3,3]]
Output: false


Note:

points.length == 3
points[i].length == 2
0 <= points[i][j] <= 100

"""

class Solution(object):
    def isBoomerang(self, points):
        """
        :type points: List[List[int]]
        :rtype: bool
        """
        vector_1, vector_2 = [points[1][0] - points[0][0], points[1][1] - points[0][1]], [points[2][0] - points[1][0], points[2][1] - points[1][1]]
        if pow(vector_1[0] * vector_2[0] + vector_1[1] * vector_2[1], 2) == (pow(vector_1[0], 2) + pow(vector_1[1], 2)) * (pow(vector_2[0], 2) + pow(vector_2[1], 2)):
            return False
        else:
            return True

if __name__ == '__main__':
    s = Solution()
    print(s.isBoomerang([[1,1],[2,3],[3,2]]))
