# We want to split a group of n people (labeled from 1 to n) into two groups of any size. Each person may dislike some other people, and they should not go into the same group.

# Given the integer n and the array dislikes where dislikes[i] = [ai, bi] indicates that the person labeled ai does not like the person labeled bi, return true if it is possible to split everyone into two groups in this way.

 

# Example 1:

# Input: n = 4, dislikes = [[1,2],[1,3],[2,4]]
# Output: true
# Explanation: group1 [1,4] and group2 [2,3].
# Example 2:

# Input: n = 3, dislikes = [[1,2],[1,3],[2,3]]
# Output: false
# Example 3:

# Input: n = 5, dislikes = [[1,2],[2,3],[3,4],[4,5],[1,5]]
# Output: false
 

# Constraints:

# 1 <= n <= 2000
# 0 <= dislikes.length <= 10^4
# dislikes[i].length == 2
# 1 <= dislikes[i][j] <= n
# ai < bi
# All the pairs of dislikes are unique.

class Solution:
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        mp = collections.defaultdict(list)
        for i in range(len(dislikes)):
            mp[dislikes[i][0] - 1].append(dislikes[i][1] - 1)
            mp[dislikes[i][1] - 1].append(dislikes[i][0] - 1)
        visited = [0 for _ in range(n)]
        def dfs(visited, id, color):
            if visited[id]:
                return visited[id] == color
            visited[id] = color
            for c in mp[id]:
                if not dfs(visited, c, -color):
                    return False
            return True
        for i in range(n):
            if visited[i] == 0 and not dfs(visited, i, 1):
                return False
        return True
    
class Solution:
    # bfs
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        mp = collections.defaultdict(list)
        for i in range(len(dislikes)):
            mp[dislikes[i][0] - 1].append(dislikes[i][1] - 1)
            mp[dislikes[i][1] - 1].append(dislikes[i][0] - 1)
        visited = [0 for _ in range(n)]
        qu = list()
        for i in range(n):
            if visited[i]:
                continue
            qu.append(i)
            visited[i] = 1
            while len(qu) > 0:
                m = len(qu)
                for j in range(m):
                    id = qu.pop(0)
                    for c in mp[id]:
                        if visited[c] == visited[id]:
                            return False
                        if visited[c] == 0:
                            visited[c] = -visited[id]
                            qu.append(c)
        return True
    
class UnionFound:
    F = list()
    def __init__(self, n: int):
        self.F = [0 for _ in range(n)]
        for i in range(n):
            self.F[i] = i

    def Find(self, x: int) -> int:
        if self.F[x] == x:
            return x
        self.F[x] = self.Find(self.F[x])
        return self.F[x]

    def Union(self, x: int, y: int):
        x = self.Find(x)
        y = self.Find(y)
        if x != y:
            self.F[x] = y
        

class Solution:
    # 并查集
    def possibleBipartition(self, n: int, dislikes: List[List[int]]) -> bool:
        mp = collections.defaultdict(list)
        for i in range(len(dislikes)):
            mp[dislikes[i][0] - 1].append(dislikes[i][1] - 1)
            mp[dislikes[i][1] - 1].append(dislikes[i][0] - 1)
        uf = UnionFound(n)
        for i in range(n):
            for c in mp[i]:
                if uf.Find(i) == uf.Find(c):
                    return False
                uf.Union(mp[i][0], c)
        return True