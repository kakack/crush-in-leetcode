/*Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.

选一个hash表，其实就是通过字符表达的值作为index能找到其在string中位置的储存结构，然后从左往右扫描一遍，准备一个start指针，凡是找到一个重复的字符，那么先算一下是不是当时情况下的最长，然后更新最长值，接着把之前的start到被重复的字符的hash值重新设置为-1，然后把当前的hash值更新

*/

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> mp;
        int start = -1, res = 0, n = s.size();
        for (int i = 0; i < n; i ++) {
            if (i != 0) {
                mp.erase(s[i - 1]);
            } 
            while (start + 1 < n && !mp.count(s[start + 1])) {
                mp.emplace(s[start + 1]);
                start ++;
            }
            res = max(res, start - i + 1);
        }
        return res;
    }
};