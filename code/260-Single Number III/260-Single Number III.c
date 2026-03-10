/*
LeetCode 260 - Single Number III

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given an integer array nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once. You can return the answer in any order.

// You must write an algorithm that runs in linear runtime complexity and uses only constant extra space.



// Example 1:

// Input: nums = [1,2,1,3,2,5]
// Output: [3,5]
// Explanation:  [5, 3] is also a valid answer.
// Example 2:

// Input: nums = [-1,0]
// Output: [-1,0]
// Example 3:

// Input: nums = [0,1]
// Output: [1,0]


// Constraints:

// 2 <= nums.length <= 3 * 10^4
// -2^31 <= nums[i] <= 2^31 - 1
// Each integer in nums will appear twice, only two integers will appear once.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* singleNumber(int* nums, int numsSize, int* returnSize){
    *returnSize = 2;
    int* res = malloc(sizeof(int) * 2);
    int xorSum = 0;
    for (int i = 0; i < numsSize; i ++) {
        xorSum ^= nums[i];
    }
    int l = (xorSum == INT_MIN ? xorSum : xorSum & (-xorSum));
    int ty1 = 0;
    for (int i = 0; i < numsSize; i ++) {
        if (nums[i] & l) {
            ty1 ^= nums[i];
        }
    }
    res[0] = ty1;
    res[1] = xorSum ^ ty1;
    return res;
}
