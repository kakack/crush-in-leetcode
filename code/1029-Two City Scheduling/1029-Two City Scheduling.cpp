// A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti], the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

// Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.

 

// Example 1:

// Input: costs = [[10,20],[30,200],[400,50],[30,20]]
// Output: 110
// Explanation: 
// The first person goes to city A for a cost of 10.
// The second person goes to city A for a cost of 30.
// The third person goes to city B for a cost of 50.
// The fourth person goes to city B for a cost of 20.

// The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
// Example 2:

// Input: costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
// Output: 1859
// Example 3:

// Input: costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
// Output: 3086
 

// Constraints:

// 2 * n == costs.length
// 2 <= costs.length <= 100
// costs.length is even.
// 1 <= aCosti, bCosti <= 1000

//  首先将这 2N2N 个人全都安排飞往 BB 市，
// 再选出 NN 个人改变它们的行程，让他们飞往 AA 市。
// 如果选择改变一个人的行程，那么公司将会额外付出 price_A - price_B 的费用，这个费用可正可负。
// 因此最优的方案是，选出 price_A - price_B 最小的 NN 个人，让他们飞往 A 市，其余人飞往 B 市。


//  按照 price_A - price_B 从小到大排序；

// 将前 NN 个人飞往 A 市，其余人飞往 B 市，并计算出总费用。

class Solution {
    public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        sort(costs.begin(), costs.end(), [](const vector<int> &o1, const vector<int> &o2) {
            return (o1[0] - o1[1] < o2[0] - o2[1]);
        });
        int total = 0;
        int n = costs.size() / 2;
        for (int i = 0; i < n; i ++) {
            total += costs[i][0] + costs[i + n][1];
        }
        return total;
    }
};