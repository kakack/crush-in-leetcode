/*
LeetCode 326 - Power of Three

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given an integer n, return true if it is a power of three. Otherwise, return false.

// An integer n is a power of three, if there exists an integer x such that n == 3x.



// Example 1:

// Input: n = 27
// Output: true
// Example 2:

// Input: n = 0
// Output: false
// Example 3:

// Input: n = 9
// Output: true


// Constraints:

// -2^31 <= n <= 2^31 - 1


// Follow up: Could you solve it without loops/recursion?

class Solution {
public:
    bool isPowerOfThree(int n) {
        if (n == 0) {
            return false;
        } else if (n == 1) {
            return true;
        }
        if (n % 3 != 0) {
            return false;
        } else {
            return isPowerOfThree(n / 3);
        }
    }
};
