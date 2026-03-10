/*
LeetCode 821 - Shortest Distance to a Character

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given a string s and a character c that occurs in s, return an array of integers answer where answer.length == s.length and answer[i] is the distance from index i to the closest occurrence of character c in s.

// The distance between two indices i and j is abs(i - j), where abs is the absolute value function.



// Example 1:

// Input: s = "loveleetcode", c = "e"
// Output: [3,2,1,0,1,0,0,1,2,2,1,0]
// Explanation: The character 'e' appears at indices 3, 5, 6, and 11 (0-indexed).
// The closest occurrence of 'e' for index 0 is at index 3, so the distance is abs(0 - 3) = 3.
// The closest occurrence of 'e' for index 1 is at index 3, so the distance is abs(1 - 3) = 2.
// For index 4, there is a tie between the 'e' at index 3 and the 'e' at index 5, but the distance is still the same: abs(4 - 3) == abs(4 - 5) = 1.
// The closest occurrence of 'e' for index 8 is at index 6, so the distance is abs(8 - 6) = 2.
// Example 2:

// Input: s = "aaab", c = "b"
// Output: [3,2,1,0]


// Constraints:

// 1 <= s.length <= 10^4
// s[i] and c are lowercase English letters.
// It is guaranteed that c occurs at least once in s.



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shortestToChar(char * s, char c, int* returnSize){
    int n = strlen(s);
    *returnSize = n;
    int * ans = (int*)malloc(sizeof(int) * n);
    int * pos = (int*)malloc(sizeof(int) * n);
    int pos_top = 0;
    for (int i = 0; i < n; i ++) {
        if (s[i] == c) {
            pos[pos_top ++] = i;
        }
    }
    int anc_idx = 0;
    for (int i = 0; i < n; i ++) {
        int anc = pos[anc_idx];
        if (i >= anc && anc_idx < pos_top - 1) {
            int anc_ = pos[anc_idx + 1];
            if (abs(i - anc) > abs(i - anc_)) {
                anc = anc_;
                anc_idx ++;
            }
        }
        ans[i] = abs(i - anc);
    }
    return ans;
}
