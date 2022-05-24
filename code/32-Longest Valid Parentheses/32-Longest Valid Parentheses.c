/*Longest Valid Parentheses
Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.

For "(()", the longest valid parentheses substring is "()", which has length = 2.

Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.

维护一个堆栈，我之前大体思路是对的，但是在怎么计算结果上有问题
*/


int longestValidParentheses(char* s) {
    int maxans = 0, n = strlen(s);
    int stk[n + 1], top = -1;
    stk[++top] = -1;
    for (int i = 0; i < n; i++) {
        if (s[i] == '(') {
            stk[++top] = i;
        } else {
            --top;
            if (top == -1) {
                stk[++top] = i;
            } else {
                maxans = fmax(maxans, i - stk[top]);
            }
        }
    }
    return maxans;
}