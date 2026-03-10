/*
LeetCode 135 - Candy

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*
There are N children standing in a line. Each child is assigned a rating value.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
What is the minimum candies you must give?

左右各扫描一遍，从左边扫的时候保证右侧邻居rating高的拿到多一个糖，从右边扫的时候保证左边邻居rating高的拿到多一个糖
*/

class Solution {
public:
    int candy(vector<int> &ratings) {
        int n = ratings.size();

        vector<int> candy(n);

        for(int i=1,inc =1;i<n;i++){
            if(ratings[i]>ratings[i-1])
              candy[i]=max(inc++,candy[i]);
            else
              inc=1;
        }

        for(int i=n-2,inc=1;i>=0;i--){
            if(ratings[i]>ratings[i+1])
               candy[i]=max(inc++,candy[i]);
             else
               inc=1;
        }


        int result=n;
        for(int i=0;i<n;i++)
           result+=candy[i];

        return result;


    }
};
