/*
Two Sum
Given an array of integers, find two numbers such that they add up to a specific target number.

The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.

You may assume that each input would have exactly one solution.

Input: numbers={2, 7, 11, 15}, target=9
Output: index1=1, index2=2
 hash
从左往右扫描一遍，然后将数及坐标，存到map中。然后再扫描一遍即可。时间复杂度O(n)，我忘记了这题哪家实习面试的时候问过我，当时答的跟屎一样，道理是充分利用map访问快的又是，搜寻两边就行，
*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> numsMap;
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i < n; i ++) {
            int diff = target - nums[i];
            if (numsMap.find(diff) != numsMap.end()) {
                res.push_back(numsMap[diff]);
                res.push_back(i);
                break;
            } else {
                numsMap[nums[i]] = i;
            }
        }
        return res;
    }
};