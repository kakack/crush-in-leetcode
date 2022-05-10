// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]
// Example 3:

// Input: nums = [1]
// Output: [[1]]
 

// Constraints:

// 1 <= nums.length <= 6
// -10 <= nums[i] <= 10
// All the integers of nums are unique.



/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int* nums_;
int numsSize_;
int **res;

void swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void backtrack(int first, int* returnSize, int** returnColumnSizes) {
    if (first == numsSize_) {
        int *tmp = malloc(sizeof(int) * numsSize_);
        memcpy(tmp, nums_, sizeof(int) * numsSize_);
        res[*returnSize] = tmp;
        (*returnColumnSizes)[(*returnSize) ++] = numsSize_;
    } else {
        for (int i = first; i < numsSize_; i ++) {
            swap(&nums_[first], &nums_[i]);
            backtrack(first + 1, returnSize, returnColumnSizes);
            swap(&nums_[first], &nums_[i]);
        }
    }
}

int** permute(int* nums, int numsSize, int* returnSize, int** returnColumnSizes){
    res = malloc(sizeof(int) * numsSize * 8000);
    *returnSize = 0;
    (*returnColumnSizes) = malloc(sizeof(int) * 8000);
    nums_ = malloc(sizeof(int) * numsSize);
    memcpy(nums_, nums, sizeof(int) * numsSize);
    numsSize_ = numsSize;
    backtrack(0, returnSize, returnColumnSizes);
    return res;
}