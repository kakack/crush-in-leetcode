/*
LeetCode 456 - 132 Pattern

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*
Given an array of n integers nums, a 132 pattern is a subsequence of three integers nums[i], nums[j] and nums[k] such that i < j < k and nums[i] < nums[k] < nums[j].

Return true if there is a 132 pattern in nums, otherwise, return false.

Follow up: The O(n^2) is trivial, could you come up with the O(n logn) or the O(n) solution?



Example 1:

Input: nums = [1,2,3,4]
Output: false
Explanation: There is no 132 pattern in the sequence.
Example 2:

Input: nums = [3,1,4,2]
Output: true
Explanation: There is a 132 pattern in the sequence: [1, 4, 2].
Example 3:

Input: nums = [-1,3,2,0]
Output: true
Explanation: There are three 132 patterns in the sequence: [-1, 3, 2], [-1, 3, 0] and [-1, 2, 0].


Constraints:

n == nums.length
1 <= n <= 10^4
-10^9 <= nums[i] <= 10^9
*/


bool find132pattern(int* nums, int numsSize){
    if (numsSize < 3) {
        return false;
    }
    int *stk = (int*)malloc(sizeof(int) * 100001);
    int tail = 0;
    int minNums[numsSize];
    minNums[0] = nums[0];
    // memset(minNums, 0, sizeof(int) * numsSize);
    for (int i = 1; i < numsSize; i ++) {
        minNums[i] = fmin(minNums[i - 1], nums[i]);
    }
    for (int j = numsSize - 1; j >= 0; j --) {
        if (nums[j] > minNums[j]) {
            while (0 < tail && stk[tail - 1] <= minNums[j]) {
                tail --;
            }
            if (0 < tail && stk[tail - 1] < nums[j]) {
                return true;
            }
            stk[tail ++] = nums[j];
        }
    }
    free(stk);
    return false;
}
