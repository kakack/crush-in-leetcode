// Given an array nums of n integers, return an array of all the unique quadruplets [nums[a], nums[b], nums[c], nums[d]] such that:

// 0 <= a, b, c, d < n
// a, b, c, and d are distinct.
// nums[a] + nums[b] + nums[c] + nums[d] == target
// You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,0,-1,0,-2,2], target = 0
// Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
// Example 2:

// Input: nums = [2,2,2,2,2], target = 8
// Output: [[2,2,2,2]]
 

// Constraints:

// 1 <= nums.length <= 200
// -10^9 <= nums[i] <= 10^9
// -10^9 <= target <= 10^9



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(int *a, int *b) {
    return *a - *b;
}

int** fourSum(int* nums, int numsSize, int target, int* returnSize, int** returnColumnSizes){
    int **res = (int**)malloc(sizeof(int*) * numsSize * numsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * numsSize * numsSize);
    *returnSize = 0;
    if (numsSize < 4) {
        return res;
    }
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize - 3; i ++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        if ((long) nums[i] + nums[i + 1] + nums[i + 2] + nums[i + 3] > target) {
            break;
        }
        if ((long) nums[i] + nums[numsSize - 1] + nums[numsSize - 2] + nums[numsSize - 3] < target) {
            continue;
        }
        for (int j = i + 1; j < numsSize - 2; j ++) {
            if (j > i + 1 && nums[j] == nums[j - 1]) {
                continue;
            }
            if ((long) nums[i] + nums[j] + nums[j + 1] + nums[j + 2] > target) {
                break;
            }
            if ((long) nums[i] + nums[j] + nums[numsSize - 2] + nums[numsSize - 1] < target) {
                continue;
            }
            int left = j + 1, right = numsSize - 1;
            while (left < right) {
                int sum = sum = nums[i] + nums[j] + nums[left] + nums[right];
                if (sum == target) {
                    res[*returnSize] = malloc(sizeof(int) * 4);
                    res[*returnSize][0] = nums[i];
                    res[*returnSize][1] = nums[j];
                    res[*returnSize][2] = nums[left];
                    res[*returnSize][3] = nums[right];
                    (*returnColumnSizes)[*returnSize] = 4;
                    (*returnSize) ++;
                    while (left < right && nums[left] == nums[++ left]);
                    while (left < right && nums[right] == nums[-- right]);
                } else if (sum < target) {
                    left ++;
                } else {
                    right --;
                }
            }
        }
    }
    return res;
}