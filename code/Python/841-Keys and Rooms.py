# -*- coding: utf-8 -*
"""
@author: Kai Chen
@file: 841-Keys and Rooms.py
@time: 2020/8/31 9:54
@desc:
There are N rooms and you start in room 0.
Each room has a distinct number in 0, 1, 2, ..., N-1, and each room may have some keys to access the next room.

Formally, each room i has a list of keys rooms[i],
and each key rooms[i][j] is an integer in [0, 1, ..., N-1] where N = rooms.length.
A key rooms[i][j] = v opens the room with number v.

Initially, all the rooms start locked (except for room 0).

You can walk back and forth between rooms freely.

Return true if and only if you can enter every room.

Example 1:

Input: [[1],[2],[3],[]]
Output: true
Explanation:
We start in room 0, and pick up key 1.
We then go to room 1, and pick up key 2.
We then go to room 2, and pick up key 3.
We then go to room 3.  Since we were able to go to every room, we return true.
Example 2:

Input: [[1,3],[3,0,1],[2],[0]]
Output: false
Explanation: We can't enter the room with number 2.
Note:

1 <= rooms.length <= 1000
0 <= rooms[i].length <= 1000
The number of keys in all rooms combined is at most 3000.
Accepted

"""

from collections import deque

# bfs
# class Solution(object):
#     def canVisitAllRooms(self, rooms):
#         """
#         :type rooms: List[List[int]]
#         :rtype: bool
#         """
#         n = len(rooms)
#         visited = [0 for _ in range(n)]
#         visited[0] = 1
#         stack = deque([0])
#         while stack:
#             room_idx = stack.popleft()
#             visited[room_idx] = 1
#             for key in rooms[room_idx]:
#                 if not visited[key]:
#                     stack.append(key)
#         return False if 0 in visited else True


# dfs
class Solution(object):
    def canVisitAllRooms(self, rooms):
        """
        :type rooms: List[List[int]]
        :rtype: bool
        """
        n = len(rooms)
        visited = set([0])

        def dfs(room):
            visited.add(room)
            for key in rooms[room]:
                if key not in visited:
                    dfs(key)

        dfs(0)
        return len(visited) == n

            

if __name__ == '__main__':
    s = Solution()
    ipts = [
        [[1], [2], [3], []],
        [[2], [], [1]],
        [[1, 3], [3, 0, 1], [2], [0]]
    ]
    for ipt in ipts:
        print(s.canVisitAllRooms(ipt))
