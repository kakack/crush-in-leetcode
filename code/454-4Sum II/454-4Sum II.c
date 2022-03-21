/*
Given four lists A, B, C, D of integer values, compute how many tuples (i, j, k, l) there are such that A[i] + B[j] + C[k] + D[l] is zero.

To make problem a bit easier, all A, B, C, D have same length of N where 0 ≤ N ≤ 500. All integers are in the range of -228 to 228 - 1 and the result is guaranteed to be at most 231 - 1.

Example:

Input:
A = [ 1, 2]
B = [-2,-1]
C = [-1, 2]
D = [ 0, 2]

Output:
2

Explanation:
The two tuples are:
1. (0, 0, 0, 1) -> A[0] + B[0] + C[0] + D[1] = 1 + (-2) + (-1) + 2 = 0
2. (1, 1, 0, 0) -> A[1] + B[1] + C[0] + D[0] = 2 + (-1) + (-1) + 0 = 0
*/

typedef struct  {
    int key;
    int cnt;
    UT_hash_handle hh;
} HashItem;



int fourSumCount(int* nums1, int nums1Size, int* nums2, int nums2Size, int* nums3, int nums3Size, int* nums4, int nums4Size){
    HashItem *cnt1and2 = NULL, *cnt3and4 = NULL;
    for (int i = 0; i < nums1Size; i ++) {
        for (int j = 0; j < nums2Size; j ++) {
            int val = nums1[i] + nums2[j];
            HashItem *pEntry = NULL;
            HASH_FIND_INT(cnt1and2, &val, pEntry);
            if (pEntry == NULL) {
                pEntry = (HashItem*)malloc(sizeof(HashItem));
                pEntry->key = val;
                pEntry->cnt = 1;
                HASH_ADD_INT(cnt1and2, key, pEntry);
            } else {
                pEntry->cnt ++;
            }
        }
    }
    for (int i = 0; i < nums3Size; i ++) {
        for (int j = 0; j < nums4Size; j ++) {
            int val = nums3[i] + nums4[j];
            HashItem *pEntry = NULL;
            HASH_FIND_INT(cnt3and4, &val, pEntry);
            if (pEntry == NULL) {
                pEntry = (HashItem*)malloc(sizeof(HashItem));
                pEntry->key = val;
                pEntry->cnt = 1;
                HASH_ADD_INT(cnt3and4, key, pEntry);
            } else {
                pEntry->cnt ++;
            }
        }
    }
    HashItem *iter = NULL, *curr = NULL;
    int res = 0;
    HASH_ITER(hh, cnt1and2, iter, curr) {
        int val = iter->key;
        int diff = -val;
        int cnt1 = iter->cnt;
        HashItem *pEntry = NULL;
        HASH_FIND_INT(cnt3and4, &diff, pEntry);
        if (pEntry != NULL) {
            int cnt2 = pEntry->cnt;
            res += cnt1 * cnt2;
        }
    }
    return res;
}