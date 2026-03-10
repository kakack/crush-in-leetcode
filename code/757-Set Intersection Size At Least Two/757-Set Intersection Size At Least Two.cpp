/*
LeetCode 757 - Set Intersection Size At Least Two

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// An integer interval [a, b] (for integers a < b) is a set of all consecutive integers from a to b, including a and b.

// Find the minimum size of a set S such that for every integer interval A in intervals, the intersection of S with A has a size of at least two.



// Example 1:

// Input: intervals = [[1,3],[1,4],[2,5],[3,5]]
// Output: 3
// Explanation: Consider the set S = {2, 3, 4}.  For each interval, there are at least 2 elements from S in the interval.
// Also, there isn't a smaller size set that fulfills the above condition.
// Thus, we output the size of this set, which is 3.
// Example 2:

// Input: intervals = [[1,2],[2,3],[2,4],[4,5]]
// Output: 5
// Explanation: An example of a minimum sized set is {1, 2, 3, 4, 5}.


// Constraints:

// 1 <= intervals.length <= 3000
// intervals[i].length == 2
// 0 <= ai < bi <= 10^8

class Solution {
public:
    void help(vector<vector<int>>& intervals, vector<vector<int>>& temp, int pos, int num) {
        for (int i = pos; i >= 0; i--) {
            if (intervals[i][1] < num) {
                break;
            }
            temp[i].push_back(num);
        }
    }

    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();
        int res = 0;
        int m = 2;
        sort(intervals.begin(), intervals.end(), [&](vector<int>& a, vector<int>& b) {
            if (a[0] == b[0]) {
                return a[1] > b[1];
            }
            return a[0] < b[0];
        });
        vector<vector<int>> temp(n);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = intervals[i][0], k = temp[i].size(); k < m; j++, k++) {
                res++;
                help(intervals, temp, i - 1, j);
            }
        }
        return res;
    }
};
