// You are given a rectangular cake of size h x w and two arrays of integers horizontalCuts and verticalCuts where:

// horizontalCuts[i] is the distance from the top of the rectangular cake to the ith horizontal cut and similarly, and
// verticalCuts[j] is the distance from the left of the rectangular cake to the jth vertical cut.
// Return the maximum area of a piece of cake after you cut at each horizontal and vertical position provided in the arrays horizontalCuts and verticalCuts. Since the answer can be a large number, return this modulo 109 + 7.

 

// Example 1:


// Input: h = 5, w = 4, horizontalCuts = [1,2,4], verticalCuts = [1,3]
// Output: 4 
// Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green piece of cake has the maximum area.
// Example 2:


// Input: h = 5, w = 4, horizontalCuts = [3,1], verticalCuts = [1]
// Output: 6
// Explanation: The figure above represents the given rectangular cake. Red lines are the horizontal and vertical cuts. After you cut the cake, the green and yellow pieces of cake have the maximum area.
// Example 3:

// Input: h = 5, w = 4, horizontalCuts = [3], verticalCuts = [3]
// Output: 9
 

// Constraints:

// 2 <= h, w <= 10^9
// 1 <= horizontalCuts.length <= min(h - 1, 10^5)
// 1 <= verticalCuts.length <= min(w - 1, 10^5)
// 1 <= horizontalCuts[i] < h
// 1 <= verticalCuts[i] < w
// All the elements in horizontalCuts are distinct.
// All the elements in verticalCuts are distinct.

class Solution {
public:
    using ll = long long;
    static constexpr int mod = 1e9 +7;
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
        //排序
        sort(horizontalCuts.begin(), horizontalCuts.end());
        sort(verticalCuts.begin(), verticalCuts.end());
        int hei = 0, wei = 0;
        int pre = 0;
        for(auto i : horizontalCuts){
            hei = max(hei, i - pre);
            pre = i;
        }
        hei = max(hei, h - pre);   // 比较当前高度与下边界的距离
        pre = 0;
        for(auto  i : verticalCuts){
            wei = max(wei, i - pre);
            pre = i;
        }
        wei = max(wei, w - pre);     // 比较当前高度与右边界的距离
        return ((ll)hei*wei) % mod; //注意转long long，否则会溢出
    }
};
