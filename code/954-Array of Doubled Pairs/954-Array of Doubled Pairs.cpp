// Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.

 

// Example 1:

// Input: arr = [3,1,3,6]
// Output: false
// Example 2:

// Input: arr = [2,1,2,6]
// Output: false
// Example 3:

// Input: arr = [4,-2,2,-4]
// Output: true
// Explanation: We can take two groups, [-2,-4] and [2,4] to form [-2,-4,2,4] or [2,4,-2,-4].
 

// Constraints:

// 2 <= arr.length <= 3 * 10^4
// arr.length is even.
// -10^5 <= arr[i] <= 10^5

class Solution {
public:
    bool canReorderDoubled(vector<int>& arr) {
        unordered_map<int, int> cnt;
        for (int x: arr) {
            cnt[x] ++;
        }
        if (cnt[0] % 2) {
            return false;
        }
        vector<int> vals;
        vals.reserve(cnt.size());
        for (auto &[x, _] : cnt) {
            vals.push_back(x);
        }
        sort(vals.begin(), vals.end(), [](int a, int b){return abs(a) < abs(b);});
        for (int x: vals) {
            if (cnt[2* x] < cnt[x]) {
                return false;
            }
            cnt[2 * x] -= cnt[x];
        }
        return true;
    }
};