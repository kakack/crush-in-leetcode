/*
LeetCode 912 - Sort an Array

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given an array of integers nums, sort the array in ascending order.



// Example 1:

// Input: nums = [5,2,3,1]
// Output: [1,2,3,5]
// Example 2:

// Input: nums = [5,1,1,2,0,0]
// Output: [0,0,1,1,2,5]


// Constraints:

// 1 <= nums.length <= 5 * 10^4
// -5 * 10^4 <= nums[i] <= 5 * 10^4



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

int cmp(int* a, int* b) {
    return *a - *b;
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums;
}

 void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

// 二元选择排序

void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    for (int i = 0; i < numsSize / 2; i ++) {
        int minIndex = i, maxIndex = i;
        for (int j = i + 1; j < numsSize - i; j ++) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
            if (nums[j] > nums[maxIndex]) {
                maxIndex = j;
            }
        }
        if (minIndex == maxIndex) {
            break;
        }
        swap(nums + i, nums + minIndex);
        if (maxIndex == i) {
            maxIndex = minIndex;
        }
        swap(nums + numsSize - 1, nums + maxIndex);
    }
    return nums;
}

// 普通选择排序
int* sortArray(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    for (int i = 0; i < numsSize; i ++) {
        int minIndex = i;
        for (int j = i + 1; j < numsSize; j ++) {
            if (nums[j] < nums[minIndex]) {
                minIndex = j;
            }
        }
        swap(nums + i, nums + minIndex);
    }
    return nums;
}
