/*
LeetCode 50 - Pow(x, n)

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*Pow(x, n)分治法
Implement pow(x, n).
*/

class Solution {
public:
    double pow(double x, int n) {
        if(n == 0)
          return 1;
        double res = pow(x, n/2);
        if(n%2 == 0)
          return res*res;
        else
          return res*res*x;

    }
    double myPow(double x, int n) {
        if(n<0)
          return 1.0/pow(x, -n);
        else
          return pow(x,n);
    }
};
