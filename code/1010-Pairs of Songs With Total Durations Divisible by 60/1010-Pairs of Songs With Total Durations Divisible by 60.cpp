/*
LeetCode 1010 - Pairs of Songs With Total Durations Divisible by 60

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
#include <vector>
#include <iostream>
class Solution
{
public:
    int numPairsDivisibleBy60(vector<int> &time)
    {
        int res = 0;
        vector<int> store(60);
        for(auto iter = time.begin(); iter != time.end(); iter ++){
            store[*iter % 60] ++;
        }
        res += store[0] * (store[0] - 1) / 2 + store[30] * (store[30] - 1) / 2;
        for(int i = 1; i < 30; i++){
            res += store[i] * store[60 -i];
        }
        return res;
    }
};

// int main(int argc, char const *argv[])
// {
//     Solution s = Solution.__init__();
//     vector<int> time = []
//     return 0;
// }
