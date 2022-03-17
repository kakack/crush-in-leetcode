We can shift a string by shifting each of its letters to its successive letter.

// For example, "abc" can be shifted to be "bcd".
// We can keep shifting the string to form a sequence.

// For example, we can keep shifting "abc" to form the sequence: "abc" -> "bcd" -> ... -> "xyz".
// Given an array of strings strings, group all strings[i] that belong to the same shifting sequence. You may return the answer in any order.

//  

// Example 1:

// Input: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]
// Output: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]
// Example 2:

// Input: strings = ["a"]
// Output: [["a"]]
//  

// Constraints:

// 1 <= strings.length <= 200
// 1 <= strings[i].length <= 50
// strings[i] consists of lowercase English letters.

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char * processStr(char * str) {
    int n = strlen(str);
    char * res = (char*)malloc(sizeof(char) * (n + 1));
    int diff = str[0] - 'a';
    res[0] = 'a';
    for (int i = 1; i < n; i ++) {
        res[i] = 'a' + (str[i] -'a' + 26 - diff) % 26;
    }
    res[n] = '\0';
    return res; 
}

typedef struct {
    char * key;
    int idx;
    UT_hash_handle hh;
} HashItem;

char *** groupStrings(char ** strings, int stringsSize, int* returnSize, int** returnColumnSizes){
    char *** res = (char***)malloc(sizeof(char**) * stringsSize);
    *returnColumnSizes = (char*)malloc(sizeof(int) * stringsSize);
    *returnSize = 0;

    HashItem * strMap = NULL;
    for (int i = 0; i < stringsSize; i ++) {
        char * keyStr = processStr(strings[i]);
        int len = strlen(strings[i]);
        HashItem * pEntry = NULL;
        HASH_FIND_STR(strMap, keyStr, pEntry); 
        if (pEntry == NULL) {
            res[*returnSize] = (char**)malloc(sizeof(char*) * stringsSize);
            (*returnColumnSizes)[*returnSize] = malloc(sizeof(int) * stringsSize);
            res[*returnSize][0] = (char*)malloc(sizeof(char) * (len + 1));
            strcpy(res[*returnSize][0], strings[i]);
            (*returnColumnSizes)[*returnSize] = 1;

            pEntry = (HashItem*)malloc(sizeof(HashItem));
            pEntry->key = (char*)malloc(sizeof(char) * (len + 1));
            strcpy(pEntry->key, keyStr);
            pEntry->idx = *returnSize;
            HASH_ADD_STR(strMap, key, pEntry);

            (*returnSize) ++;
        } else {
            int row = pEntry->idx;
            int col = (*returnColumnSizes)[row];
            res[row][col] = (char*)malloc(sizeof(char) * (len + 1));
            strcpy(res[row][col], strings[i]);
            (*returnColumnSizes)[row] ++;
        }
    }
    return res;
}
