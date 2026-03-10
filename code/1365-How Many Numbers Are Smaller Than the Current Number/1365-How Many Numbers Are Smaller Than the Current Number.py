# -*- coding: utf-8 -*
"""
LeetCode 1365 - How Many Numbers Are Smaller Than the Current Number

解题步骤（自动整理）
1. 使用哈希表记录已遍历元素（或频次/索引）以支持 O(1) 查询
2. 遍历输入并在哈希表中查找所需互补/状态，命中时更新答案
3. 遍历结束后返回答案或默认值
"""
r"""
@author: Kai Chen
@file: 1365-How Many Numbers Are Smaller Than the Current Number.py
@time: 2020/9/8 10:38
@desc:
Given the array nums, for each nums[i] find out how many numbers in the array are smaller than it. That is, for each nums[i] you have to count the number of valid j's such that j != i and nums[j] < nums[i].

Return the answer in an array.



Example 1:

Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation:
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3).
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1).
For nums[3]=2 there exist one smaller number than it (1).
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).
Example 2:

Input: nums = [6,5,4,8]
Output: [2,1,0,3]
Example 3:

Input: nums = [7,7,7,7]
Output: [0,0,0,0]


Constraints:

2 <= nums.length <= 500
0 <= nums[i] <= 100
"""

import collections


class Solution(object):
    def smallerNumbersThanCurrent(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """
        dic = collections.Counter(nums)
        result = []
        for num in nums:
            result.append(sum(dic[i] for i in range(num)))
        return result


if __name__ == '__main__':
    s = Solution()
    ipt = [8, 1, 2, 2, 3]
    print(s.smallerNumbersThanCurrent(ipt))
