/*
Given an array A of 0s and 1s, we may change up to K values from 0 to 1.

Return the length of the longest (contiguous) subarray that contains only 1s.



Example 1:

Input: A = [1,1,1,0,0,0,1,1,1,1,0], K = 2
Output: 6
Explanation:
[1,1,1,0,0,1,1,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.
Example 2:

Input: A = [0,0,1,1,0,0,1,1,1,0,1,1,0,0,0,1,1,1,1], K = 3
Output: 10
Explanation:
[0,0,1,1,1,1,1,1,1,1,1,1,0,0,0,1,1,1,1]
Bolded numbers were flipped from 0 to 1.  The longest subarray is underlined.


Note:

1 <= A.length <= 20000
0 <= K <= A.length
A[i] is 0 or 1
*/
// 前缀和之差为k

int longestOnes(int* nums, int numsSize, int k){
    int n = numsSize;
    int left = 0, lsum = 0, rsum = 0, res = 0;
    for (int right = 0; right < n; right ++) {
        rsum += 1 - nums[right];
        while (lsum < rsum - k) {
            lsum += 1 - nums[left];
            left ++;
        }
        res = fmax(res, right - left + 1);
    }
    return res;
}