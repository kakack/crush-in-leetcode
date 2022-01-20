/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.



Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99


Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.


Follow up: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

int singleNumber(int* nums, int numsSize){
    int once = 0, twice = 0;
    for (int i = 0; i < numsSize; i++) {
        once = ~twice & (once ^ nums[i]);
        twice = ~once & (twice ^ nums[i]);
    }
    return once;
}


struct HashTable {
    int key, val;
    UT_hash_handle hh;
};

int singleNumber(int* nums, int numsSize){
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
        if (iter->val == 1) {
            ans = iter->key;
            break;
        }
    }
    return ans;
}

