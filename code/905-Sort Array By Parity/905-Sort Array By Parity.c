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