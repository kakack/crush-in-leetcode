/*
Given two strings s and t, determine if they are isomorphic.

Two strings are isomorphic if the characters in s can be replaced to get t.

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.

Example 1:

Input: s = "egg", t = "add"
Output: true
Example 2:

Input: s = "foo", t = "bar"
Output: false
Example 3:

Input: s = "paper", t = "title"
Output: true
Note:
You may assume both s and t have the same length.
*/

struct HashTable {
    char key, val;
    UT_hash_handle hh;
};

bool isIsomorphic(char * s, char * t){
    struct HashTable *s2t = NULL;
    struct HashTable *t2s = NULL;
    int n = strlen(s), m = strlen(t);
    if (n != m) {
        return false;
    }
    for (int i = 0; i < n; i ++) {
        char x = s[i], y = t[i];
        struct HashTable *tmp1, *tmp2;
        HASH_FIND(hh, s2t, &x, sizeof(char), tmp1);
        HASH_FIND(hh, t2s, &y, sizeof(char), tmp2);
        if (tmp1 == NULL) {
            tmp1 = malloc(sizeof(struct HashTable));
            tmp1->key = x;
            tmp1->val = y;
            HASH_ADD_STR(hh, s2t, key,sizeof(char), tmp1);
        } else {
            if (tmp1->val != y) {
                return false;
            }
        }
        if (tmp2 == NULL) {
            tmp2 = malloc(sizeof(struct HashTable));
            tmp2->key = y;
            tmp2->val = x;
            HASH_ADD_STR(hh, t2s, key,sizeof(char), tmp2);
        } else {
            if (tmp2->val != x) {
                return false;
            }
        }
    }
    retur true;
}