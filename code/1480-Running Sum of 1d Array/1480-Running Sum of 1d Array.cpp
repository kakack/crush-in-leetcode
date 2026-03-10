/*
LeetCode 1480 - Running Sum of 1d Array

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given an array nums. We define a running sum of an array as runningSum[i] = sum(nums[0]…nums[i]).

// Return the running sum of nums.



// Example 1:

// Input: nums = [1,2,3,4]
// Output: [1,3,6,10]
// Explanation: Running sum is obtained as follows: [1, 1+2, 1+2+3, 1+2+3+4].
// Example 2:

// Input: nums = [1,1,1,1,1]
// Output: [1,2,3,4,5]
// Explanation: Running sum is obtained as follows: [1, 1+1, 1+1+1, 1+1+1+1, 1+1+1+1+1].
// Example 3:

// Input: nums = [3,1,2,10,1]
// Output: [3,4,6,16,17]


// Constraints:

// 1 <= nums.length <= 1000
// -10^6 <= nums[i] <= 10^6

class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        vector<int> res({nums[0]});
        int n = nums.size();
        for (int i = 1;  i < n; i ++) {
            res.push_back(res[i - 1] + nums[i]);
        }
        return res;
    }
};
