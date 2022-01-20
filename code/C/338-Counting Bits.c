/*
Given a non negative integer number num.
For every numbers i in the range 0 ≤ i ≤ num calculate
the number of 1's in their binary representation and return them as an array.

Example 1:

Input: 2
Output: [0,1,1]
Example 2:

Input: 5
Output: [0,1,1,2,1,2]
Follow up:

It is very easy to come up with a solution with run time O(n*sizeof(integer)).
But can you do it in linear time O(n) /possibly in a single pass?
Space complexity should be O(n).
Can you do it like a boss?
Do it without using any builtin function like __builtin_popcount in c++ or in any other language.
*/



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* countBits(int n, int* returnSize){
    *returnSize = n + 1;
    int* res = malloc(sizeof(int) * (*returnSize));
    memset(res, 0, sizeof(int) * (*returnSize));
    for (int i = 1; i < (*returnSize); i ++) {
        res[i] = res[i & (i - 1)] + 1;
    }
    return res;
}