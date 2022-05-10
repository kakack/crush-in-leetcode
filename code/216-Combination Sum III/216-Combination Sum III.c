// # -*- coding: utf-8 -*
// @author: Kai Chen
// @file: 216-Combination Sum III.py
// @time: 2020/9/11 11:02
// @desc:
// Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.

// Note:

// All numbers will be positive integers.
// The solution set must not contain duplicate combinations.
// Example 1:

// Input: k = 3, n = 7
// Output: [[1,2,4]]
// Example 2:

// Input: k = 3, n = 9
// Output: [[1,2,6], [1,3,5], [2,3,4]]

// 2 <= k <= 9
// 1 <= n <= 60


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int *tmp;
int tmpSize;

bool check(int mask, int k, int n ) {
    tmpSize = 0;
    int sum = 0;
    for (int i = 0; i < 9; i ++) {
        if ((1 << i) & mask) {
            tmp[tmpSize ++] = i + 1;
            sum += i + 1;
        }
    }
    return sum == n && tmpSize == k;
}

int** combinationSum3(int k, int n, int* returnSize, int** returnColumnSizes){
    *returnColumnSizes = malloc(sizeof(int) * 2001);
    int ** res = malloc(sizeof(int*) * 2001);
    tmp = malloc(sizeof(int) * 2001);

    *returnSize = 0;
    for (int mask = 0; mask < (1 << 9); mask ++) {
        if (check(mask, k, n)) {
            int *tmpRes = malloc(sizeof(int) * tmpSize);
            memcpy(tmpRes, tmp, sizeof(int) * tmpSize);
            res[*returnSize] = tmpRes;
            (*returnColumnSizes)[(*returnSize) ++] = tmpSize;
        }
    }
    return res;
}
