/*
LeetCode 567 - Permutation in String

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.



Example 1:

Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").
Example 2:

Input:s1= "ab" s2 = "eidboaoo"
Output: False


Constraints:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.length(), m = s2.length();
        if (n > m) {
            return false;
        }
        vector<int> cnt1(26), cnt2(26);
        for (int i = 0; i < n; i++) {
            cnt1[s1[i] - 'a'] ++;
            cnt2[s2[i] - 'a'] ++;
        }
        if (cnt1 == cnt2) {
            return true;
        }
        for (int i = n; i < m; i ++) {
            cnt2[s2[i] - 'a'] ++;
            cnt2[s2[i - n] - 'a'] --;
            if (cnt1 == cnt2) {
                return true;
            }
        }
        return false;
    }
};
