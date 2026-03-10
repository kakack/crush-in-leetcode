/*
LeetCode 45 - Jump Game II

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given an array of non-negative integers nums, you are initially positioned at the first index of the array.

// Each element in the array represents your maximum jump length at that position.

// Your goal is to reach the last index in the minimum number of jumps.

// You can assume that you can always reach the last index.



// Example 1:

// Input: nums = [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2. Jump 1 step from index 0 to 1, then 3 steps to the last index.
// Example 2:

// Input: nums = [2,3,0,1,4]
// Output: 2


// Constraints:

// 1 <= nums.length <= 10^4
// 0 <= nums[i] <= 1000

// 反向
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), steps = 0;
        int pos = n - 1;
        while (pos > 0) {
            for (int i = 0; i < pos; i ++) {
                if (nums[i] + i >= pos) {
                    steps ++;
                    pos = i;
                    break;
                }
            }
        }
        return steps;
    }
};

// 正向

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), steps = 0;
        int maxPos = 0, end = 0;
        for (int i = 0; i < n - 1; i ++) {
            if (maxPos >= i) {
                maxPos = max(maxPos, i + nums[i]);
                if (end == i) {
                    end = maxPos;
                    steps ++;
                }
            }
        }
        return steps;
    }
};
