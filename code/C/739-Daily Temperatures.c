// Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.

 

// Example 1:

// Input: temperatures = [73,74,75,71,69,72,76,73]
// Output: [1,1,4,2,1,1,0,0]
// Example 2:

// Input: temperatures = [30,40,50,60]
// Output: [1,1,1,0]
// Example 3:

// Input: temperatures = [30,60,90]
// Output: [1,1,0]
 

// Constraints:

// 1 <= temperatures.length <= 10^5
// 30 <= temperatures[i] <= 100

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* dailyTemperatures(int* temperatures, int temperaturesSize, int* returnSize){
    *returnSize = temperaturesSize;
    int *res = malloc(sizeof(int) * temperaturesSize);
    memset(res, 0, sizeof(int) * temperaturesSize);
    int *stack = malloc(sizeof(int) * temperaturesSize);
    int top = 0;
    for (int i = 0; i < temperaturesSize; i ++) {
        while (top > 0 && temperatures[i] > temperatures[stack[top - 1]]) {
            int preIndex = stack[top - 1];
            res[preIndex] = i - preIndex;
            top --;
        }
        stack[top ++] = i;
    }
    return res;
}