/*
LeetCode 217 - Contains Duplicate

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*
Given an array of integers, find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.

Example 1:

Input: [1,2,3,1]
Output: true
Example 2:

Input: [1,2,3,4]
Output: false
Example 3:

Input: [1,1,1,3,3,4,3,2,4,2]
Output: true
*/


#include "vector"
#include "unordered_set"

using namespace std;

class Solution {
public:
    // Hash表
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> s;
        for(int num: nums){
            if (s.find(num) != s.end())
            {
                return true;
            }
            s.insert(num);
        }
        return false;
    }

    // 排序
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i ++) {
            if (nums[i] == nums[i + 1]) {
                return true;
            }
        }
        return false;
    }
};

