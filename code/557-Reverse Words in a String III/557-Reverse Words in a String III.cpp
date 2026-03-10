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


class Solution {
public:
    string reverseWords(string s) {
        int length = s.length();
        int i = 0;
        while (i < length) {
            int start = i;
            while (i < length && s[i] != ' ') {
                i++;
            }

            int left = start, right = i - 1;
            while (left < right) {
                swap(s[left], s[right]);
                left++;
                right--;
            }
            while (i < length && s[i] == ' ') {
                i++;
            }
        }
        return s;
    }
};


class Solution {
public:
    string reverseWords(string s) {
        s = s + " ";
        string res = "";
        int n = s.size();
        int l = 0, r = 0;
        while (l < n) {
            while (s[r] != ' ') {
                r ++;
            }
            string tmp = s.substr(l, r - l);
            reverse(tmp.begin(), tmp.end());
            res = res + tmp;
            while (s[r] == ' ') {
                res = res + " ";
                r ++;
            }
            l = r;
        }
        return res.substr(0, n - 1);
    }
};
