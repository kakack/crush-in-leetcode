/*
LeetCode 647 - Palindromic Substrings

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
Given a string s, return the number of palindromic substrings in it.

// A string is a palindrome when it reads the same backward as forward.

// A substring is a contiguous sequence of characters within the string.



// Example 1:

// Input: s = "abc"
// Output: 3
// Explanation: Three palindromic strings: "a", "b", "c".
// Example 2:

// Input: s = "aaa"
// Output: 6
// Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".


// Constraints:

// 1 <= s.length <= 1000
// s consists of lowercase English letters.




int countSubstrings(char * s){
    int n = strlen(s), res = 0;
    for (int i  = 0; i < 2 * n - 1; i ++) {
        int l = i / 2;
        int r = i / 2 + i % 2;
        while (l >= 0 && r < n && s[l] == s[r]) {
            l --;
            r ++;
            res ++;
        }
    }
    return res;
}
