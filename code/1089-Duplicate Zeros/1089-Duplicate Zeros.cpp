/*
LeetCode 1089 - Duplicate Zeros

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given a fixed-length integer array arr, duplicate each occurrence of zero, shifting the remaining elements to the right.

// Note that elements beyond the length of the original array are not written. Do the above modifications to the input array in place and do not return anything.



// Example 1:

// Input: arr = [1,0,2,3,0,4,5,0]
// Output: [1,0,0,2,3,0,0,4]
// Explanation: After calling your function, the input array is modified to: [1,0,0,2,3,0,0,4]
// Example 2:

// Input: arr = [1,2,3]
// Output: [1,2,3]
// Explanation: After calling your function, the input array is modified to: [1,2,3]


// Constraints:

// 1 <= arr.length <= 10^4
// 0 <= arr[i] <= 9


class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int n = arr.size(), top = 0, i = -1;
        while (top < n) {
            i ++;
            if (arr[i] != 0) {
                top ++;
            } else {
                top += 2;
            }
        }
        int j = n - 1;
        if (top == n + 1) {
            arr[j] = 0;
            j --;
            i --;
        }
        while (j >= 0) {
            arr[j] = arr[i];
            j --;
            if (! arr[i]) {
                arr[j] = arr[i];
                j --;
            }
            i --;
        }
    }
};
