/*
LeetCode 386 - Lexicographical Numbers

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/

// Given an integer n, return 1 - n in lexicographical order.

// For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

// Please optimize your algorithm to use less time and space.
// The input size may be as large as 5,000,000.


class Solution {
public:
    vector<int> lexicalOrder(int n) {
        vector<int> res(n, 0);
        int num = 1;
        for (int i = 0; i < n; i ++) {
            res[i] = num;
            if (num * 10 <= n) {
                num *= 10;
            } else {
                while (num % 10 == 9 || num + 1 > n) {
                    num /= 10;
                }
                num ++;
            }
        }
        return res;
    }
};
