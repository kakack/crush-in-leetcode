/*
LeetCode 300 - Longest Increasing Subsequence

解题步骤（自动整理）
1. 定义状态（dp[i] 或 dp[i][j]）来表示子问题的最优解/可行性
2. 写出状态转移方程，并处理边界初始化
3. 按依赖顺序递推（必要时滚动数组优化空间），得到最终答案
*/
// Given an integer array nums, return the length of the longest strictly increasing subsequence.

// A subsequence is a sequence that can be derived from an array by deleting some or no elements without changing the order of the remaining elements. For example, [3,6,2,7] is a subsequence of the array [0,3,1,6,2,2,7].



// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1


// Constraints:

// 1 <= nums.length <= 2500
// -10^4 <= nums[i] <= 10^4


// Follow up: Can you come up with an algorithm that runs in O(n log(n)) time complexity?

// f(n)=maxf(i)+1 其中 i<n 且 a[i]<a[n]


class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int res = 1;
        for (int i = 1; i < n; i ++) {
            for (int j = 0; j < i; j ++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[j] + 1, dp[i]);
                }
                res = max(res, dp[i]);
            }
        }
        return res;
    }
};
