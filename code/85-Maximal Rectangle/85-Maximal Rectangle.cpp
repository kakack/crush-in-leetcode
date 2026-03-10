/*
LeetCode 85 - Maximal Rectangle

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*
Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.



Example 1:


Input: matrix = [["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]
Output: 6
Explanation: The maximal rectangle is shown in the above picture.
Example 2:

Input: matrix = []
Output: 0
Example 3:

Input: matrix = [["0"]]
Output: 0
Example 4:

Input: matrix = [["1"]]
Output: 1
Example 5:

Input: matrix = [["0","0"]]
Output: 0


Constraints:

rows == matrix.length
cols == matrix.length
0 <= row, cols <= 200
matrix[i][j] is '0' or '1'.
*/

#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if(m == 0) {
            return 0;
        }
        int n = matrix[0].size();
        vector<vector<int>> left(m, vector<int>(n, 0));
        for(int i = 0; i < m; i ++){
            for(int j = 0; j < n; j ++) {
                if(matrix[i][j] == '1') {
                    left[i][j] = (j == 0 ? 0: left[i][j - 1]) + 1;
                }
            }
        }
        int ret = 0;
        for(int i = 0; i < m; i++){
            for (int j = 0; j < n; j ++) {
                if(matrix[i][j] == '0'){
                    continue;
                }
                int width = left[i][j];
                int area = width;
                for(int k = i - 1; k >= 0; k --){
                    width = min(width, left[k][j]);
                    area = max(area, width * (i - k + 1));
                }
                ret = max(area, ret);
            }
        }
        return ret;
    }
};
