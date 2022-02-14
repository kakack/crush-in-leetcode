// Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

 

// Example 1:

// Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
// Output: 1
// Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
// Example 2:

// Input: intervals = [[1,2],[1,2],[1,2]]
// Output: 2
// Explanation: You need to remove two [1,2] to make the rest of the intervals non-overlapping.
// Example 3:

// Input: intervals = [[1,2],[2,3]]
// Output: 0
// Explanation: You don't need to remove any of the intervals since they're already non-overlapping.
 

// Constraints:

// 1 <= intervals.length <= 10^5
// intervals[i].length == 2
// -5 * 10^4 <= starti < endi <= 5 * 10^4

// 贪心解法，找出与首个区间不重合并且右端点最小的区间

int cmp(int** a, int** b) {
    return (*a)[1] - (*b)[1];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) {
        return 0;
    }
    qsort(intervals, intervalsSize, sizeof(int*), cmp);

    int right = intervals[0][1];
    int ans = 1;
    for (int i = 1; i < intervalsSize; i ++) {
        if (intervals[i][0] >= right) {
            ans ++;
            right = intervals[i][1];
        }
    }
    return intervalsSize - ans;
}

// 动态规划
// fi = max_{j < i ^ rj < li} {fj} + 1

int cmp(int** a, int** b) {
    return (*a)[0] - (*b)[0];
}

int eraseOverlapIntervals(int** intervals, int intervalsSize, int* intervalsColSize) {
    if (intervalsSize == 0) {
        return 0;
    }

    qsort(intervals, intervalsSize, sizeof(int*), cmp);
    int f[intervalsSize];
    for (int i = 0; i < intervalsSize; i ++) {
        f[i] = 1;
    }
    int maxn = 1;
    for (int i = 1; i < intervalsSize; i ++) {
        for (int j = 0; j < i; j ++) {
            if (intervals[j][1] <= intervals[i][0]) {
                f[i] = fmax(f[i], f[j] + 1);
            }
        }
        maxn = fmax(maxn, f[i]);
    }
    return intervalsSize - maxn;
}