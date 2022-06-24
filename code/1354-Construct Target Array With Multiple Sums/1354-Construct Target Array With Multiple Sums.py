# You are given an array target of n integers. From a starting array arr consisting of n 1's, you may perform the following procedure :

# let x be the sum of all elements currently in your array.
# choose index i, such that 0 <= i < n and set the value of arr at index i to x.
# You may repeat this procedure as many times as needed.
# Return true if it is possible to construct the target array from arr, otherwise, return false.

 

# Example 1:

# Input: target = [9,3,5]
# Output: true
# Explanation: Start with arr = [1, 1, 1] 
# [1, 1, 1], sum = 3 choose index 1
# [1, 3, 1], sum = 5 choose index 2
# [1, 3, 5], sum = 9 choose index 0
# [9, 3, 5] Done
# Example 2:

# Input: target = [1,1,1,2]
# Output: false
# Explanation: Impossible to create target array from [1,1,1,1].
# Example 3:

# Input: target = [8,5]
# Output: true
 

# Constraints:

# n == target.length
# 1 <= n <= 5 * 10^4
# 1 <= target[i] <= 10^9

class Solution:
    def isPossible(self, target: List[int]) -> bool:
        n = len(target)
        maxHeap = []
        tot_sum = 0
        for x in target:
            heapq.heappush(maxHeap, -1 * x)
            tot_sum += x
        while maxHeap[0] != -1:                     #[1, 3, 5] --> [9, 3, 5] --> [17, 3, 5]
            curmax = -1 * heapq.heappop(maxHeap)    #当前最大的是17
            other_sum = tot_sum - curmax            #其他的和为26 - 17 = 8
            
            if other_sum < n -1 :
                return False
            
            t = curmax - other_sum                  #17的位置上一轮是 17 - 8 = 9
            if t < 1:
                return False   
            if other_sum == 0:
                return False
            t %= other_sum                          #[9, 3, 5]下一轮是 [17, 3, 5]

            if t == 0:                              #[10, 1, 1]
                t = other_sum
            heapq.heappush(maxHeap, -1 * t)
            tot_sum = tot_sum - curmax + t

        return True

    