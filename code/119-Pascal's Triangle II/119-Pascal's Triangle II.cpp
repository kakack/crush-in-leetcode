/*
LeetCode 119 - Pascal's Triangle II

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*
Given an integer rowIndex, return the rowIndexth row of the Pascal's triangle.

Notice that the row index starts from 0.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Follow up:

Could you optimize your algorithm to use only O(k) extra space?



Example 1:

Input: rowIndex = 3
Output: [1,3,3,1]
Example 2:

Input: rowIndex = 0
Output: [1]
Example 3:

Input: rowIndex = 1
Output: [1,1]


Constraints:

0 <= rowIndex <= 33
*/

// C^m_n = C^(m-1)_n * (n - m + 1)/m

#include "vector"
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
         vector<int> res;
         long cur = 1;
         res.push_back(cur);
         for(int i = 1; i <= rowIndex; i++){
             cur = long(cur * (rowIndex - i + 1) / i);
             res.push_back(cur);
         }
         return res;
    }
};
