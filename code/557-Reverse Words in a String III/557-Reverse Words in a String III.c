/*
LeetCode 557 - Reverse Words in a String III

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given a string s, reverse the order of characters in each word within a sentence while still preserving whitespace and initial word order.



// Example 1:

// Input: s = "Let's take LeetCode contest"
// Output: "s'teL ekat edoCteeL tsetnoc"
// Example 2:

// Input: s = "God Ding"
// Output: "doG gniD"


// Constraints:

// 1 <= s.length <= 5 * 104
// s contains printable ASCII characters.
// s does not contain any leading or trailing spaces.
// There is at least one word in s.
// All the words in s are separated by a single space.

char* reverseWords(char* s) {
    int n = strlen(s);
    int i = 0;
    while (i < n) {
        int start = i;
        while (i < n && s[i] != ' ') {
            i ++;
        }
        int left = start, right = i - 1;
        while (left < right) {
            char tmp = s[left];
            s[left ++] = s[right];
            s[right --] = tmp;
        }
        while (i < n && s[i] == ' ') {
            i ++;
        }
    }
    return s;
}
