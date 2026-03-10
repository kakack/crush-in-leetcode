"""
LeetCode 498 - Diagonal Traverse

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given an m x n matrix mat, return an array of all the elements of the array in a diagonal order.



# Example 1:


# Input: mat = [[1,2,3],[4,5,6],[7,8,9]]
# Output: [1,2,4,7,5,3,6,8,9]
# Example 2:

# Input: mat = [[1,2],[3,4]]
# Output: [1,2,3,4]


# Constraints:

# m == mat.length
# n == mat[i].length
# 1 <= m, n <= 10^4
# 1 <= m * n <= 10^4
# -10^5 <= mat[i][j] <= 10^5


class Solution:
    def findDiagonalOrder(self, mat: List[List[int]]) -> List[int]:
        row, col, i, j = len(mat), len(mat[0]), 0, 0
        up = True
        res = []
        while i < row and j < col:
            res.append(mat[i][j])
            if up:
                i, j = i - 1, j + 1
                if j >= col:
                    up = not up
                    i, j  = i + 2, j - 1
                elif i < 0:
                    up = not up
                    i = i + 1
            else:
                i, j = i + 1, j - 1
                if i >= row:
                    up = not up
                    i, j = i - 1, j + 2
                elif j < 0:
                    up = not up
                    j += 1
        return res
