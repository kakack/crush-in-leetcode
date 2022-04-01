// Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.

 

// Example 1:

// Input: arr = [3,1,3,6]
// Output: false
// Example 2:

// Input: arr = [2,1,2,6]
// Output: false
// Example 3:

// Input: arr = [4,-2,2,-4]
// Output: true
// Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
 

// Constraints:

// 2 <= arr.length <= 3 * 10^4
// arr.length is even.
// -10^5 <= arr[i] <= 10^5

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

static int cmp(const int* a, const int* b) {
    return abs(*a) - abs(*b);
}

bool canReorderDoubled(int* arr, int arrSize){
    HashItem *cnt = NULL;
    HashItem *pEntry = NULL;
    for (int i = 0; i < arrSize; i ++) {
        pEntry = NULL;
        HASH_FIND_INT(cnt, &arr[i], pEntry);
        if (NULL == pEntry) {
            pEntry = (HashItem*)malloc(sizeof(HashItem));
            pEntry->key = arr[i];
            pEntry->val = 1;
            HASH_ADD_INT(cnt, key, pEntry);
        } else {
            pEntry->val ++;
        }
    }
    pEntry = NULL;
    int k = 0;
    HASH_FIND_INT(cnt, &k, pEntry);
    if (pEntry != NULL && pEntry->val % 2) {
        return false;
    }
    int cntSize = HASH_COUNT(cnt);
    int *vals = (int*)malloc(sizeof(int) * cntSize);
    int pos = 0;
    HashItem *tmp = NULL;
    HASH_ITER(hh, cnt, pEntry, tmp) {
        vals[pos ++] = pEntry->key;
    }
    qsort(vals, cntSize, sizeof(int), cmp);
    for (int i = 0; i < cntSize; i ++) {
        int c1 = 0, c2 = 0;
        int key = vals[i]; 
        HashItem *pEntry1 = NULL;
        HashItem *pEntry2 = NULL;
        HASH_FIND_INT(cnt, &key, pEntry1);
        if (pEntry1) {
            c1 = pEntry1->val;
        }
        key = 2 * vals[i];
        HASH_FIND_INT(cnt, &key, pEntry2);
        if (pEntry2) {
            c2 = pEntry2->val;
        }
        if (c2 < c1) {
            return false;
        }
        if (pEntry2) {
            pEntry2->val -= c1;
        }
    }
    HASH_ITER(hh, cnt, pEntry, tmp) {
        HASH_DEL(cnt, pEntry);
        free(pEntry);
    }
    free(vals);
    return true;
}