// Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.

// The words in paragraph are case-insensitive and the answer should be returned in lowercase.

 

// Example 1:

// Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
// Output: "ball"
// Explanation: 
// "hit" occurs 3 times, but it is a banned word.
// "ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
// Note that words in the paragraph are not case sensitive,
// that punctuation is ignored (even if adjacent to words, such as "ball,"), 
// and that "hit" isn't the answer even though it occurs more because it is banned.
// Example 2:

// Input: paragraph = "a.", banned = []
// Output: "a"
 

// Constraints:

// 1 <= paragraph.length <= 1000
// paragraph consists of English letters, space ' ', or one of the symbols: "!?',;.".
// 0 <= banned.length <= 100
// 1 <= banned[i].length <= 10
// banned[i] consists of only lowercase English letters.


typedef struct {
    char * key;
    UT_hash_handle hh;
} HashSetItem;

typedef struct {
    char * key;
    int val;
    UT_hash_handle hh;
} HashMapItem;

#define MAX_STR_LEN 1024
#define MAX(a, b) ((a) > (b) ? (a) : (b))

char * mostCommonWord(char * paragraph, char ** banned, int bannedSize){
    HashSetItem * bannedSet = NULL;
    for (int i = 0; i < bannedSize; i++) {
        HashSetItem * pSetEntry = NULL;
        HASH_FIND_STR(bannedSet, banned[i], pSetEntry);
        if (NULL == pSetEntry) {
            pSetEntry = (HashSetItem *)malloc(sizeof(HashSetItem));
            pSetEntry->key = banned[i];
            HASH_ADD_STR(bannedSet, key, pSetEntry);
        }
    }
    int maxFrequency = 0;
    char * mostCommon = (char *)malloc(sizeof(char) * MAX_STR_LEN);
    HashMapItem * frequencies = NULL;
    char word[MAX_STR_LEN];
    int pos = 0;
    int length = strlen(paragraph);
    for (int i = 0; i <= length; i++) {
        if (i < length && isalpha(paragraph[i])) {
            word[pos++] = tolower(paragraph[i]);
        } else if (pos > 0) {
            HashSetItem * pSetEntry = NULL;
            word[pos] = 0;
            HASH_FIND_STR(bannedSet, word, pSetEntry);
            if (NULL == pSetEntry) {
                HashMapItem * pMapEntry = NULL;
                HASH_FIND_STR(frequencies, word, pMapEntry);
                if (NULL == pMapEntry) {
                    pMapEntry = (HashMapItem *)malloc(sizeof(HashMapItem));
                    pMapEntry->key = (char *)malloc(sizeof(char) * pos);
                    strcpy(pMapEntry->key, word);
                    pMapEntry->val = 1;
                    HASH_ADD_STR(frequencies, key, pMapEntry);
                } else {
                    pMapEntry->val++;
                }
                if (maxFrequency < pMapEntry->val) {
                    maxFrequency = pMapEntry->val;
                    strcpy(mostCommon, word);
                }
            }
            pos = 0;
        }
    }
    return mostCommon;
}
