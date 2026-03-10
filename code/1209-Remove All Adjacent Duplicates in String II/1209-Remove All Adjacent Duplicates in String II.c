/*
LeetCode 1209 - Remove All Adjacent Duplicates in String II

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// You are given a string s and an integer k, a k duplicate removal consists of choosing k adjacent and equal letters from s and removing them, causing the left and the right side of the deleted substring to concatenate together.

// We repeatedly make k duplicate removals on s until we no longer can.

// Return the final string after all such duplicate removals have been made. It is guaranteed that the answer is unique.



// Example 1:

// Input: s = "abcd", k = 2
// Output: "abcd"
// Explanation: There's nothing to delete.
// Example 2:

// Input: s = "deeedbbcccbdaa", k = 3
// Output: "aa"
// Explanation:
// First delete "eee" and "ccc", get "ddbbbdaa"
// Then delete "bbb", get "dddaa"
// Finally delete "ddd", get "aa"
// Example 3:

// Input: s = "pbbcggttciiippooaais", k = 2
// Output: "ps"


// Constraints:

// 1 <= s.length <= 10^5
// 2 <= k <= 10^4
// s only contains lower case English letters.



char * removeDuplicates(char * s, int k){
    int *stk = (int*)malloc(sizeof(int) * 100001);
    int top = 0;
    for (int i = 0; i < strlen(s); i ++) {
        if (i == 0 || s[i] != s[i - 1]) {
            stk[top ++] = 1;
        } else if (++ stk[top - 1] == k) {
            top --;
            memcpy(s + i - k + 1, s + i, strlen(s) - k + 1);
            i = i - k;
        }
    }
    return s;
}
