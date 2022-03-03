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