# -*- coding: utf-8 -*
"""
@author: Kai Chen
@file: 347-Top K Frequent Elements.py
@time: 2020/9/7 9:16
@desc:
Given a non-empty array of integers, return the k most frequent elements.

Example 1:

Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]
Example 2:

Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
"""

import heapq
import collections


class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        Hash + Heap
        """
        dic = collections.Counter(nums)
        heap, result = [], []
        for i in dic:
            heapq.heappush(heap, (-dic[i], i))
        print(heap)
        for _ in range(k):
            result.append(heapq.heappop(heap)[1])
        return result


if __name__ == '__main__':
    s = Solution()
    ipt = [1, 1, 1, 2, 2, 3, 4, 4, 4, 5, 5, 6, 6, 6, 6, 6, 6, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 1, 1, 1, 1, 2, 2,
           18]
    print(s.topKFrequent(ipt, 3))
