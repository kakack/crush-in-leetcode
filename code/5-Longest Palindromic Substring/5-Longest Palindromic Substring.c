/*
LeetCode 5 - Longest Palindromic Substring

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given a string s, return the longest palindromic substring in s.



// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"


// Constraints:

// 1 <= s.length <= 1000
// s consist of only digits and English letters.

char * longestPalindrome(char * s){
    char * res;
    int maxLen = 0;
    for (int i = 0; i < strlen(s); i ++) {
        char *tmp1 = malloc(sizeof(char) * (1 + strlen(s)));
        palindrome(s, i, i, tmp1);
        if (strlen(tmp1) > maxLen) {
            maxLen = strlen(tmp1);
            res = tmp1;
        }
        char *tmp2 = malloc(sizeof(char) * (1 + strlen(s)));
        palindrome(s, i, i + 1, tmp2);
        if (strlen(tmp2) > maxLen) {
            maxLen = strlen(tmp2);
            res = tmp2;
        }
    }
    return res;
}

void palindrome(char * s, int i, int j, char* res) {
    while (i >= 0 && j < strlen(s) && s[i] == s[j]) {
        i --;
        j ++;
    }
    // return s[i + 1:j];
    // if (i == j - 1 && s[i] != s[j]) {
    //     return '\0';
    // }
    // char *res = malloc(sizeof(char) * strlen(s));
    int idx = i + 1;
    for (; idx < j; idx++) {
        res[idx - i - 1] = s[idx];
    }
    res[idx - i - 1] = '\0';
    return res;
}
