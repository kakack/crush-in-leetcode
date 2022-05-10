// # -*- coding: utf-8 -*
// @author: Kai Chen
// @file: 216-Combination Sum III.py
// @time: 2020/9/11 11:02
// @desc:
// Find all possible combinations of k numbers that add up to a number n, 
// given that only numbers from 1 to 9 can be used and 
// each combination should be a unique set of numbers.

// Note:

// All numbers will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]

class Solution {
public:
    vector<int> tmp;
    vector<vector<int>> res;

    bool check(int mask, int k, int n) {
        tmp.clear();
        for (int i = 0; i < 9; i ++) {
            if ((1 << i) & mask) {
                tmp.push_back(i + 1);
            }
        }
        return tmp.size() == k && accumulate(tmp.begin(), tmp.end(), 0) == n;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        for (int mask = 0; mask < (1 << 9); mask ++) {
            if (check(mask, k, n)) {
                res.push_back(tmp);
            }
        }
        return res;
    }
};