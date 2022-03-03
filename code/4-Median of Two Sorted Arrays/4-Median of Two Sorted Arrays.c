// Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

// The overall run time complexity should be O(log (m+n)).

 

// Example 1:

// Input: nums1 = [1,3], nums2 = [2]
// Output: 2.00000
// Explanation: merged array = [1,2,3] and median is 2.
// Example 2:

// Input: nums1 = [1,2], nums2 = [3,4]
// Output: 2.50000
// Explanation: merged array = [1,2,3,4] and median is (2 + 3) / 2 = 2.5.
 

// Constraints:

// nums1.length == m
// nums2.length == n
// 0 <= m <= 1000
// 0 <= n <= 1000
// 1 <= m + n <= 2000
// -10^6 <= nums1[i], nums2[i] <= 10^6


// 当m + n 为奇数的时候，为（m + n）/ 2个；当偶数时候，为(m + n) / 2 和(m + n) / 2 + 1个的平均值

int min(int a, int b) {
    if (a < b) {
        return a;
    } else {
        return b;
    }
}

int getKthElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int k) {
    int index1 = 0, index2 = 0;
    while (true) {
        if (index1 == nums1Size) {
            return nums2[index2 + k - 1];
        } else if (index2 == nums2Size) {
            return nums1[index1 + k - 1];
        } else if (k == 1) {
            return min(nums1[index1], nums2[index2]);
        }

        int newIndex1 = min(index1 + k / 2 - 1, nums1Size - 1);
        int newIndex2 = min(index2 + k / 2 - 1, nums2Size - 1);
        int pivot1 = nums1[newIndex1];
        int pivot2 = nums2[newIndex2];
        if (pivot1 <= pivot2) {
            k -= newIndex1 - index1 + 1;
            index1 = newIndex1 + 1;
        } else {
            k -= newIndex2 - index2 + 1;
            index2 = newIndex2 + 1;
        }
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int totalLength = nums1Size + nums2Size;
    if (totalLength % 2 == 1) {
        return getKthElement(nums1, nums1Size, nums2, nums2Size, (totalLength + 1) / 2);
    } else {
        return (getKthElement(nums1, nums1Size, nums2, nums2Size, (totalLength + 1) / 2) + getKthElement(nums1, nums1Size, nums2, nums2Size, (totalLength + 1) / 2 + 1)) / 2.0;
    }
}