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

class Solution {
public:
    string longestPalindrome(string s) {
        string res = "";
        int mxLen = 0;
        for (int i = 0; i < s.size(); i ++) {
            string tmp = palindrome(s, i, i);
            if (tmp.size() > mxLen) {
                mxLen = tmp.size();
                res = tmp;
            }
            tmp = palindrome(s, i, i + 1);
            if (tmp.size() > mxLen) {
                mxLen = tmp.size();
                res = tmp;
            }
        }
        return res;
    }

    string palindrome(string s, int i, int j) {
        while (i >= 0 && j < s.size() and s[i] == s[j]) {
            i --;
            j ++;
        }
        return s.substr(i + 1, j - i- 1);
    }
};
