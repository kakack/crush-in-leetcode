/*
LeetCode 22 - Generate Parentheses

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*
Generate Parentheses

Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

"((()))", "(()())", "(())()", "()(())", "()()()"

*/

class Solution {
public:
    vector<string> ans;
     void rec(int left,int right,string s){

            if(left==0&&right==0){
                this->ans.push_back(s);
                return;
            }
            if(left==0){
                rec(0,right-1,s+")");
                return;
            }
            if(right==0||left>right)
                return;

            rec(left-1,right,s+"(");
            rec(left,right-1,s+")");

        }
    vector<string> generateParenthesis(int n) {

        rec(n,n,"");
        return this->ans;


    }
};
