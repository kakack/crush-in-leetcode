/*
LeetCode 476 - Number Complement

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

// For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.
// Given an integer num, return its complement.



// Example 1:

// Input: num = 5
// Output: 2
// Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.
// Example 2:

// Input: num = 1
// Output: 0
// Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.


// Constraints:

// 1 <= num < 2^31


// Note: This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/

class Solution {
public:
    int findComplement(int num) {
        int res = 0;
        while (num > 0) {
            res <<= 1;
            res += 1 ^ (num % 2);
            num >>= 1;
        }
        return res;
    }
};
