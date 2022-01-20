# Given a non-empty array of integers, every element appears twice except for one. Find that single one.
#
# Note:
# Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
#
# Example 1:
# Input: [2,2,1]
# Output: 1
#
# Example 2:
# Input: [4,1,2,1,2]
# Output: 4

class Solution(object):
    def singleNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        ans = 0
        for num in nums:
            ans ^= num
        return ans

    # def singleNumber(self, nums):
    #     """
    #     :type nums: List[int]
    #     :rtype: int
    #     """
    #     hashMap = {}
    #     for item in nums:
    #         if hashMap.get(item) is None:
    #             hashMap[item] = 1
    #         else:
    #             hashMap[item] = 2
    #     for item in hashMap.keys():
    #         if hashMap[item] == 1:
    #             return item

# class Solution(object):
#     def singleNumber(self, nums):
#         """
#         :type nums: List[int]
#         :rtype: int
#         """
#         return 2 * sum(set(nums)) - sum(nums)

if __name__ == '__main__':
    s = Solution()
    print(s.singleNumber([4,1,2,1,2]))