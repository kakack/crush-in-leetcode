/*
LeetCode 215 - Kth Largest Element in an Array

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given an integer array nums and an integer k, return the kth largest element in the array.

// Note that it is the kth largest element in the sorted order, not the kth distinct element.



// Example 1:

// Input: nums = [3,2,1,5,6,4], k = 2
// Output: 5
// Example 2:

// Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
// Output: 4


// Constraints:

// 1 <= k <= nums.length <= 10^4
// -10^4 <= nums[i] <= 10^4



void swap(int* a, int* b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

int findKthLargest(int* nums, int numsSize, int k){
    int n = numsSize, count = 0;
    for (int i = 0; i < n; i ++) {
        int maxIndex = i;
        for (int j = i + 1; j < n; j ++) {
            if (nums[maxIndex] < nums[j]) {
                maxIndex = j;
            }
        }
        count ++;
        if (count == k) {
            return nums[maxIndex];
        } else {
            swap(nums + i, nums + maxIndex);
        }
    }
    return -1;
}
