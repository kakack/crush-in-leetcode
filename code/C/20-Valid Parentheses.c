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