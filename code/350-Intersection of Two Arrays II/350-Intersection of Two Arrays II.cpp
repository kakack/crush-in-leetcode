/*
LeetCode 350 - Intersection of Two Arrays II

解题步骤（自动整理）
1. 定义状态（dp[i] 或 dp[i][j]）来表示子问题的最优解/可行性
2. 写出状态转移方程，并处理边界初始化
3. 按依赖顺序递推（必要时滚动数组优化空间），得到最终答案
*/
// Given two integer arrays nums1 and nums2, return an array of their intersection.
// Each element in the result must appear as many times as it shows in both arrays
// and you may return the result in any order.



// Example 1:

// Input: nums1 = [1,2,2,1], nums2 = [2,2]
// Output: [2,2]
// Example 2:

// Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
// Output: [4,9]
// Explanation: [9,4] is also accepted.


// Constraints:

// 1 <= nums1.length, nums2.length <= 1000
// 0 <= nums1[i], nums2[i] <= 1000


// Follow up:

// What if the given array is already sorted? How would you optimize your algorithm?
// What if nums1's size is small compared to nums2's size? Which algorithm is better?
// What if elements of nums2 are stored on disk,
// and the memory is limited such that you cannot load all elements into the memory at once?

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> numMap;
        for (int num: nums1) {
            if (numMap.find(num) == numMap.end()) {
                numMap[num] = 1;
            } else {
                numMap[num] ++;
            }
        }
        vector<int> res;
        for (int num: nums2) {
            if (numMap.find(num) != numMap.end()) {
                res.push_back(num);
                numMap[num] --;
                if (numMap[num] == 0) {
                    numMap.erase(num);
                }
            }
        }
        return res;
    }
};
