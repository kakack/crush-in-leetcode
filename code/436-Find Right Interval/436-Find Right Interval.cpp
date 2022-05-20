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

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        vector<pair<int, int>> startIntervals;
        vector<pair<int, int>> endIntervals;
        int n = intervals.size();
        for (int i = 0; i < n; i++) {
            startIntervals.emplace_back(intervals[i][0], i);
            endIntervals.emplace_back(intervals[i][1], i);
        }
        sort(startIntervals.begin(), startIntervals.end());
        sort(endIntervals.begin(), endIntervals.end());
        vector<int> res(n, - 1);
        for (int i = 0, j = 0; i < n && j < n; i ++) {
            while (j < n && endIntervals[i].first > startIntervals[j].first) {
                j ++;
            }
            if (j < n) {
                res[endIntervals[i].second] = startIntervals[j].second;
            }
        }
        return res;
    }
};