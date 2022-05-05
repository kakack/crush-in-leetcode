// Given an array of integers nums and an integer k, return the number of contiguous subarrays where the product of all the elements in the subarray is strictly less than k.

 

// Example 1:

// Input: nums = [10,5,2,6], k = 100
// Output: 8
// Explanation: The 8 subarrays that have product less than 100 are:
// [10], [5], [2], [6], [10, 5], [5, 2], [2, 6], [5, 2, 6]
// Note that [10, 5, 2] is not included as the product of 100 is not strictly less than k.
// Example 2:

// Input: nums = [1,2,3], k = 0
// Output: 0
 

// Constraints:

// 1 <= nums.length <= 3 * 10^4
// 1 <= nums[i] <= 1000
// 0 <= k <= 10^6



int numSubarrayProductLessThanK(int* nums, int numsSize, int k){
    if (k == 0) {
        return 0;
    }
    double *logPrefix = (double *)malloc(sizeof(double) * (numsSize + 1));
    for (int i = 0; i < numsSize; i ++) {
        logPrefix[i + 1] = logPrefix[i] + log(nums[i]);
    }
    double logk = log(k);
    int res = 0;
    for (int j = 0; j < numsSize; j ++) {
        int l = 0;
        int r = j + 1;
        int idx = j + 1;
        double val = logPrefix[j + 1] - logk + 1e-10;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (logPrefix[mid] > val) {
                idx = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        res += j + 1 - idx;
    }
    free(logPrefix);
    return res;
}