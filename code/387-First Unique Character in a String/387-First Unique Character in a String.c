/*
Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.
*/

int firstUniqChar(char * s){
    int n = strlen(s);
    int freq[26];
    memset(freq, 0, sizeof(int) * 26);
    for(int i = 0; i < n; i ++) {
        int idx = s[i] - 'a';
        freq[idx] ++;
    }
    for (int i = 0; i < n; i ++) {
        if (freq[s[i] - 'a'] == 1){
            return i;
        }
    }
    return -1;
}

// hash

typedef struct {
    char key;
    int cnt;
    int idx;
    UT_hash_handle hh;
} HashItem;

int firstUniqChar(char * s){
    HashItem * chrMap = NULL;
    int n = strlen(s);
    for (int i = 0; i < n; i ++) {
        char c = s[i];
        HashItem * pEntry = NULL;
        HASH_FIND(hh, chrMap, &c, sizeof(char), pEntry);
        if (pEntry == NULL) {
            pEntry = (HashItem*)malloc(sizeof(HashItem));
            pEntry->key = c;
            pEntry->cnt = 1;
            pEntry->idx = i;
            HASH_ADD(hh, chrMap, key, sizeof(char), pEntry);
        } else {
            pEntry->cnt ++;
        }
    }
    HashItem *iter = NULL, *curr = NULL;
    int res = -1;
    HASH_ITER(hh, chrMap, iter, curr) {
        if (iter->cnt == 1) {
            res = iter->idx;
            break;
        }
    }
    return res;
}