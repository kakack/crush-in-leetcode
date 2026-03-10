/*
LeetCode 680 - Valid Palindrome II

解题步骤（自动整理）
1. 定义状态（dp[i] 或 dp[i][j]）来表示子问题的最优解/可行性
2. 写出状态转移方程，并处理边界初始化
3. 按依赖顺序递推（必要时滚动数组优化空间），得到最终答案
*/
// Given a non-empty string s, you may delete at most one character. Judge whether you can make it a palindrome.

// Example 1:
// Input: "aba"
// Output: True

// Example 2:
// Input: "abca"
// Output: True

// Explanation: You could delete the character 'c'.
// Note:
// The string will only contain lowercase characters a-z. The maximum length of the string is 50000.


class Solution {
private:
    bool isPalindrome(string s, int l, int r) {
        while (l < r) {
            if (s[l ++] != s[r --]) {
                return false;
            }
        }
        return true;
    }

public:
    bool validPalindrome(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r && s[l] == s[r]) {
            l ++;
            r --;
        }
        if (l < r) {
            return isPalindrome(s, l, r - 1) || isPalindrome(s, l + 1, r);
        } else {
            return true;
        }
    }
};
