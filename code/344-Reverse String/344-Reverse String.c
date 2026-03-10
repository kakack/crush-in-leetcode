/*
LeetCode 344 - Reverse String

解题步骤（自动整理）
1. 定义状态（dp[i] 或 dp[i][j]）来表示子问题的最优解/可行性
2. 写出状态转移方程，并处理边界初始化
3. 按依赖顺序递推（必要时滚动数组优化空间），得到最终答案
*/
// Write a function that reverses a string. The input string is given as an array of characters s.

// You must do this by modifying the input array in-place with O(1) extra memory.



// Example 1:

// Input: s = ["h","e","l","l","o"]
// Output: ["o","l","l","e","h"]
// Example 2:

// Input: s = ["H","a","n","n","a","h"]
// Output: ["h","a","n","n","a","H"]


// Constraints:

// 1 <= s.length <= 10^5
// s[i] is a printable ascii character.


void swap(char* a, char* b) {
    char tmp = *a;
    *a = *b;
    *b = tmp;
}

void reverseString(char* s, int sSize){
    int left = 0 , right = sSize - 1;
    while (left < right) {
        swap(s + (left ++), s + (right --));
    }
}
