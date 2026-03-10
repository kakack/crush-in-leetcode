"""
LeetCode 1 - Two Sum

解题步骤（自动整理）
1. 使用哈希表记录已遍历元素（或频次/索引）以支持 O(1) 查询
2. 遍历输入并在哈希表中查找所需互补/状态，命中时更新答案
3. 遍历结束后返回答案或默认值
"""
# Given an array of integers, return indices of the two numbers such that they add up to a specific target.

# You may assume that each input would have exactly one solution, and you may not use the same element twice.

# Example:
# Given nums = [2, 7, 11, 15], target = 9,

# Because nums[0] + nums[1] = 2 + 7 = 9,
# return [0, 1].


# class Solution(object):
#     def twoSum(self, nums, target):
#         """
#         :type nums: List[int]
#         :type target: int
#         :rtype: List[int]
#         """
#         length=len(nums)
#         for i in range(0, length):
#             for j in range(i+1, length):
#                 if nums[i]+nums[j]==target:
#                     return i, j
#                 else:
#                     continue

class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        hashmap = {}
        for i, num in enumerate(nums):
            hashmap[num] = i

        for i, num in enumerate(nums):
            j = hashmap.get(target - num)
            if j and i != j:
                return [i, j]

# if __name__ == '__main__':
#     nums = [2, 7, 11, 15]
#     target = 9
#     s = Solution()
#     print(s.twoSum(nums, target))
