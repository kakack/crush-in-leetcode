/*
LeetCode 246 - Strobogrammatic Number

解题步骤（自动整理）
1. 使用哈希表记录已遍历元素（或频次/索引）以支持 O(1) 查询
2. 遍历输入并在哈希表中查找所需互补/状态，命中时更新答案
3. 遍历结束后返回答案或默认值
*/
// Given a string num which represents an integer, return true if num is a strobogrammatic number.

// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

//

// Example 1:

// Input: num = "69"
// Output: true
// Example 2:

// Input: num = "88"
// Output: true
// Example 3:

// Input: num = "962"
// Output: false
//

// Constraints:

// 1 <= num.length <= 50
// num consists of only digits.
// num does not contain any leading zeros except for zero itself.


class Solution {
public:
    bool isStrobogrammatic(string num) {
        unordered_map<char, char> rev = {
            {'0', '0'},
            {'1', '1'},
            {'2', '#'},
            {'3', '#'},
            {'4', '#'},
            {'5', '#'},
            {'6', '9'},
            {'7', '#'},
            {'8', '8'},
            {'9', '6'}
        };
        int i = 0, j = num.size() - 1;
        while (i <= j) {
            if (rev[num[i]] == num[j]) {
                i ++;
                j --;
            } else {
                return false;
            }
        }
        return true;
    }
};
