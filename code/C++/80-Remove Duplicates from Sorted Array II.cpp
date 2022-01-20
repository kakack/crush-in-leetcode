/*
Given a sorted array nums, remove the duplicates in-place such that duplicates appeared at most twice and return the new length.

Do not allocate extra space for another array; you must do this by modifying the input array in-place with O(1) extra memory.

Clarification:

Confused why the returned value is an integer, but your answer is an array?

Note that the input array is passed in by reference, which means a modification to the input array will be known to the caller.

Internally you can think of this:

// nums is passed in by reference. (i.e., without making a copy)
int len = removeDuplicates(nums);

// any modification to nums in your function would be known by the caller.
// using the length returned by your function, it prints the first len elements.
for (int i = 0; i < len; i++) {
    print(nums[i]);
}


Example 1:

Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3]
Explanation: Your function should return length = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively. It doesn't matter what you leave beyond the returned length.
Example 2:

Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3]
Explanation: Your function should return length = 7, with the first seven elements of nums being modified to 0, 0, 1, 1, 2, 3 and 3 respectively. It doesn't matter what values are set beyond the returned length.


Constraints:

1 <= nums.length <= 3 * 104
-104 <= nums[i] <= 104
nums is sorted in ascending order.
*/

#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int length = nums.size(), i = 1, count = 1;
        while (i < length) {
            if (nums[i] == nums[i - 1]) {
                count ++;
                if (count == 3) {
                    nums.erase(nums.begin() + i);
                    count --;
                    length --;
                } else {
                    i ++;
                }
            } else {
                i ++;
                count = 1;
            }
        }
        return length;
    }

    int removeDuplicates(int A[], int n) {
        if(n==0) return 0;
        int index=0,occur=1;
        for(int i=1;i<n;i++){
            if(A[index]==A[i]){
                if(occur<2){
                    A[++index]=A[i];
                    occur++;
                }
            }
            else {
                A[++index]=A[i];
                occur=1;
            }
        } 
        return index+1;
    }
};