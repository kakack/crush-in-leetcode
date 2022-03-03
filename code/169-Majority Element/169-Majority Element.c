// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2
 

// Constraints:

// n == nums.length
// 1 <= n <= 5 * 104
// -231 <= nums[i] <= 231 - 1
 

// Follow-up: Could you solve the problem in linear time and in O(1) space?

struct HashTable {
    int key, val;
    UT_hash_handle hh;
};

int majorityElement(int* nums, int numsSize){
    struct HashTable *hashTable = NULL;
    for (int i = 0; i < numsSize; i ++) {
        struct HashTable *tmp;
        HASH_FIND_INT(hashTable, &nums[i], tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(struct HashTable));
            tmp->key = nums[i];
            tmp->val = 1;
            HASH_ADD_INT(hashTable, key, tmp);
        } else {
            tmp->val ++;
        }
    }
    int ans = 0;
    struct HashTable *iter, *tmp;
    HASH_ITER(hh, hashTable, iter, tmp) {
        if (iter->val > numsSize / 2) {
            ans = iter->key;
            break;
        }
    }
    return ans;
}

int cmp(int* a, int* b) {
    return *a - *b;
}

int majorityElement(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    return nums[numsSize / 2];
}