/*
LeetCode 14 - Longest Common Prefix

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*
Longest Common Prefix
Write a function to find the longest common prefix string amongst an array of strings.
*/
//没有必要所有字串都两两比较，只要每个都跟第一个比较找出最短的就行了
class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if(strs.empty()) return "";

        for(int id=0;id<strs[0].size();id++)
          for(int i=1;i<strs.size();i++){

              if(strs[i][id]!=strs[0][id]) return strs[0].substr(0,id);
          }
          return strs[0];
    }
};
