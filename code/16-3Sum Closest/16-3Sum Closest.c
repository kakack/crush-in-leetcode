/*
LeetCode 16 - 3Sum Closest

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

// Return the sum of the three integers.

// You may assume that each input would have exactly one solution.



// Example 1:

// Input: nums = [-1,2,1,-4], target = 1
// Output: 2
// Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
// Example 2:

// Input: nums = [0,0,0], target = 1
// Output: 0


// Constraints:

// 3 <= nums.length <= 1000
// -1000 <= nums[i] <= 1000
// -10^4 <= target <= 10^4

int cmp(int* a, int* b) {
    return *a - *b;
}

void update(int cur, int *best, int target) {
    if (abs(cur - target) < abs(*best - target)) {
        *best = cur;
    }
}

int threeSumClosest(int* nums, int numsSize, int target){
    qsort(nums, numsSize, sizeof(int), cmp);
    int best = 1e7;
    for (int i = 0; i < numsSize; i ++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }
        // 使用双指针
        int j = i + 1, k = numsSize - 1;
        while (j < k) {
            int s = nums[i] + nums[j] + nums[k];
            if (s == target) {
                return target;
            }
            update(s, &best, target);
            if (s > target) {
                int k0 = k - 1;
                while (j < k0 && nums[k0] == nums[k]) {
                    k0 -= 1;
                }
                k = k0;
            } else {
                int j0 = j + 1;
                while (j0 < k && nums[j0] == nums[j]) {
                    j0 ++;
                }
                j = j0;
            }
        }
    }
    return best;
}
