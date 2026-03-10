/*
LeetCode 605 - Can Place Flowers

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*
You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.

Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule.



Example 1:

Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
Example 2:

Input: flowerbed = [1,0,0,0,1], n = 2
Output: false


Constraints:

1 <= flowerbed.length <= 2 * 104
flowerbed[i] is 0 or 1.
There are no two adjacent flowers in flowerbed.
0 <= n <= flowerbed.length
*/

#include "vector"

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int target = 0, m = flowerbed.size();
        if (m == 1) {
            if (flowerbed[0] == 0){
                return 1 >= n;
            } else {
                return 0 >= n;
            }
        }
        if (flowerbed[0] == 0 && flowerbed[1] == 0){
            target = 1;
            flowerbed[0] = 1;
        }

        for (int i = 1; i < m - 2; i++)
        {
            if(flowerbed[i] == 0) {
                if (flowerbed[i + 1] == 0 & flowerbed[i - 1] == 0) {
                    target += 1;
                    flowerbed[i] =1;
                }
            }
        }
        if (flowerbed[m - 2] == 0 & flowerbed[m - 1] == 0)
        {
            target ++;
        }
        return target >= n;
    }
};
