// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2
 

// Constraints:

// n == nums.length
// 1 <= n <= 5 * 104
// -2^31 <= nums[i] <= 2^31 - 1
 

// Follow-up: Could you solve the problem in linear time and in O(1) space?

class Solution {
// 快速排序写法
public:
    int majorityElement(vector<int>& nums) {
        quickSort(nums);
        return nums[nums.size() / 2];
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums);
        return nums;
    }

    void quickSort(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
    }

    void quickSort(vector<int>& nums, int start, int end) {
        if (start >= end) {
            return;
        }
        int mid = partition(nums, start, end);
        quickSort(nums, start, mid - 1);
        quickSort(nums, mid + 1, end);
    }

    int partition(vector<int>& nums, int start, int end) {
        int pivot = nums[start];
        int left = start + 1;
        int right = end;
        while (left < right) {
            while (left < right && nums[left] <= pivot) {
                left ++;
            }
            if (left != right) {
                swap(nums[left], nums[right]);
                right --;
            }
        }
        if (left == right && nums[right] > pivot) {
            right --;
        }
        if  (right != start) {
            swap(nums[start], nums[right]);
        }
        return right;
    }



    // 偷懒写法
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};