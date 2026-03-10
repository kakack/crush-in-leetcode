/*
LeetCode 77 - Combinations

解题步骤（自动整理）
1. 用 DFS/回溯枚举所有可能选择，并维护当前路径/状态
2. 在递归过程中进行剪枝（如边界、重复、提前失败条件）
3. 到达终止条件时收集结果或返回，并回溯撤销选择
*/

/*Combinations
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]*/
class Solution {
public:
    vector<vector<int> > combine(int n, int k) {

        vector<vector<int> > result;
        vector<int> path;
        dfs(n, k, 1, 0, path, result);
        return result;

    }

    void dfs(int n, int k, int start, int cur, vector<int> &path, vector<vector<int> > &result){
        if(cur == k)
          result.push_back(path);

        for(int i = start; i <= n; i++){
            path.push_back(i);
            dfs(n, k, i + 1, cur + 1, path, result);
            path.pop_back();
        }
    }
};
