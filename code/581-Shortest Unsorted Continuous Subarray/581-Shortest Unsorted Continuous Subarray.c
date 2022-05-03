// Given an integer array nums, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order.

// Return the shortest such subarray and output its length.

 

// Example 1:

// Input: nums = [2,6,4,8,10,9,15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
// Example 2:

// Input: nums = [1,2,3,4]
// Output: 0
// Example 3:

// Input: nums = [1]
// Output: 0
 

// Constraints:

// 1 <= nums.length <= 10^4
// -10^5 <= nums[i] <= 10^5
 

// Follow up: Can you solve it in O(n) time complexity?

bool is_sorted(int* arr, int arrSize) {
    for (int i = 1; i < arrSize; i++) {
        if (arr[i - 1] > arr[i]) {
            return false;
        }
    }
    return true;
}

int cmp(int * a, int * b) {
    return *a - *b;
}

int findUnsortedSubarray(int* nums, int numsSize){
    if (is_sorted(nums, numsSize)) {
        return 0;
    }
    int numsSorted[numsSize];
    memcpy(numsSorted, nums, sizeof(int) * numsSize);
    qsort(numsSorted, numsSize, sizeof(int), cmp);
    int left = 0, right = numsSize - 1;
    while (nums[left] == numsSorted[left]) {
        left ++;
    }
    while (nums[right] == numsSorted[right]) {
        right --;
    }
    return right - left + 1;
}

// ...

int findUnsortedSubarray(int* nums, int numsSize){
    int n = numsSize;
    int maxn = INT_MIN, minn = INT_MAX;
    int right = -1, left = -1;
    for (int i = 0; i < n; i ++) {
        if (maxn > nums[i]) {
            right = i;
        } else {
            maxn = nums[i];
        }
        if (minn < nums[n - i - 1]) {
            left = n - i - 1;
        } else {
            minn = nums[n - i - 1];
        }
    }
    return right == -1 ? 0 : right - left + 1;
}