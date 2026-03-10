/*
LeetCode 283 - Move Zeroes

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.



// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]


// Constraints:

// 1 <= nums.length <= 10^4
// -2^31 <= nums[i] <= 2^31 - 1


// Follow up: Could you minimize the total number of operations done?

void swap(int *a, int *b) {
    int t = *a;
    *a = *b, *b = t;
}
// 左指针左边均为非零数；

// 右指针左边直到左指针处均为零。
void moveZeroes(int* nums, int numsSize){
    int n = numsSize, left = 0, right = 0;
    while (right < n) {
        if (nums[right]) {
            swap(nums + left, nums + right);
            left++;
        }
        right++;
    }
}
