/*
LeetCode 402 - Remove K Digits

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.

*/
#include "vector"
#include "string"

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        vector<char> digits;
        int remain = num.size() - k;
        for (char c: num) {
            while (k > 0 && !digits.empty() && digits.back() > c) {
                digits.pop_back();
                k --;
            }
            digits.push_back(c);
        }

        string ans = "";
        bool isLeadingZero = true;
        for (int i = 0;i < remain; i++) {
            if (isLeadingZero && digits[i] == '0') {
                continue;
            }
            isLeadingZero = false;
            ans += digits[i];
        }
        return ans == "" ? "0": ans;
    }
};
