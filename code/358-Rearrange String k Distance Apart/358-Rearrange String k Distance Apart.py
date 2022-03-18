# Given a string s and an integer k, rearrange s such that the same characters are at least distance k from each other. If it is not possible to rearrange the string, return an empty string "".

#  

# Example 1:

# Input: s = "aabbcc", k = 3
# Output: "abcabc"
# Explanation: The same letters are at least a distance of 3 from each other.
# Example 2:

# Input: s = "aaabc", k = 3
# Output: ""
# Explanation: It is not possible to rearrange the string.
# Example 3:

# Input: s = "aaadbbcc", k = 2
# Output: "abacabcd"
# Explanation: The same letters are at least a distance of 2 from each other.
#  

# Constraints:

# 1 <= s.length <= 3 * 10^5
# s consists of only lowercase English letters.
# 0 <= k <= s.length

class Solution:
    def rearrangeString(self, s: str, k: int) -> str:
        if k == 0:
            return s
        
        chr_freq = collections.Counter(s)
        
        maxHeap = [(-1 * freq, chr) for chr, freq in chr_freq.items()]
        heapq.heapify(maxHeap)
        
        Q = collections.deque()
        res = ""
        while maxHeap:
            freq, c = heapq.heappop(maxHeap)    #要想实现，必须先弹出最大次数的那个
            freq *= -1

            res += c
            Q.append((freq - 1, c))

            if len(Q) == k:             #能够构成一个长度为k的窗口。则后移
                f, c = Q.popleft()
                if f > 0:
                    heapq.heappush(maxHeap, (-1 * f, c))
        
        return res if len(res) == len(s) else ""
