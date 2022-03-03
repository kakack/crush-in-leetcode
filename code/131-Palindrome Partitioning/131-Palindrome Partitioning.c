/*
Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.

A palindrome string is a string that reads the same backward as forward.



Example 1:

Input: s = "aab"
Output: [["a","a","b"],["aa","b"]]
Example 2:

Input: s = "a"
Output: [["a"]]


Constraints:

1 <= s.length <= 16
s contains only lowercase English letters.

*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

// 记忆化搜索中，f[i][j] = 0 表示未搜索，1 表示是回文串，-1 表示不是回文串
int isPalindrome(char* s, int** f, int i, int j) {
    if (f[i][j]) {
        return f[i][j];
    }
    if (i >= j) {
        return f[i][j] = 1;
    }
    return f[i][j] = (s[i] == s[j] ? isPalindrome(s, f, i + 1, j - 1) : -1);
}

void dfs(char* s, int n, int i, int** f, char*** ret, int* retSize, int* retColSize, char** ans, int* ansSize) {
    if (i == n) {
        char** tmp = malloc(sizeof(char*) * (*ansSize));
        for (int j = 0; j < (*ansSize); j++) {
            int ansColSize = strlen(ans[j]);
            tmp[j] = malloc(sizeof(char) * (ansColSize + 1));
            strcpy(tmp[j], ans[j]);
        }
        ret[*retSize] = tmp;
        retColSize[(*retSize)++] = *ansSize;
        return;
    }
    for (int j = i; j < n; ++j) {
        if (isPalindrome(s, f, i, j) == 1) {
            char* sub = malloc(sizeof(char) * (j - i + 2));
            for (int k = i; k <= j; k++) {
                sub[k - i] = s[k];
            }
            sub[j - i + 1] = '\0';
            ans[(*ansSize)++] = sub;
            dfs(s, n, j + 1, f, ret, retSize, retColSize, ans, ansSize);
            --(*ansSize);
        }
    }
}

char*** partition(char* s, int* returnSize, int** returnColumnSizes) {
    int n = strlen(s);
    int retMaxLen = n * (1 << n);
    char*** ret = malloc(sizeof(char**) * retMaxLen);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * retMaxLen);
    int* f[n];
    for (int i = 0; i < n; i++) {
        f[i] = malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            f[i][j] = 1;
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = i + 1; j < n; ++j) {
            f[i][j] = (s[i] == s[j]) && f[i + 1][j - 1];
        }
    }
    char* ans[n];
    int ansSize = 0;
    dfs(s, n, 0, f, ret, returnSize, *returnColumnSizes, ans, &ansSize);
    return ret;
}
