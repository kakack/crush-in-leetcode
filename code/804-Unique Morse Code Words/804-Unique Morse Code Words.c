/*
LeetCode 804 - Unique Morse Code Words

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// International Morse Code defines a standard encoding where each letter is mapped to a series of dots and dashes, as follows:

// 'a' maps to ".-",
// 'b' maps to "-...",
// 'c' maps to "-.-.", and so on.
// For convenience, the full table for the 26 letters of the English alphabet is given below:

// [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."]
// Given an array of strings words where each word can be written as a concatenation of the Morse code of each letter.

// For example, "cab" can be written as "-.-..--...", which is the concatenation of "-.-.", ".-", and "-...". We will call such a concatenation the transformation of a word.
// Return the number of different transformations among all words we have.



// Example 1:

// Input: words = ["gin","zen","gig","msg"]
// Output: 2
// Explanation: The transformation of each word is:
// "gin" -> "--...-."
// "zen" -> "--...-."
// "gig" -> "--...--."
// "msg" -> "--...--."
// There are 2 different transformations: "--...-." and "--...--.".
// Example 2:

// Input: words = ["a"]
// Output: 1


// Constraints:

// 1 <= words.length <= 100
// 1 <= words[i].length <= 12
// words[i] consists of lowercase English letters.

#define MAX_STR_LEN 64

const char* moss[26] = {
    ".-","-...","-.-.","-..",".","..-.",
    "--.","....","..",".---","-.-",".-..",
    "--","-.","---",".--.","--.-",".-.",
    "...","-","..-","...-",".--","-..-",
    "-.--","--.."
    };

typedef struct {
    char code[MAX_STR_LEN];
    UT_hash_handle hh;
} HashItem;

int uniqueMorseRepresentations(char ** words, int wordsSize){
    HashItem * hm = NULL;
    for (int i = 0; i < wordsSize; i ++) {
        int n = strlen(words[i]);
        int pos = 0;
        char trans[MAX_STR_LEN] ;
        for (int j = 0; j < n; j ++) {
            pos += sprintf(trans + pos, "%s", moss[words[i][j] - 'a']);
        }
        HashItem *pEntry = NULL;
        HASH_FIND_STR(hm, trans, pEntry);
        if (pEntry == NULL) {
            pEntry = (HashItem*)malloc(sizeof(HashItem));
            strcpy(pEntry->code, trans);
            HASH_ADD_STR(hm, code, pEntry);
        }
    }

    int res = HASH_COUNT(hm);
    HashItem * curr = NULL, * tmp = NULL;
    HASH_ITER(hh, hm, curr, tmp) {
        HASH_DEL(hm, curr);
        free(curr);
    }
    return res;
}
