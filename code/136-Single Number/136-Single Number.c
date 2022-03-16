// Given a non-empty array of integers nums, every element appears twice except for one. Find that single one.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

//  

// Example 1:

// Input: nums = [2,2,1]
// Output: 1
// Example 2:

// Input: nums = [4,1,2,1,2]
// Output: 4
// Example 3:

// Input: nums = [1]
// Output: 1
//  

// Constraints:

// 1 <= nums.length <= 3 * 104
// -3 * 10^4 <= nums[i] <= 3 * 10^4
// Each element in the array appears twice except for one element which appears only once.

int singleNumber(int* nums, int numsSize){
    int ans = 0;
    for (int i = 0; i < numsSize; i ++) {
        ans = ans ^ nums[i];
    }
    return ans;
}


// UT hash写法

typedef struct {
    int key, count;
    UT_hash_handle hh;
} HashItem;

int singleNumber(int* nums, int numsSize){
    struct HashItem* Index = NULL;
    for (int i = 0; i < numsSize; i ++) {
        struct HashItem* pEntry = NULL;
        HASH_FIND_INT(Index, nums + i, pEntry);
        if (pEntry == NULL) {
            pEntry = (struct HashItem*)malloc(sizeof(struct HashItem));
            pEntry->key = nums[i];
            pEntry->count = 1;
            HASH_ADD_INT(Index, key, pEntry);
        } else {
            pEntry->count ++;
        }
    }

    struct HashItem *iter, *tmp;
    HASH_ITER(hh, Index, iter, tmp) {
        if (iter->count == 1) {
            return iter->key;
        } else {
            HASH_DEL(Index, iter);
            free(iter);
        }
    }
    return 0;
}