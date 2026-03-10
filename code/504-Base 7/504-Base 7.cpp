/*
LeetCode 504 - Base 7

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given an integer num, return a string of its base 7 representation.



// Example 1:

// Input: num = 100
// Output: "202"
// Example 2:

// Input: num = -7
// Output: "-10"


// Constraints:

// // -107 <= num <= 107

class Solution {
public:
    string convertToBase7(int num) {
        string res = "";
        bool flag = true;
        if (num < 0) {
            flag = false;
            num = -num;
        } else if (num == 0) {
            return "0";
        }
        while (num > 0) {
            res = to_string(num % 7) + res;
            num /= 7;
        }
        if (!flag) {
            res = '-' + res;
        }
        return res;
    }
};
