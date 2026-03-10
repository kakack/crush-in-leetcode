/*
LeetCode 1048 - Longest String Chain

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// You are given an array of words where each word consists of lowercase English letters.

// wordA is a predecessor of wordB if and only if we can insert exactly one letter anywhere in wordA without changing the order of the other characters to make it equal to wordB.

// For example, "abc" is a predecessor of "abac", while "cba" is not a predecessor of "bcad".
// A word chain is a sequence of words [word1, word2, ..., wordk] with k >= 1, where word1 is a predecessor of word2, word2 is a predecessor of word3, and so on. A single word is trivially a word chain with k == 1.

// Return the length of the longest possible word chain with words chosen from the given list of words.



// Example 1:

// Input: words = ["a","b","ba","bca","bda","bdca"]
// Output: 4
// Explanation: One of the longest word chains is ["a","ba","bda","bdca"].
// Example 2:

// Input: words = ["xbc","pcxbcf","xb","cxbc","pcxbc"]
// Output: 5
// Explanation: All the words can be put in a word chain ["xb", "xbc", "cxbc", "pcxbc", "pcxbcf"].
// Example 3:

// Input: words = ["abcd","dbqca"]
// Output: 1
// Explanation: The trivial word chain ["abcd"] is one of the longest word chains.
// ["abcd","dbqca"] is not a valid word chain because the ordering of the letters is changed.


// Constraints:

// 1 <= words.length <= 1000
// 1 <= words[i].length <= 16
// words[i] only consists of lowercase English letters.

int cmp(const char **a, const char **b) {
    return strlen(*a) - strlen(*b);
}

typedef struct {
    char key[17];
    int val;
    UT_hash_handle hh;
} HashItem;

int longestStrChain(char ** words, int wordsSize){
    qsort(words, wordsSize, sizeof(char*), cmp);
    int n = wordsSize;
    HashItem *mp = NULL;
    int ans = 1;
    for (int i = 0; i < n; i ++) {
        HashItem *pEntry = (HashItem*)malloc(sizeof(HashItem));
        strcpy(pEntry->key, words[i]);
        pEntry->val = 1;
        HASH_ADD_STR(mp, key, pEntry);
    }
    for (int i = n - 1; i >= 0; i --) {
        int m = strlen(words[i]);
        HashItem *wd = NULL;
        char access[17];
        strcpy(access, words[i]);
        HASH_FIND_STR(mp, access, wd);
        int wdVal = wd->val;
        for (int j = 0; j < m; j ++) {
            char cmp[17];
            strcpy(cmp, words[i]);
            strcpy(cmp + j, words[i] + j + 1);
            HashItem *tmp = NULL;
            HASH_FIND_STR(mp, &cmp, tmp);
            if (tmp != NULL) {
                tmp->val = fmax(tmp->val, wdVal + 1);
                ans = fmax(ans, tmp->val);
            }
        }
    }
    // HashItem *cur, *iter;
    // HASH_ITER(hh, mp, cur, iter) {
    //     free(cur);
    // }
    // free(mp);
    return ans;
}
