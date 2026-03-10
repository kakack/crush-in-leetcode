/*
LeetCode 89 - Gray Code

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*
Gray Code

My Submissions Question Solution
The gray code is a binary numeral system where two successive values differ in only one bit.

Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.

For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:

00 - 0
01 - 1
11 - 3
10 - 2
Note:
For a given n, a gray code sequence is not uniquely defined.

For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.

For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.


Gray Code 可以直接用数学公式,整数 n 的格雷码是 n ⊕ (n/2)。
*/


#include <vector>
#include <iostream

class Solution {
public:
   int binary_to_gray(int i){
       return i^(i>>1);
   }

    vector<int> grayCode(int n) {

        vector<int> ans;

        size_t size=1<<n;

        for (size_t i = 0; i < size; ++i)
              ans.push_back(binary_to_gray(i));
          return ans;

    }
};
