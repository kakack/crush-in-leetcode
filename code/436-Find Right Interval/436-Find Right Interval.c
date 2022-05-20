// You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.

// The right interval for an interval i is an interval j such that startj >= endi and startj is minimized. Note that i may equal j.

// Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.

 

// Example 1:

// Input: intervals = [[1,2]]
// Output: [-1]
// Explanation: There is only one interval in the collection, so it outputs -1.
// Example 2:

// Input: intervals = [[3,4],[2,3],[1,2]]
// Output: [-1,0,1]
// Explanation: There is no right interval for [3,4].
// The right interval for [2,3] is [3,4] since start0 = 3 is the smallest start that is >= end1 = 3.
// The right interval for [1,2] is [2,3] since start1 = 2 is the smallest start that is >= end2 = 2.
// Example 3:

// Input: intervals = [[1,4],[2,3],[3,4]]
// Output: [-1,2,-1]
// Explanation: There is no right interval for [1,4] and [3,4].
// The right interval for [2,3] is [3,4] since start2 = 3 is the smallest start that is >= end1 = 3.
 

// Constraints:

// 1 <= intervals.length <= 2 * 10^4
// intervals[i].length == 2
// -10^6 <= starti <= endi <= 10^6
// The start point of each interval is unique.



/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct {
    int start;
    int index;
} Node;

int cmp(const void *pa, const void *pb) {
    return ((Node *)pa)->start - ((Node *)pb)->start;
}


int* findRightInterval(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize){
    Node * startIntervals = (Node *)malloc(sizeof(Node) * intervalsSize);
    Node * endIntervals = (Node *)malloc(sizeof(Node) * intervalsSize);
    for (int i = 0; i < intervalsSize; i ++) {
        startIntervals[i].start = intervals[i][0];
        startIntervals[i].index = i;
        endIntervals[i].start = intervals[i][1];
        endIntervals[i].index = i;
    }
    qsort(startIntervals, intervalsSize, sizeof(Node), cmp);
    qsort(endIntervals, intervalsSize, sizeof(Node), cmp);
    int *res = malloc(sizeof(int) * intervalsSize);
    memset(res, -1, sizeof(int) * intervalsSize);

    for (int i = 0, j = 0; i < intervalsSize; i ++) {
        while (j < intervalsSize && endIntervals[i].start > startIntervals[j].start) {
            j ++;
        }
        if (j < intervalsSize) {
            res[endIntervals[i].index] = startIntervals[j].index;
        }
    } 
    *returnSize = intervalsSize;
    free(startIntervals);
    free(endIntervals);
    return res;
}