/*
LeetCode 118 - Pascal's Triangle

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/


#include "vector"


using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        for(int i = 0;i < numRows; i++){
            vector<int> row(i + 1, 1) ;
            for(int j = 1; j < i; j++) {
                row[j] = res[i-1][j - 1] + res[i-1][j];
            }
            res.push_back(row);
        }
        return res;
    }
};
