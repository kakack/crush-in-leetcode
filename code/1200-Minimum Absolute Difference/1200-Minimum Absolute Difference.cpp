/*
LeetCode 1200 - Minimum Absolute Difference

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given an array of distinct integers arr, find all pairs of elements with the minimum absolute difference of any two elements.

// Return a list of pairs in ascending order(with respect to pairs), each pair [a, b] follows

// a, b are from arr
// a < b
// b - a equals to the minimum absolute difference of any two elements in arr


// Example 1:

// Input: arr = [4,2,1,3]
// Output: [[1,2],[2,3],[3,4]]
// Explanation: The minimum absolute difference is 1. List all pairs with difference equal to 1 in ascending order.
// Example 2:

// Input: arr = [1,3,6,10,15]
// Output: [[1,3]]
// Example 3:

// Input: arr = [3,8,-10,23,19,-4,-14,27]
// Output: [[-14,-10],[19,23],[23,27]]


// Constraints:

// 2 <= arr.length <= 10^5
// -10^6 <= arr[i] <= 10^6

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int minDif = INT_MAX;
        vector<vector<int>> res;
        for (int i = 0; i < n - 1; i ++) {
            int dif = arr[i + 1] - arr[i];
            if (dif < minDif) {
                res = {{arr[i], arr[i + 1]}};
                minDif = dif;
            } else if (dif == minDif) {
                res.emplace_back(initializer_list<int>{arr[i], arr[i + 1]});
            }
        }
        return res;
    }
};
