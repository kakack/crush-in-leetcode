/*
For some fixed n, an array nums is beautiful if it is a permutation of the integers 1, 2, ..., n, such that:

For every i < j, there is no k with i < k < j such that nums[k] * 2 = nums[i] + nums[j].

Given n, return any beautiful array nums.  (It is guaranteed that one exists.)

 

Example 1:

Input: n = 4
Output: [2,1,4,3]
Example 2:

Input: n = 5
Output: [3,1,2,5,4]
 

Note:

1 <= n <= 1000

*/

#include "unordered_map"
#include "vector"

using namespace std;

class Solution {
public:
    unordered_map<int, vector<int>> memo;

    vector<int> f(int N) {
        if (memo.find(N) != memo.end()) {
            return memo[N];
        }
        vector<int> ans(N);
        if (N == 1) {
            ans[0] = 1;
        } else {
            int t = 0;
            for (int x : f((N + 1) / 2)) {
                ans[t++] = 2 * x - 1;
            }
            for (int x: f(N / 2)) {
                ans[t++] = 2 * x;
            }
        }
        memo[N] = ans;
        return ans;
    }

    vector<int> beautifulArray(int n) {
        memo[1].push_back(1);
        return f(n);
    }
};