// Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

// You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.

 

// Example 1:

// Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
// Output: ["Shogun"]
// Explanation: The only restaurant they both like is "Shogun".
// Example 2:

// Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Shogun","Burger King"]
// Output: ["Shogun"]
// Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).
 

// Constraints:

// 1 <= list1.length, list2.length <= 1000
// 1 <= list1[i].length, list2[i].length <= 30
// list1[i] and list2[i] consist of spaces ' ' and English letters.
// All the stings of list1 are unique.
// All the stings of list2 are unique.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef  struct {
    char *key;
    int val;
    UT_hash_handle hh;
} HashItem;

void freeHash(HashItem ** obj) {
    HashItem * curr = NULL, * next = NULL;
    HASH_ITER(hh, *obj, curr, next) {
      HASH_DEL(*obj, curr);
      free(curr);
    } 
}

char ** findRestaurant(char ** list1, int list1Size, char ** list2, int list2Size, int* returnSize){
    HashItem * index = NULL;
    HashItem * pEntry = NULL;
    for (int i = 0; i < list1Size; i ++) {
        HASH_FIND_STR(index, list1[i], pEntry);
        if (NULL == pEntry) {
            pEntry = (HashItem*)malloc(sizeof(HashItem));
            pEntry->key = list1[i];
            pEntry->val = i;
            HASH_ADD_STR(index, key, pEntry);
        }
    }
    char ** res = (char**)malloc(sizeof(char *) * 1000);
    *returnSize = 0;
    int minIdx = INT_MAX;
    for (int i = 0; i < list2Size; i ++) {
        HASH_FIND_STR(index, list2[i], pEntry);
        if (NULL != pEntry) {
            int idx = i + pEntry->val;
            if (idx > minIdx) {
                continue;
            } else if (idx < minIdx) {
                minIdx = idx;
                *returnSize = 0;
            }
            res[(*returnSize) ++] = list2[i];
        }
    }
    freeHash(&index);
    return res;
}
