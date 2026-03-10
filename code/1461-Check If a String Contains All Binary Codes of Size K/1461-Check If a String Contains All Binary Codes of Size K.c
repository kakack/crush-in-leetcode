/*
LeetCode 1461 - Check If a String Contains All Binary Codes of Size K

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given a binary string s and an integer k, return true if every binary code of length k is a substring of s. Otherwise, return false.



// Example 1:

// Input: s = "00110110", k = 2
// Output: true
// Explanation: The binary codes of length 2 are "00", "01", "10" and "11". They can be all found as substrings at indices 0, 1, 3 and 2 respectively.
// Example 2:

// Input: s = "0110", k = 1
// Output: true
// Explanation: The binary codes of length 1 are "0" and "1", it is clear that both exist as a substring.
// Example 3:

// Input: s = "0110", k = 2
// Output: false
// Explanation: The binary code "00" is of length 2 and does not exist in the array.


// Constraints:

// 1 <= s.length <= 5 * 10^5
// s[i] is either '0' or '1'.
// 1 <= k <= 20

struct  hashItem {
    char *ch;
    UT_hash_handle hh;
};


bool hasAllCodes(char * s, int k){
    struct hashItem *hashSet = NULL, *entry = NULL, *tmp = NULL;
    int count = 0;
    int n = strlen(s);
    char * str = (char*)calloc(n + 1,sizeof(char));
    int j = 0;
    for (int i = 0; i <= n; i ++) {
        if (j == k) {
            str[k] = '\0';
            HASH_FIND_STR(hashSet, str, tmp);
            if (!tmp) {
                entry = (struct hashItem*)malloc(sizeof(struct hashItem));
                entry->ch = str;
                HASH_ADD_STR(hashSet, ch, entry);
                count++;
            }
            str ++;
            j --;
            i --;
        } else {
            str[j ++] = s[i];
        }
    }
    return count == pow(2, k);
}
