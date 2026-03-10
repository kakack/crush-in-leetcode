/*
LeetCode 728 - Self Dividing Numbers

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
A self-dividing number is a number that is divisible by every digit it contains.

// For example, 128 is a self-dividing number because 128 % 1 == 0, 128 % 2 == 0, and 128 % 8 == 0.
// A self-dividing number is not allowed to contain the digit zero.

// Given two integers left and right, return a list of all the self-dividing numbers in the range [left, right].



// Example 1:

// Input: left = 1, right = 22
// Output: [1,2,3,4,5,6,7,8,9,11,12,15,22]
// Example 2:

// Input: left = 47, right = 85
// Output: [48,55,66,77]


// Constraints:

// 1 <= left <= right <= 10^4



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

bool isSelfDividing(int num) {
    int num_ = num;
    while (num_ > 0) {
        int div = num_ % 10;
        if (div == 0 || num % div != 0) {
            return false;
        } else {
            num_ /= 10;
        }
    }
    return true;
}
int* selfDividingNumbers(int left, int right, int* returnSize){
    *returnSize = 0;
     int* res = (int*)malloc(sizeof(int) * (right - left + 1));
     for (int i = left; i <= right; i ++) {
         if (isSelfDividing(i)) {
             res[(*returnSize) ++] = i;
         }
     }
     return res;
}
