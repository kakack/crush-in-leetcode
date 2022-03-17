// Given an array of strings words representing an English Dictionary, return the longest word in words that can be built one character at a time by other words in words.

// If there is more than one possible answer, return the longest word with the smallest lexicographical order. If there is no answer, return the empty string.

 

// Example 1:

// Input: words = ["w","wo","wor","worl","world"]
// Output: "world"
// Explanation: The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
// Example 2:

// Input: words = ["a","banana","app","appl","ap","apply","apple"]
// Output: "apple"
// Explanation: Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
 

// Constraints:

// 1 <= words.length <= 1000
// 1 <= words[i].length <= 30
// words[i] consists of lowercase English letters.

typedef struct {
    char *key;
    UT_hash_handle hh;
} HashItem;

void hashInsert(HashItem ** obj, const char *str) {
    HashItem *pEntry = NULL;
    HASH_FIND_STR(*obj, str, pEntry);
    if (NULL == pEntry) {
        pEntry = (HashItem *)malloc(sizeof(HashItem));
        pEntry->key = str;
        HASH_ADD_STR(*obj, key, pEntry);
    }
}

bool hashFind(const HashItem ** obj, const char * str) {
    HashItem * pEntry = NULL;
    HASH_FIND_STR(*obj, str, pEntry);
    if (NULL == pEntry) {
        return false;
    } else {
        return true;
    }
}

bool hashRelease(HashItem ** obj) {
    HashItem * curr = NULL, * next = NULL;
    HASH_ITER(hh, *obj, curr, next) {
      HASH_DEL(*obj, curr);
      free(curr);
    }
    return true;
}

int cmp(const void *a, const void *b) {
    char * pa = *(char **)a;
    char * pb = *(char **)b;
    int la = strlen(pa);
    int lb = strlen(pb);
    if (la != lb) {
        return la - lb;
    } else {
        return strcmp(pb, pa);
    }
}

char * longestWord(char ** words, int wordsSize){
    qsort(words, wordsSize, sizeof(char *), cmp);
    char * longest = "";
    HashItem *cnt = NULL;
    hashInsert(&cnt, "");
    char str[32] = {0};
    for (int i = 0; i < wordsSize; i ++) {
        snprintf(str, strlen(words[i]), "%s", words[i]);
        if (hashFind(&cnt, str)) {
            hashInsert(&cnt, words[i]);
            longest = words[i];
        }
    }
    hashRelease(&cnt);
    return longest;
}
