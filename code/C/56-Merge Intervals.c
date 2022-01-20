// Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

 

// Example 1:

// Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
// Example 2:

// Input: intervals = [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 

// Constraints:

// 1 <= intervals.length <= 10^4
// intervals[i].length == 2
// 0 <= starti <= endi <= 10^4




/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void *a, const void *b) {
    int *left = *(int **)a;
    int *right = *(int **)b;
    return left[0] > right[0] ? 1: -1;
}

int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes){
    int **merged = (int **)malloc(sizeof(int*) * intervalsSize);
    int cnt = 0;
    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int lf = intervals[0][0];
    int rt = intervals[0][1];

    for (int i = 1; i < intervalsSize; i ++) {
        if (intervals[i][0] <= rt) {
            rt = fmax(rt, intervals[i][1]);
        } else {
            int *tmp = (int *)malloc(sizeof(int) * 2);
            tmp[0] = lf;
            tmp[1] = rt;
            merged[cnt ++] = tmp;
            lf = intervals[i][0];
            rt = intervals[i][1];
        }
    }
    int *tmp = (int *)malloc(sizeof(int) * 2);
    tmp[0] = lf;
    tmp[1] = rt;
    merged[cnt ++] = tmp;

    *returnSize = cnt;
    *returnColumnSizes = (int *)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < cnt; i ++) {
        (*returnColumnSizes)[i] = 2;
    }
    return merged;
}