// Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

// Example 1:

// Input: nums = [1,2,3,1], k = 3
// Output: true
// Example 2:

// Input: nums = [1,0,1,1], k = 1
// Output: true
// Example 3:

// Input: nums = [1,2,3,1,2,3], k = 2
// Output: false
 

// Constraints:

// 1 <= nums.length <= 10^5
// -10^9 <= nums[i] <= 10^9
// 0 <= k <= 10^5

typedef struct {
    int key;
    int idx;
    UT_hash_handle hh;
} HashItem;

bool containsNearbyDuplicate(int* nums, int numsSize, int k){
    int minDiff = INT_MAX;
    HashItem *numMap = NULL;
    for (int i = 0; i < numsSize; i ++) {
        HashItem *curr = NULL;
        HASH_FIND_INT(numMap, nums + i, curr);
        if (curr == NULL) {
            curr = (HashItem*)malloc(sizeof(HashItem));
            curr->key = nums[i];
            curr->idx = i;
            HASH_ADD_INT(numMap, key, curr);
        } else {
            int diff = fabs(i - curr->idx);
            if (diff <= k) {
                return true;
            }
            curr->idx = i;
        }
    }
    return false;
}