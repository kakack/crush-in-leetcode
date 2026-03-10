/*
LeetCode 1359 - Count All Valid Pickup and Delivery Options

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given n orders, each order consist in pickup and delivery services.

// Count all valid pickup/delivery possible sequences such that delivery(i) is always after of pickup(i).

// Since the answer may be too large, return it modulo 10^9 + 7.



// Example 1:

// Input: n = 1
// Output: 1
// Explanation: Unique order (P1, D1), Delivery 1 always is after of Pickup 1.
// Example 2:

// Input: n = 2
// Output: 6
// Explanation: All possible orders:
// (P1,P2,D1,D2), (P1,P2,D2,D1), (P1,D1,P2,D2), (P2,P1,D1,D2), (P2,P1,D2,D1) and (P2,D2,P1,D1).
// This is an invalid order (P1,D2,P2,D1) because Pickup 2 is after of Delivery 2.
// Example 3:

// Input: n = 3
// Output: 90


// Constraints:

// 1 <= n <= 500


// f[i]=(2i−1)i * f[i−1]

class Solution {
private:
    static constexpr int mod = 1000000007;

public:
    int countOrders(int n) {
        if (n == 1) {
            return 1;
        }
        int res = 1;
        for (int i = 2; i <= n; i ++) {
            res = (long long)res * (i * 2 - 1) % mod * i % mod;
        }
        return res;
    }
};
