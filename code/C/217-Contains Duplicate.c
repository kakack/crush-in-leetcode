/*
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
*/

// 排序

int cmp(int *a, int *b) {
    return *a - *b;
}

bool containsDuplicate(int* nums, int numsSize){
    qsort(nums, numsSize, sizeof(int), cmp);
    for (int i = 0; i < numsSize - 1; i ++) {
        if (nums[i] == nums[i + 1]) {
            return true;
        }
    }
    return false;
}

// 用C写hash表

struct hashTable {
    int key;
    UT_hash_handle hh;
};

bool containsDuplicate(int* nums, int numsSize){
    struct hashTable* set = NULL;
    for (int i = 0; i < numsSize; i ++) {
        struct hashTable* tmp;
        HASH_FIND_INT(set, nums + i, tmp);
        if (tmp == NULL) {
            tmp = malloc(sizeof(struct hashTable));
            tmp->key = nums[i];
            HASH_ADD_INT(set, key, tmp);
        } else {
            return true;
        }
    }
    return false;
}
