// Given three integer arrays arr1, arr2 and arr3 sorted in strictly increasing order, return a sorted array of only the integers that appeared in all three arrays.

//  

// Example 1:

// Input: arr1 = [1,2,3,4,5], arr2 = [1,2,5,7,9], arr3 = [1,3,4,5,8]
// Output: [1,5]
// Explanation: Only 1 and 5 appeared in the three arrays.
// Example 2:

// Input: arr1 = [197,418,523,876,1356], arr2 = [501,880,1593,1710,1870], arr3 = [521,682,1337,1395,1764]
// Output: []
//  

// Constraints:

// 1 <= arr1.length, arr2.length, arr3.length <= 1000
// 1 <= arr1[i], arr2[i], arr3[i] <= 2000


class Solution {
public:
    vector<int> arraysIntersection(vector<int>& arr1, vector<int>& arr2, vector<int>& arr3) {
        unordered_map<int, int> mp;
        vector<int> res;
        for (auto &i: arr1) {
            mp[i] = 1;
        }
        for (auto &i: arr2) {
            if (mp.count(i) > 0) {
                mp[i] = 2;
            }
        }
        for (auto &i: arr3) {
            if (mp.count(i) && mp[i] == 2) {
                res.push_back(i);
            }
        }
        return res;
    }
};