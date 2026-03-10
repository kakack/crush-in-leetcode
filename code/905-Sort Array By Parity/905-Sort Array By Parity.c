/*
LeetCode 905 - Sort Array By Parity

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given an integer array nums, move all the even integers at the beginning of the array followed by all the odd integers.

// Return any array that satisfies this condition.



// Example 1:

// Input: nums = [3,1,2,4]
// Output: [2,4,3,1]
// Explanation: The outputs [4,2,3,1], [2,4,1,3], and [4,2,1,3] would also be accepted.
// Example 2:

// Input: nums = [0]
// Output: [0]


// Constraints:

// 1 <= nums.length <= 5000
// 0 <= nums[i] <= 5000




/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int* sortArrayByParity(int* nums, int numsSize, int* returnSize){
    int l = 0, r = numsSize - 1;
    while (l < r) {
        while (nums[l] % 2 == 0) {
            l ++;
        }
        while (nums[r] % 2 == 1) {
            r --;
        }
        swap(&nums[l ++], &nums[r --]);
    }
    *returnSize = numsSize;
    return nums;
}
