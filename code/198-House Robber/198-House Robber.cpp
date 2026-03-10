/*
LeetCode 198 - House Robber

解题步骤（自动整理）
1. 定义状态（dp[i] 或 dp[i][j]）来表示子问题的最优解/可行性
2. 写出状态转移方程，并处理边界初始化
3. 按依赖顺序递推（必要时滚动数组优化空间），得到最终答案
*/
/*House Robber
You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.

即求数组中不相邻元素和的最大值。
用一个向量dp来保存到第i位数字时候，其不相邻元素和的最大值是多少。然后再max(nums[i]+dp[i-2],dp[i-1])来取到第i位时候这个最大值的值，动态规划
*/

class Solution {
public:
    int rob(vector<int>& nums) {
        int size = nums.size();
        if(size<=1)
          return nums.empty()? 0:nums[0];

        vector<int> dp = {nums[0], max(nums[0],nums[1])};
        for(int i=2;i<size;i++){
            dp.push_back(max(nums[i]+dp[i-2], dp[i-1]));
        }

        return dp.back();

    }
};
