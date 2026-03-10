/*
LeetCode 20 - Valid Parentheses

解题步骤（自动整理）
1. 维护栈（或单调栈）保存候选元素的下标/值
2. 遍历序列时根据出栈条件更新答案，再将当前元素入栈
3. 遍历结束后处理剩余元素（如需要）并返回结果
*/
/*
Valid Parentheses

Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.
*/

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;

        if(s.length()==0||s[0]==')'||s[0]==']'||s[0]=='}')
          return false;
        else
          stack.push_back(s[0]);

        for(int i=1;i<s.length();i++){
            if(s[i]=='('||s[i]=='['||s[i]=='{'){
              stack.push_back(s[i]);
              continue;
            }

            char cur=stack.back();

            if(s[i]==')'&&cur!='(')
               return false;
            if(s[i]==']'&&cur!='[')
               return false;
            if(s[i]=='}'&&cur!='{')
               return false;

            stack.pop_back();
        }

        if(stack.size()!=0)
          return false;
        else
          return true;


    }
};
