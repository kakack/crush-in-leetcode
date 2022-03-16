// Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

// You may assume that each input would have exactly one solution, and you may not use the same element twice.

// You can return the answer in any order.

 

// Example 1:

// Input: nums = [2,7,11,15], target = 9
// Output: [0,1]
// Output: Because nums[0] + nums[1] == 9, we return [0, 1].
// Example 2:

// Input: nums = [3,2,4], target = 6
// Output: [ß1,2]
// Example 3:

// Input: nums = [3,3], target = 6
// Output: [0,1]
 

// Constraints:

// 2 <= nums.length <= 104
// -109 <= nums[i] <= 109
// -109 <= target <= 109
// Only one valid answer exists.



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    *returnSize = 2;
    for (int i = 0; i < numsSize - 1; i ++) {
        for(int j = i + 1; j < numsSize; j ++) {
            if (nums[j] == target - nums[i]) {
                nums[0] = i;
                nums[1] = j;
                return nums;
            }
        }
    }
    return NULL;
}

// 哈希表写法

typedef struct {
    int key;
    int index;
    UT_hash_handle hh;
} HashItem;

int* twoSum(int* nums, int numsSize, int target, int* returnSize){
    HashItem *numMap = NULL;
    int *res = (int*)malloc(sizeof(int) * 2);
    for (int i = 0; i < numsSize; i ++) {
        HashItem *pEntry = NULL;
        int diff = target - nums[i];
        HASH_FIND_INT(numMap, &diff, pEntry);
        if (pEntry != NULL) {
            res[0] = pEntry->index;
            res[1] = i;
            break;
        } else {
            pEntry = (HashItem*)malloc(sizeof(HashItem));
            pEntry->key = nums[i];
            pEntry->index = i;
            HASH_ADD_INT(numMap, key, pEntry);
        }
    }
    *returnSize = 2;
    return res;
}