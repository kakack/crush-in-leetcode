/*
Given an unsorted array, find the maximum difference between the successive elements in its sorted form.

Return 0 if the array contains less than 2 elements.

Example 1:

Input: [3,6,9,1]
Output: 3
Explanation: The sorted form of the array is [1,3,6,9], either
             (3,6) or (6,9) has the maximum difference 3.
Example 2:

Input: [10]
Output: 0
Explanation: The array contains less than 2 elements, therefore return 0.
Note:

You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
Try to solve it in linear time/space.
*/

#include "vector"
#include "algorithm"
using namespace std;

class Solution {
public:
    int maximumGapEasy(vector<int>& nums) {
        if (nums.size() < 2) {
            return 0;
        }
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 1; i < nums.size(); i ++) {
            res = max(res, nums[i] - nums[i - 1]);
        }
        return res;
    }

    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return 0;
        }
        int exp = 1;
        vector<int> buf(n);
        int maxVal = *max_element(nums.begin(), nums.end());

        while (maxVal >= exp) {
            vector<int> cnt(10);
            for (int i = 0; i < n; i++) {
                int digit = (nums[i] / exp) % 10;
                cnt[digit]++;
            }
            for (int i = 1; i < 10; i++) {
                cnt[i] += cnt[i - 1];
            }
            for (int i = n - 1; i >= 0; i--) {
                int digit = (nums[i] / exp) % 10;
                buf[cnt[digit] - 1] = nums[i];
                cnt[digit]--;
            }
            copy(buf.begin(), buf.end(), nums.begin());
            exp *= 10;
        }

        int ret = 0;
        for (int i = 1; i < n; i++) {
            ret = max(ret, nums[i] - nums[i - 1]);
        }
        return ret;
    }
};
