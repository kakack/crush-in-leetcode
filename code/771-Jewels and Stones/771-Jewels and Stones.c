// You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

// Letters are case sensitive, so "a" is considered a different type of stone from "A".

 

// Example 1:

// Input: jewels = "aA", stones = "aAAbbbb"
// Output: 3
// Example 2:

// Input: jewels = "z", stones = "ZZ"
// Output: 0
 

// Constraints:

// 1 <= jewels.length, stones.length <= 50
// jewels and stones consist of only English letters.
// All the characters of jewels are unique.


typedef struct {
    int key;
    UT_hash_handle hh;
} HashItem;

int numJewelsInStones(char * jewels, char * stones){
    HashItem *jewelsList = NULL;
    int n = strlen(jewels), m = strlen(stones);
    for (int i = 0; i < n; i ++) {
        HashItem *tmp = NULL;
        tmp = (HashItem*)malloc(sizeof(HashItem));
        int je = jewels[i] - 'a';
        tmp->key = je;
        HASH_ADD_INT(jewelsList, key, tmp);
    }
    int res = 0;
    for (int i = 0; i < m; i ++) {
        HashItem *tmp = NULL;
        int st = stones[i] - 'a';
        HASH_FIND_INT(jewelsList, &st, tmp);
        if (tmp != NULL) {
            res ++;
        }
    }
    return res;
}