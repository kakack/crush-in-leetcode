"""
LeetCode 217 - Contains Duplicate

解题步骤（自动整理）
1. 使用哈希表记录已遍历元素（或频次/索引）以支持 O(1) 查询
2. 遍历输入并在哈希表中查找所需互补/状态，命中时更新答案
3. 遍历结束后返回答案或默认值
"""
# Given an array of integers, find if the array contains any duplicates.
#
# Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.
#
# Example 1:
# Input: [1,2,3,1]
# Output: true
#
# Example 2:
# Input: [1,2,3,4]
# Output: false
#
# Example 3:
# Input: [1,1,1,3,3,4,3,2,4,2]
# Output: true

class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        hashMap = {}
        for item in nums:
            if hashMap.get(item):
                return True
            else:
                hashMap[item] = 1
        return False

if __name__ == '__main__':
    s = Solution()
    print(s.containsDuplicate([1,2,3,1]))
