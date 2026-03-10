/*
LeetCode 34 - Find First and Last Position of Element in Sorted Array

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*
Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

If target is not found in the array, return [-1, -1].

Follow up: Could you write an algorithm with O(log n) runtime complexity?
Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
Example 3:

Input: nums = [], target = 0
Output: [-1,-1]


Constraints:

0 <= nums.length <= 105
-109 <= nums[i] <= 109
nums is a non-decreasing array.
-109 <= target <= 109

二分查找第一个target和第一个比target大的数
*/


#include "vector"

using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int target) {
        const int n = nums.size() - 1;
        int left = 0, right = n;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        return left;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int a = binarySearch(nums, target);
        int b = binarySearch(nums, target + 1);
        if (a == nums.size() || nums[a] != target) {
            return vector<int> {-1, -1};
        } else {
            return vector<int> {a, b - 1};
        }
    }
};
