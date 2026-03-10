/*
LeetCode 20 - Valid Parentheses

解题步骤（自动整理）
1. 维护栈（或单调栈）保存候选元素的下标/值
2. 遍历序列时根据出栈条件更新答案，再将当前元素入栈
3. 遍历结束后处理剩余元素（如需要）并返回结果
*/
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.


// Example 1:

// Input: s = "()"
// Output: true
// Example 2:

// Input: s = "()[]{}"
// Output: true
// Example 3:

// Input: s = "(]"
// Output: false


// Constraints:

// 1 <= s.length <= 10^4
// s consists of parentheses only '()[]{}'.

bool isValid(char * s){
    char* stack = malloc(sizeof(char) * 10001);
    int n = strlen(s);
    int stackTop = 0;

    for (int i = 0; i < n; i ++) {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
            stack[stackTop ++] = s[i];
        } else {
            if (stackTop == 0) {
                return false;
            }
            bool flag1 = (s[i] == ')' && stack[stackTop - 1] != '(');
            bool flag2 = (s[i] == ']' && stack[stackTop - 1] != '[');
            bool flag3 = (s[i] == '}' && stack[stackTop - 1] != '{');
            if (flag1 || flag2 || flag3 ) {
                return false;
            } else {
                stackTop --;
            }
        }
    }
    return stackTop == 0? true : false;
}
