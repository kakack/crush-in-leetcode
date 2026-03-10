/*
LeetCode 78 - Subsets

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*Subsets
Given a set of distinct integers, S, return all possible subsets.

Note:
Elements in a subset must be in non-descending order.
The solution set must not contain duplicate subsets.
For example,
If S = [1,2,3], a solution is:

[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]

妈的网上和教材里说的每一个对的，数位法要纸上画一下后再做，就会比较明白到底怎么回事
*/

class Solution {

public:
    vector<vector<int> > subsets(vector<int> &S) {
          sort(S.begin(), S.end()); //输出有序
          vector<vector<int> > res;
          long n = pow(2,S.size());//总共有n种情况

          for(long i=0;i<n;i++){
              vector<int> v;
              for(int j=0;j<S.size();j++){
                  if((1<<j)&i){
                      v.push_back(S[j]);
                  }
              }

              res.push_back(v);
              v.clear();
          }

          return res;

    }
};
