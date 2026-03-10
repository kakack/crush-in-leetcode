/*
LeetCode 1695 - Maximum Erasure Value

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// You are given an array of positive integers nums and want to erase a subarray containing unique elements. The score you get by erasing the subarray is equal to the sum of its elements.

// Return the maximum score you can get by erasing exactly one subarray.

// An array b is called to be a subarray of a if it forms a contiguous subsequence of a, that is, if it is equal to a[l],a[l+1],...,a[r] for some (l,r).



// Example 1:

// Input: nums = [4,2,4,5,6]
// Output: 17
// Explanation: The optimal subarray here is [2,4,5,6].
// Example 2:

// Input: nums = [5,2,1,2,5,2,1,2,5]
// Output: 8
// Explanation: The optimal subarray here is [5,2,1] or [1,2,5].


// Constraints:

// 1 <= nums.length <= 10^5
// 1 <= nums[i] <= 10^4

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> s;
        int n = nums.size(), ans = 0, sum = 0;
        for (int l = 0, r = 0; r < n; r ++) {
            while (s.count(nums[r])) {
                sum -= nums[l];
                s.erase(nums[l ++]);
            }
            s.insert(nums[r]);
            sum += nums[r];
            ans = max(ans, sum);
        }
        return ans;
    }
};
