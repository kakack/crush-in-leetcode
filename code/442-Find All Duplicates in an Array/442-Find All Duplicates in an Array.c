// Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears once or twice, return an array of all the integers that appears twice.

// You must write an algorithm that runs in O(n) time and uses only constant extra space.

 

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [2,3]
// Example 2:

// Input: nums = [1,1,2]
// Output: [1]
// Example 3:

// Input: nums = [1]
// Output: []
 

// Constraints:

// n == nums.length
// 1 <= n <= 10^5
// 1 <= nums[i] <= n
// Each element in nums appears once or twice.



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findDuplicates(int* nums, int numsSize, int* returnSize){
    int *res = (int*)malloc(sizeof(int) * numsSize / 2);
    *returnSize = 0;
    for (int i = 0; i < numsSize; i++) {
        int idx = fabs(nums[i]) - 1;
        if (nums[idx] > 0) {
            nums[idx] *= -1;
        } else {
            res[(*returnSize) ++] = idx + 1;
        }
    }
    return res;
}