/*
LeetCode 48 - Rotate Image

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*
Rotate Image
You are given an n x n 2D matrix representing an image.

Rotate the image by 90 degrees (clockwise).

Follow up:
Could you do this in-place?

就是先按照副对角线对称交换，然后按照水平中线对称交换

因为恰好是90°的关系所以计算比较方便，可以展开成逆时针90°，那就先按照主对角线对称交换
*/

class Solution {
public:
    void rotate(vector<vector<int> > &matrix) {

       int n=matrix.size();

        for(int i=0;i<n;i++)
          for(int j=0;j<n-i;j++)
            swap(matrix[i][j],matrix[n-j-1][n-i-1]);

    //沿副对角线对称

       for(int i=0;i<n/2;i++)
         for(int j=0;j<n;j++)
           swap(matrix[i][j],matrix[n-i-1][j]);
    //沿水平中线对称
    }
};
