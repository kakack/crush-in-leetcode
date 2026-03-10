/*
LeetCode 942 - DI String Match

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// A permutation perm of n + 1 integers of all the integers in the range [0, n] can be represented as a string s of length n where:

// s[i] == 'I' if perm[i] < perm[i + 1], and
// s[i] == 'D' if perm[i] > perm[i + 1].
// Given a string s, reconstruct the permutation perm and return it. If there are multiple valid permutations perm, return any of them.



// Example 1:

// Input: s = "IDID"
// Output: [0,4,1,3,2]
// Example 2:

// Input: s = "III"
// Output: [0,1,2,3]
// Example 3:

// Input: s = "DDI"
// Output: [3,2,0,1]


// Constraints:

// 1 <= s.length <= 10^5
// s[i] is either 'I' or 'D'.



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* diStringMatch(char * s, int* returnSize){
    int low = 0, high = strlen(s), n = strlen(s);
    int * res = malloc(sizeof(int) * (n + 1));
    for (int i = 0; i < n; i ++) {
        if (s[i] == 'I') {
            res[i] = low ++;
        } else {
            res[i] = high --;
        }
    }
    res[n] = low;
    *returnSize = n + 1;
    return res;
}
