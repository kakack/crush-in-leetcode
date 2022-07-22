# An integer interval [a, b] (for integers a < b) is a set of all consecutive integers from a to b, including a and b.

# Find the minimum size of a set S such that for every integer interval A in intervals, the intersection of S with A has a size of at least two.

 

# Example 1:

# Input: intervals = [[1,3],[1,4],[2,5],[3,5]]
# Output: 3
# Explanation: Consider the set S = {2, 3, 4}.  For each interval, there are at least 2 elements from S in the interval.
# Also, there isn't a smaller size set that fulfills the above condition.
# Thus, we output the size of this set, which is 3.
# Example 2:

# Input: intervals = [[1,2],[2,3],[2,4],[4,5]]
# Output: 5
# Explanation: An example of a minimum sized set is {1, 2, 3, 4, 5}.
 

# Constraints:

# 1 <= intervals.length <= 3000
# intervals[i].length == 2
# 0 <= ai < bi <= 10^8

class Solution:
    def intersectionSizeTwo(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))
        ans, n, m = 0, len(intervals), 2
        vals = [[] for _ in range(n)]
        for i in range(n - 1, -1, -1):
            j = intervals[i][0]
            for k in range(len(vals[i]), m):
                ans += 1
                for p in range(i - 1, -1, -1):
                    if intervals[p][1] < j:
                        break
                    vals[p].append(j)
                j += 1
        return ans
