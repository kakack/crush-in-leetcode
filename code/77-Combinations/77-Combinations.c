
/*Combinations
Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.

For example,
If n = 4 and k = 2, a solution is:

[
  [2,4],
  [3,4],
  [2,3],
  [1,2],
  [1,3],
  [1,4],
]*/
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int *tmp;
int tmpSize;

bool check(long mask, int k, int n ) {
    tmpSize = 0;
    int sum = 0;
    for (int i = 0; i < n; i ++) {
        if ((1 << i) & mask) {
            tmp[tmpSize ++] = i + 1;
        }
    }
    return tmpSize == k;
}


int** combine(int n, int k, int* returnSize, int** returnColumnSizes){
    tmp = malloc(sizeof(int) * 21);
    int **res = malloc(sizeof(int) * 10001);
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * 10001);

    for (long  mask = 0; mask < (1 << n) ; mask ++) {
        if (check(mask, k, n)) {
            int *tmpRes = malloc(sizeof(int) * tmpSize);
            memcpy(tmpRes, tmp, sizeof(int) * tmpSize);
            res[*returnSize] = tmpRes;
            (*returnColumnSizes)[(*returnSize) ++] = tmpSize;
        }
    }
    return res;
}