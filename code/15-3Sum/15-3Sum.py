# Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
#
# Note:
#
# The solution set must not contain duplicate triplets.
#
# Example:
#
# Given array nums = [-1, 0, 1, 2, -1, -4],
#
# A solution set is:
# [
#   [-1, 0, 1],
#   [-1, -1, 2]
# ]

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        n = len(nums)
        if n < 3:
            return []
        nums.sort()
        res = list()
        for i in range(n - 2):
            if nums[i] > 0:
                return res
            if (i > 0 and nums[i] == nums[i - 1]):
                continue
            j, k = i + 1, n - 1
            while j < k:
                sum = nums[i] + nums[j] + nums[k]
                if sum == 0:
                    res.append([nums[i], nums[j], nums[k]])
                    while j < k and nums[j] == nums[j + 1]:
                        j += 1
                    j += 1
                    while j < k and nums[k] == nums[k - 1]:
                        k -= 1
                    k -= 1
                elif sum > 0:
                    k -= 1
                else :
                    j += 1
        return res

class Solution(object):
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """

        n = len(nums)
        if n < 3:
            return []
        nums.sort()
        result = []
        for i in range(n):
            if nums[i] > 0:
                return result
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            L = i + 1
            R = n - 1
            while L < R:
                if nums[i] + nums[L] + nums[R] == 0:
                    result.append([nums[i], nums[L], nums[R]])
                    while L < R and nums[L] == nums[L + 1]:
                        L += 1
                    while L < R and nums[R] == nums[R - 1]:
                        R -= 1
                    L = L + 1
                    R = R - 1
                elif nums[i] + nums[L] + nums[R] > 0:
                    R = R - 1
                else:
                    L = L + 1
        return result

if __name__ == '__main__':
    s = Solution()
    nums = [-1,0,1,2,-1,-4]
    print(s.threeSum(nums))