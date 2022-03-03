/*
Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.


In Pascal's triangle, each number is the sum of the two numbers directly above it.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]

*/

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** generate(int numRows, int* returnSize, int** returnColumnSizes){
    int** ret = malloc(sizeof(int*) * numRows);
    *returnSize = numRows;
    *returnColumnSizes = malloc(sizeof(int) * numRows);
    for (int i = 0; i < numRows; i ++) {
        ret[i] = malloc(sizeof(int) * (i + 1));
        (*returnColumnSizes)[i] = i + 1;
        ret[i][0] = ret[i][i] = 1;
        for (int j = 1; j < i; j ++) {
            ret[i][j] = ret[i - 1][j] + ret[i - 1][j - 1];
        }
    }
    return ret;
}
