/*
LeetCode 693 - Binary Number with Alternating Bits

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.



// Example 1:

// Input: n = 5
// Output: true
// Explanation: The binary representation of 5 is: 101
// Example 2:

// Input: n = 7
// Output: false
// Explanation: The binary representation of 7 is: 111.
// Example 3:

// Input: n = 11
// Output: false
// Explanation: The binary representation of 11 is: 1011.


// Constraints:

// 1 <= n <= 2^31 - 1

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int base1 = 0, base2 = 0;
    for (int i = 0; i <= 15; i++) {
        base1 <<= 2;
        base1 += 1;
        base2 <<= 2;
        base2 += 2;
        }
        long xor1 = base1 ^ n, xor2 = base2 ^ n;
    return (xor1 & (-xor1)) > n || (xor2 & (-xor2)) > n || n == 1431655765;
    }
};
