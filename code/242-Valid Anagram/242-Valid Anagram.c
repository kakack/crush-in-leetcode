/*
LeetCode 242 - Valid Anagram

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.



// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false


// Constraints:

// 1 <= s.length, t.length <= 5 * 10^4
// s and t consist of lowercase English letters.


// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

bool isAnagram(char * s, char * t){
    int alphat[26];
    memset(alphat, 0, sizeof(int) * 26);
    int lens = strlen(s), lent = strlen(t);
    if (lens != lent) {
        return false;
    }
    for (int i = 0; i < lens; i ++) {
        alphat[s[i] - 'a'] ++;
        alphat[t[i] - 'a'] --;
    }
    for (int i = 0; i < 26; i ++) {
        if (alphat[i] != 0) {
            return false;
        }
    }
    return true;
}
