// Given a binary array nums, return the maximum number of consecutive 1's in the array if you can flip at most one 0.

//  

// Example 1:

// Input: nums = [1,0,1,1,0]
// Output: 4
// Explanation: Flip the first zero will get the maximum number of consecutive 1s. After flipping, the maximum number of consecutive 1s is 4.
// Example 2:

// Input: nums = [1,0,1,1,0,1]
// Output: 4
//  

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.
//  

// Follow up: What if the input numbers come in one by one as an infinite stream? In other words, you can't store all numbers coming from the stream as it's too large to hold in memory. Could you solve it efficiently?

// 用dp[i][0]表示包含nums[i]未翻转情况下最长串长度，dp[i][1]表示包含nums[i]翻转情况下最长串长度；
// 如果动态输入，可以不用维护一整个数组，只要关注一个全局最大值和当前处理位置的两个值就行

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), res = 0, dp0 = 0, dp1 = 0;
        for (int i = 0; i < n; i ++) {
            if (nums[i] == 1) {
                dp1 ++;
                dp0 ++;
            } else{
                dp1 = dp0 + 1;
                dp0 = 0;
            }
            res = max(res, max(dp0, dp1));
        }
        return res;
    }
};
