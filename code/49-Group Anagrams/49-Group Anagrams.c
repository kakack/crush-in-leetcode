/*
Given an array of strings strs, group the anagrams together. You can return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

Example 1:

Input: strs = ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
Example 2:

Input: strs = [""]
Output: [[""]]
Example 3:

Input: strs = ["a"]
Output: [["a"]]
 

Constraints:

1 <= strs.length <= 104
0 <= strs[i].length <= 100
strs[i] consists of lower-case English letters.
*/


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int cmp(const void *a_, const void *b_){
    char *a = (char *)a_;
    char *b = (char *)b_;
    return *a - *b;
}


typedef struct {
    char * key;
    int idx;
    UT_hash_handle hh;
} HashItem;

char *** groupAnagrams(char ** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    char *** res = (char***)malloc(sizeof(char**) * strsSize);
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * strsSize);
    HashItem *strMap = NULL;

    for (int i = 0; i < strsSize; i ++) {
        int len = strlen(strs[i]);
        char * tmp = (char*)malloc(sizeof(char) * (len + 1));
        strcpy(tmp, strs[i]);

        qsort(tmp, len, sizeof(char), cmp);

        HashItem *pEntry = NULL;
        HASH_FIND_STR(strMap, tmp, pEntry);
        if (pEntry == NULL) {
            pEntry = (HashItem*)malloc(sizeof(HashItem));
            pEntry->key = (char*)malloc(sizeof(char) * (len + 1));
            strcpy(pEntry->key, tmp);
            pEntry->idx = *returnSize;
            HASH_ADD_STR(strMap, key, pEntry);

            res[*returnSize] = (char**)malloc(sizeof(char*) * strsSize);
            res[*returnSize][0] = (char*)malloc(sizeof(char) * (len + 1));
            strcpy(res[*returnSize][0], strs[i]);
            (*returnColumnSizes)[*returnSize] = 1;
            (*returnSize) ++;
        } else {
            int row = pEntry->idx;
            int col = (*returnColumnSizes)[row];
            res[row][col] = (char*)malloc(sizeof(char) * (len + 1));
            strcpy(res[row][col], strs[i]);
            (*returnColumnSizes)[row] ++;
        }
    }
    return res;
}