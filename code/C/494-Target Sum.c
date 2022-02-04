// You are given an integer array nums and an integer target.

// You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

// For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
// Return the number of different expressions that you can build, which evaluates to target.

 

// Example 1:

// Input: nums = [1,1,1,1,1], target = 3
// Output: 5
// Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
// -1 + 1 + 1 + 1 + 1 = 3
// +1 - 1 + 1 + 1 + 1 = 3
// +1 + 1 - 1 + 1 + 1 = 3
// +1 + 1 + 1 - 1 + 1 = 3
// +1 + 1 + 1 + 1 - 1 = 3
// Example 2:

// Input: nums = [1], target = 1
// Output: 1
 

// Constraints:

// 1 <= nums.length <= 20
// 0 <= nums[i] <= 1000
// 0 <= sum(nums[i]) <= 1000
// -1000 <= target <= 1000


// 动态规划

int findTargetSumWays(int* nums, int numsSize, int target){
    int sum = 0;
    for (int i = 0; i < numsSize; i ++) {
        sum += nums[i];
    }
    int diff = sum - target;
    if (diff < 0 || diff % 2 != 0) {
        return 0;
    }
    int neg = diff / 2;
    int dp[neg + 1];
    memset(dp, 0, sizeof(int) * (neg + 1));
    dp[0] = 1;
    for (int i = 0; i < numsSize; i ++) {
        for (int j = neg; j >= nums[i]; j --) {
            dp[j] += dp[j - nums[i]];
        }
    }
    return dp[neg];
}

// 回溯
int count = 0;

void backtrack(int* nums, int numSize, int target, int index, int sum) {
    if (index == numSize) {
        if (sum == target) {
            count ++;
        }
    } else {
        backtrack(nums, numSize, target, index + 1, sum + nums[index]);
        backtrack(nums, numSize, target, index + 1, sum - nums[index]);

    }
}

int findTargetSumWays(int* nums, int numsSize, int target) {
    count = 0;
    backtrack(nums, numsSize, target, 0, 0);
    return count;
}