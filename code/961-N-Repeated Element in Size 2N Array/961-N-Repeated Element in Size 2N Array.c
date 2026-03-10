/*
LeetCode 961 - N-Repeated Element in Size 2N Array

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
You are given an integer array nums with the following properties:

// nums.length == 2 * n.
// nums contains n + 1 unique elements.
// Exactly one element of nums is repeated n times.
// Return the element that is repeated n times.



// Example 1:

// Input: nums = [1,2,3,3]
// Output: 3
// Example 2:

// Input: nums = [2,1,2,5,3,2]
// Output: 2
// Example 3:

// Input: nums = [5,1,5,2,5,3,5,4]
// Output: 5


// Constraints:

// 2 <= n <= 5000
// nums.length == 2 * n
// 0 <= nums[i] <= 10^4
// nums contains n + 1 unique elements and one of them is repeated exactly n times.

int repeatedNTimes(int* nums, int numsSize) {
    srand(time(NULL));
    while (true) {
        int x = random() % numsSize, y = random() % numsSize;
        if (x != y && nums[x] == nums[y]) {
            return nums[x];
        }
    }
}
