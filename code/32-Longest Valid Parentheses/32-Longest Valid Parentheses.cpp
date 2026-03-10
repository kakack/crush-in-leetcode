/*
LeetCode 32 - Longest Valid Parentheses

解题步骤（自动整理）
1. 定义状态（dp[i] 或 dp[i][j]）来表示子问题的最优解/可行性
2. 写出状态转移方程，并处理边界初始化
3. 按依赖顺序递推（必要时滚动数组优化空间），得到最终答案
*/
/*Longest Valid Parentheses
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

维护一个堆栈，我之前大体思路是对的，但是在怎么计算结果上有问题
*/

#include <iostream>
#include <stack>
#include <algorithm>

using namespace std;

 int longestValidParentheses(string s) {
        stack<int> st;
        int max_len=0,last=-1;
        const int len=s.size();

        for(int i=0;i<len;i++){

	       if(s[i]=='(')
	           st.push(i);
	       else if (s[i]==')') {
		      if(st.empty())
		         last=i;//更新找到的最后一个')'位置
		      else{//找到一一对'('
			     st.pop();
			     if(st.empty())
			        max_len=max(max_len,i-last);
			     else
			        max_len=max(max_len,i-st.top());
		   }
	    }
    }

    return max_len;

    }
int main(int argc, char *argv[]) {
	cout<<longestValidParentheses("(()");
}
