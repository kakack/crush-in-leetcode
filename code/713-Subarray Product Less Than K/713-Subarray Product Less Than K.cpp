/*
LeetCode 713 - Subarray Product Less Than K

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.



// Example 1:

// Input: nums = [10,5,2,6], k = 100
// Output: 8
// Explanation: The 8 subarrays that have product less than 100 are:
// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
// Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
// Example 2:

// Input: nums = [1,2,3], k = 0
// Output: 0


// Constraints:

// 1 <= nums.length <= 3 * 10^4
// 1 <= nums[i] <= 1000
// 0 <= k <= 10^6

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) {
            return 0;
        }
        int n = nums.size();
        vector<double> logPrefix(n + 1);
        for (int i = 0; i < n; i ++) {
            logPrefix[i + 1] = logPrefix[i] + log(nums[i]);
        }
        double logk = log(k);
        int res = 0;
        for (int j = 0; j < n; j ++) {
            int l = upper_bound(logPrefix.begin(), logPrefix.begin() + j + 1, logPrefix[j + 1] - log(k) + 1e-10) - logPrefix.begin();
            res += j + 1 - l;
        }
        return res;
    }
};
