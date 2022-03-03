// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.

// A subarray is a contiguous part of an array.

 

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
// Example 2:

// Input: nums = [1]
// Output: 1
// Example 3:

// Input: nums = [5,4,-1,7,8]
// Output: 23
 

// Constraints:

// 1 <= nums.length <= 10^5
// -10^4 <= nums[i] <= 10^4
 

// Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.

int maxSubArray(int* nums, int numsSize){
    int maxSum = nums[0], sumIdx = nums[0];
    for (int i = 1; i < numsSize; i ++) {
        if (sumIdx <= 0) {
            sumIdx = nums[i];
        } else {
            sumIdx += nums[i];
        }
        if (maxSum < sumIdx) {
            maxSum = sumIdx;
        }
    }
    return maxSum;
}