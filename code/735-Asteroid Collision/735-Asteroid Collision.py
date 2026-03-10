"""
LeetCode 735 - Asteroid Collision

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# We are given an array asteroids of integers representing asteroids in a row.

# For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

# Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.



# Example 1:

# Input: asteroids = [5,10,-5]
# Output: [5,10]
# Explanation: The 10 and -5 collide resulting in 10. The 5 and 10 never collide.
# Example 2:

# Input: asteroids = [8,-8]
# Output: []
# Explanation: The 8 and -8 collide exploding each other.
# Example 3:

# Input: asteroids = [10,2,-5]
# Output: [10]
# Explanation: The 2 and -5 collide resulting in -5. The 10 and -5 collide resulting in 10.


# Constraints:

# 2 <= asteroids.length <= 10^4
# -1000 <= asteroids[i] <= 1000
# asteroids[i] != 0

class Solution:
    def asteroidCollision(self, asteroids: List[int]) -> List[int]:
        stk = []
        for aster in asteroids:
            alive = True
            while alive and aster < 0 and stk and stk[-1] > 0:
                alive = stk[-1] < -aster
                if stk[-1] <= -aster:
                    stk.pop()
            if alive:
                stk.append(aster)
        return stk
