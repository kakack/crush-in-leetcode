/*
There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.



Example 1:

Input: nums = [2,5,6,0,0,1,2], target = 0
Output: true
Example 2:

Input: nums = [2,5,6,0,0,1,2], target = 3
Output: false


Constraints:

1 <= nums.length <= 5000
-104 <= nums[i] <= 104
nums is guaranteed to be rotated at some pivot.
-104 <= target <= 104


Follow up: This problem is the same as Search in Rotated Sorted Array, where nums may contain duplicates. Would this affect the runtime complexity? How and why?
*/

bool search(int* nums, int numsSize, int target){
    int first = 0, end = numsSize;
    while (first != end) {
        int mid = (first + end) / 2;
        if (nums[mid] == target) {
            return true;
        }
        if (nums[mid] > nums[first]) {
            if (nums[mid] > target && nums[first] <= target) {
                end = mid;
            } else {
                first = mid + 1;
            }
        } else if (nums[mid] < nums[first]) {
            if (nums[mid] < target && nums[end - 1] >= target) {
                first = mid + 1;
            } else {
                end = mid;
            }
        } else {
            first ++;
        }
    }
    return false;
}