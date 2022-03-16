// Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.

 

// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [9,4]
// Explanation: [4,9] is also accepted.
 

// Constraints:

// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 1000



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    int key;
    bool cnt;
    UT_hash_handle hh;
} HashItem;

int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    HashItem *cnt = NULL;
    for (int i = 0; i < nums1Size; i ++) {
        HashItem *pEntry = NULL;
        HASH_FIND_INT(cnt, nums1 + i, pEntry);
        if (pEntry == NULL) {
            pEntry = (HashItem*)malloc(sizeof(HashItem));
            pEntry->key = nums1[i];
            pEntry->cnt = true;
            HASH_ADD_INT(cnt, key, pEntry);
        }
    }
    int* res = (int*)malloc(sizeof(int) * 1001);
    *returnSize = 0;
    for (int i = 0; i < nums2Size; i ++) {
        HashItem *pEntry = NULL;
        HASH_FIND_INT(cnt, nums2 + i, pEntry);
        if (pEntry != NULL) {
            if (pEntry->cnt) {
                res[(*returnSize) ++] = nums2[i];
                pEntry->cnt = false;
            }
        }
    }
    return res;
}