/*
LeetCode 724 - Find Pivot Index

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given an array of integers nums, calculate the pivot index of this array.

// The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

// If the index is on the left edge of the array, then the left sum is 0 because there are no elements to the left. This also applies to the right edge of the array.

// Return the leftmost pivot index. If no such index exists, return -1.



// Example 1:

// Input: nums = [1,7,3,6,5,6]
// Output: 3
// Explanation:
// The pivot index is 3.
// Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
// Right sum = nums[4] + nums[5] = 5 + 6 = 11
// Example 2:

// Input: nums = [1,2,3]
// Output: -1
// Explanation:
// There is no index that satisfies the conditions in the problem statement.
// Example 3:

// Input: nums = [2,1,-1]
// Output: 0
// Explanation:
// The pivot index is 0.
// Left sum = 0 (no elements to the left of index 0)
// Right sum = nums[1] + nums[2] = 1 + -1 = 0


// Constraints:

// 1 <= nums.length <= 10^4
// -1000 <= nums[i] <= 1000


// Note: This question is the same as 1991: https://leetcode.com/problems/find-the-middle-index-in-array/

int pivotIndex(int* nums, int numsSize){
    int sum = 0, sumL = 0;
    for (int i = 0; i < numsSize; i ++) {
        sum += nums[i];
    }
    for (int i = 0; i < numsSize; i ++) {
        if (sumL * 2 == sum - nums[i]) {
            return  i;
        }
        sumL += nums[i];
    }
    return  -1;
}
