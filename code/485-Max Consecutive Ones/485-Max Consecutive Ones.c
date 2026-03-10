/*
LeetCode 485 - Max Consecutive Ones

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given a binary array nums, return the maximum number of consecutive 1's in the array.



// Example 1:

// Input: nums = [1,1,0,1,1,1]
// Output: 3
// Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.
// Example 2:

// Input: nums = [1,0,1,1,0,1]
// Output: 2


// Constraints:

// 1 <= nums.length <= 10^5
// nums[i] is either 0 or 1.

int findMaxConsecutiveOnes(int* nums, int numsSize){
    int mxLen = 0;
    for (int i = -1, j = 0; j < numsSize; j ++) {
        if (nums[j] != 1) {
            i = j;
        } else {
            mxLen = fmax(mxLen, j - i);
        }
    }
    return mxLen;
}
