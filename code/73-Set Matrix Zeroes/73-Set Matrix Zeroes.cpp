/*
LeetCode 73 - Set Matrix Zeroes

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*
Given an m x n matrix. If an element is 0, set its entire row and column to 0. Do it in-place.

Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?


Example 1:


Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
Output: [[1,0,1],[0,0,0],[1,0,1]]
Example 2:


Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


Constraints:

m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1
*/

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        size_t n=matrix.size();//行数
        size_t m=matrix[0].size();//列数

        vector<bool> row(n,false);
        vector<bool> col(m,false);

         for (size_t i = 0; i < n; ++i) {
              for (size_t j = 0; j < m; ++j) {
                  if (matrix[i][j] == 0) {
                      row[i] = col[j] = true;
                    }
                  }
              }

          for (size_t i = 0; i < n; ++i) {
              if (row[i])
                  fill(&matrix[i][0], &matrix[i][0] + m, 0);
          }
          for (size_t j = 0; j < m; ++j) {
              if (col[j]) {
                  for (size_t i = 0; i < n; ++i) {
                      matrix[i][j] = 0;
                  }
                }
            }
    }
};
