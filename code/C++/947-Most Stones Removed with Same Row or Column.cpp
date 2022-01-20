/*
On a 2D plane, we place n stones at some integer coordinate points. Each coordinate point may have at most one stone.

A stone can be removed if it shares either the same row or the same column as another stone that has not been removed.

Given an array stones of length n where stones[i] = [xi, yi] represents the location of the ith stone, return the largest possible number of stones that can be removed.



Example 1:

Input: stones = [[0,0],[0,1],[1,0],[1,2],[2,1],[2,2]]
Output: 5
Explanation: One way to remove 5 stones is as follows:
1. Remove stone [2,2] because it shares the same row as [2,1].
2. Remove stone [2,1] because it shares the same column as [0,1].
3. Remove stone [1,2] because it shares the same row as [1,0].
4. Remove stone [1,0] because it shares the same column as [0,0].
5. Remove stone [0,1] because it shares the same row as [0,0].
Stone [0,0] cannot be removed since it does not share a row/column with another stone still on the plane.
Example 2:

Input: stones = [[0,0],[0,2],[1,1],[2,0],[2,2]]
Output: 3
Explanation: One way to make 3 moves is as follows:
1. Remove stone [2,2] because it shares the same row as [2,0].
2. Remove stone [2,0] because it shares the same column as [0,0].
3. Remove stone [0,2] because it shares the same row as [0,0].
Stones [0,0] and [1,1] cannot be removed since they do not share a row/column with another stone still on the plane.
Example 3:

Input: stones = [[0,0]]
Output: 0
Explanation: [0,0] is the only stone on the plane, so you cannot remove it.


Constraints:

1 <= stones.length <= 1000
0 <= xi, yi <= 104
No two stones are at the same coordinate point.
*/

# include "vector"
# include "set"

using namespace std;

class Solution {
public:
    int fa[20010];
    int find(int x){
        if (fa[x] == x) {
            return x;
        } else {
            return find(fa[x]);
        }
    }

    void merge(int i, int j) {
        if (find(i) == find(j)) {
            return;
        }
        fa[find(i)] = find(j);
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        set<int> s;
        for (int i = 0; i < n; i ++) {
            fa[i] = i;
        }
        for (int i = 0; i < n; i ++) {
            vector<int> tmp = stones[i];
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if ((tmp[0] == stones[j][0]) || (tmp[1] == stones[j][1])) {
                    merge(i, j);
                }
            }
        }
        for(int i = 0; i < n; i ++){
            s.insert(find(i));
        }
        return n - s.size();
    }
};