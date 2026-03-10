/*
LeetCode 163 - Missing Ranges

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/

// You are given an inclusive range [lower, upper] and a sorted unique integer array nums, where all elements are in the inclusive range.

// A number x is considered missing if x is in the range [lower, upper] and x is not in nums.

// Return the smallest sorted list of ranges that cover every missing number exactly. That is, no element of nums is in any of the ranges, and each missing number is in one of the ranges.

// Each range [a,b] in the list should be output as:

// "a->b" if a != b
// "a" if a == b
//

// Example 1:

// Input: nums = [0,1,3,50,75], lower = 0, upper = 99
// Output: ["2","4->49","51->74","76->99"]
// Explanation: The ranges are:
// [2,2] --> "2"
// [4,49] --> "4->49"
// [51,74] --> "51->74"
// [76,99] --> "76->99"
// Example 2:

// Input: nums = [-1], lower = -1, upper = -1
// Output: []
// Explanation: There are no missing ranges since there are no missing numbers.
//

// Constraints:

// -10^9 <= lower <= upper <= 10^9
// 0 <= nums.length <= 100
// lower <= nums[i] <= upper
// All the values of nums are unique.

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
char ** findMissingRanges(int* nums, int numsSize, int lower, int upper, int* returnSize){
    char **res = (char**)malloc(sizeof(char*) * (numsSize + 1));
    *returnSize = 0;
    int *newNum = (int*)malloc(sizeof(int) * (numsSize + 1));
    for (int i = 0; i < numsSize; i ++) {
        newNum[i] = nums[i];
    }
    newNum[numsSize] = upper + 1;
    int last = lower - 1;
    for (int i = 0; i < numsSize + 1; i ++) {
        if (newNum[i] - last > 2) {
            res[*returnSize] = (char*)malloc(sizeof(char) * 60);
            sprintf(res[*returnSize], "%d->%d", last + 1, newNum[i] - 1);
            (*returnSize) ++;
        } else if (newNum[i] - last == 2) {
            res[*returnSize] = (char*)malloc(sizeof(char) * 60);
            sprintf(res[*returnSize], "%d", last + 1);
            (*returnSize) ++;
        }
        last = newNum[i];
    }
    return res;
}
