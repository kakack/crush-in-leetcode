"""
LeetCode 42 - Trapping Rain Water

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
#
#
# The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
#
# Example:
#
# Input: [0,1,0,2,1,0,1,3,2,1,2,1]
# Output: 6



class Solution(object):
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        maxPillar = height.index(max(height))
        res, peakLeft, peakRight = 0, 0, len(height) - 1
        for i in range(maxPillar):
            if height[i] > height[peakLeft]:
                peakLeft = i
            else:
                res += height[peakLeft] - height[i]
        for i in range(len(height) - 1, maxPillar, -1):
            if height[i] > height[peakRight]:
                peakRight = i
            else:
                res += height[peakRight] - height[i]
        return res

if __name__ == '__main__':
    s = Solution()
    print(s.trap([0,1,0,2,1,0,1,3,2,1,2,1]))
