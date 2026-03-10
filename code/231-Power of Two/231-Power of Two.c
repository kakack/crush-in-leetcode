/*
LeetCode 231 - Power of Two

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given an integer n, return true if it is a power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2x.



// Example 1:

// Input: n = 1
// Output: true
// Explanation: 20 = 1
// Example 2:

// Input: n = 16
// Output: true
// Explanation: 24 = 16
// Example 3:

// Input: n = 3
// Output: false


// Constraints:

// -2^31 <= n <= 2^31 - 1


// Follow up: Could you solve it without loops/recursion?



bool isPowerOfTwo(int n){
    bool flag = false;
    while (n > 0) {
        if (n & 1) {
            if (flag) {
                return false;
            } else {
                flag = true;
            }
        }
    }
    return flag;
}

bool isPowerOfTwo(int n){
    return n > 0 && (1 << 30) % n == 0;
}

bool isPowerOfTwo(int n){
    return n > 0 && (n & (n - 1)) == 0;
}

bool isPowerOfTwo(int n){
    return n > 0 && (n & -n) == n;
}
