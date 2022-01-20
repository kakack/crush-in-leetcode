/*
Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.



Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99


Constraints:

1 <= nums.length <= 3 * 104
-231 <= nums[i] <= 231 - 1
Each element in nums appears exactly three times except for one element which appears once.


Follow up: Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int a = 0, b = 0;
        for (int num: nums) {
            tie(a, b) = pair{(~a & b & num) | (a & ~b & ~num), ~a & (b ^ num)};
        }
        return b;
    }

    int singleNumber(vector<int>& nums) {
        int once = 0, twice = 0;
        for (int num: nums) {
            once = ~twice & (once ^ num);
            twice = ~once & (twice ^ num);
        }
        return once;
    }

    int singleNumber(vector<int>& nums) { 
        unordered_map<int, int> freq;
        int ans;
        for (int num: nums) {
            freq[num]++;
        }
        for (auto [num, occ] : freq) {
            if (occ == 1) {
                ans = num;
                break;
            }
        }
        return ans;
    }
};
