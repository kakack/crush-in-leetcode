/*
LeetCode 122 - Best Time to Buy and Sell Stock II

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// You are given an integer array prices where prices[i] is the price of a given stock on the ith day.

// On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.

// Find and return the maximum profit you can achieve.



// Example 1:

// Input: prices = [7,1,5,3,6,4]
// Output: 7
// Explanation: Buy on day 2 (price = 1) and sell on day 3 (price = 5), profit = 5-1 = 4.
// Then buy on day 4 (price = 3) and sell on day 5 (price = 6), profit = 6-3 = 3.
// Total profit is 4 + 3 = 7.
// Example 2:

// Input: prices = [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
// Total profit is 4.
// Example 3:

// Input: prices = [7,6,4,3,1]
// Output: 0
// Explanation: There is no way to make a positive profit, so we never buy the stock to achieve the maximum profit of 0.


// Constraints:

// 1 <= prices.length <= 3 * 10^4
// 0 <= prices[i] <= 10^4


// 找局部最低点和它对应的局部最高点


int maxProfit(int* prices, int pricesSize){
    int i = 0, maxProfile = 0;
    int n = pricesSize;
    int valley = prices[0], peak = prices[0];
    while (i < n - 1) {
        while (i < n - 1 && prices[i] > prices[i + 1]) {
            i ++;
        }
        valley = prices[i];
        while ( i < n - 1 && prices[i] <= prices[i + 1]){
            i ++;
        }
        peak = prices[i];
        maxProfile += peak - valley;
    }
    return maxProfile;
}
