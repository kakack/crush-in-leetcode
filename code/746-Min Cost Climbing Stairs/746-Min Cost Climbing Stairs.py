# -*- coding: utf-8 -*
"""
@author: Kai Chen
@file: 746-Min Cost Climbing Stairs.py
@time: 2020/12/21 9:17
@desc:

On a staircase, the i-th step has some non-negative cost cost[i] assigned (0 indexed).

Once you pay the cost, you can either climb one or two steps. You need to find minimum cost to reach the top of the floor, and you can either start from the step with index 0, or the step with index 1.

Example 1:
Input: cost = [10, 15, 20]
Output: 15
Explanation: Cheapest is start on cost[1], pay that cost and go to the top.
Example 2:
Input: cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
Output: 6
Explanation: Cheapest is start on cost[0], and only step on 1s, skipping cost[3].
Note:
cost will have a length in the range [2, 1000].
Every cost[i] will be an integer in the range [0, 999].

基本上就是最简单的动态规划了，dp[0] = dp[1] = 0
dp[i] = min((dp[i-1] + cost[i-1]), (dp[i - 2] + cost[i - 2]))

最后return dp[n]
"""


class Solution(object):
    def minCostClimbingStairs(self, cost):
        """
        :type cost: List[int]
        :rtype: int
        """
        n = len(cost)
        dp = [0] * (n + 1)
        for i in range(2, n + 1):
            dp[i] = min((dp[i - 1] + cost[i - 1]), (dp[i - 2] + cost[i - 2]))
        return dp[n]
