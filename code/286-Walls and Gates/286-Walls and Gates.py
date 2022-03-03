# You are given an m x n grid rooms initialized with these three possible values.

# -1 A wall or an obstacle.
# 0 A gate.
# INF Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
# Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.

#  

# Example 1:


# Input: rooms = [[2147483647,-1,0,2147483647],[2147483647,2147483647,2147483647,-1],[2147483647,-1,2147483647,-1],[0,-1,2147483647,2147483647]]
# Output: [[3,-1,0,1],[2,2,1,-1],[1,-1,2,-1],[0,-1,3,4]]
# Example 2:

# Input: rooms = [[-1]]
# Output: [[-1]]
#  

# Constraints:

# m == rooms.length
# n == rooms[i].length
# 1 <= m, n <= 250
# rooms[i][j] is -1, 0, or 2^31 - 1.

class Solution:
    def wallsAndGates(self, rooms: List[List[int]]) -> None:
        """
        Do not return anything, modify rooms in-place instead.
        """
        WALL, DOOR, INF = -1, 0, 2147483647
        dirs = [(0, 1), (0, -1), (1, 0), (-1, 0)]
        m, n = len(rooms), len(rooms[0])
        queue = []
        for i in range(m):
            for j in range(n):
                if rooms[i][j] == DOOR:
                    queue.append((i, j))
        while len(queue) > 0:
            row, col = queue.pop(0)
            for dir in dirs:
                newRow = row + dir[0]
                newCol = col + dir[1]
                if newRow < 0 or newRow >= m or newCol < 0 or newCol >= n or rooms[newRow][newCol] != INF:
                    continue
                rooms[newRow][newCol] = rooms[row][col] + 1
                queue.append((newRow, newCol))