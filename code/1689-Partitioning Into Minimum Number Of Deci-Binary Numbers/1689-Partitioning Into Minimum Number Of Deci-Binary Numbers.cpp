/*
LeetCode 1689 - Partitioning Into Minimum Number Of Deci-Binary Numbers

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*
A decimal number is called deci-binary if each of its digits is either 0 or 1 without any leading zeros. For example, 101 and 1100 are deci-binary, while 112 and 3001 are not.

Given a string n that represents a positive decimal integer, return the minimum number of positive deci-binary numbers needed so that they sum up to n.



Example 1:

Input: n = "32"
Output: 3
Explanation: 10 + 11 + 11 = 32
Example 2:

Input: n = "82734"
Output: 8
Example 3:

Input: n = "27346209830709182346"
Output: 9


Constraints:

1 <= n.length <= 105
n consists of only digits.
n does not contain any leading zeros and represents a positive integer.
*/


#include <vector>
#include <string>

using namespace std;
class Solution {
public:
    int minPartitions(string n) {
        int max = n[0], k = 0;
        for (int i = 1; i < n.length(); i ++) {
            if (n[i] > max) {
                k = i;
                max = n[i];
            }
        }
        return n[k] - '0';
    }
};
