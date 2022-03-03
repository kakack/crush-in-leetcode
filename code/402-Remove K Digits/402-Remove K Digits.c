// Given string num representing a non-negative integer num, and an integer k, return the smallest possible integer after removing k digits from num.

 

// Example 1:

// Input: num = "1432219", k = 3
// Output: "1219"
// Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
// Example 2:

// Input: num = "10200", k = 1
// Output: "200"
// Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
// Example 3:

// Input: num = "10", k = 2
// Output: "0"
// Explanation: Remove all the digits from the number and it is left with nothing which is 0.
 

// Constraints:

// 1 <= k <= num.length <= 10^5
// num consists of only digits.
// num does not have any leading zeros except for the zero itself.

char* removeKdigits(char* num, int k) {
    int n = strlen(num), top = 0;
    char* stk = malloc(sizeof(char) * (n + 1));
    for (int i = 0; i < n; i++) {
        while (top > 0 && stk[top] > num[i] && k) {
            top--, k--;
        }
        stk[++top] = num[i];
    }
    top -= k;

    char* ans = malloc(sizeof(char) * (n + 1));
    int ansSize = 0;
    bool isLeadingZero = true;
    for (int i = 1; i <= top; i++) {
        if (isLeadingZero && stk[i] == '0') {
            continue;
        }
        isLeadingZero = false;
        ans[ansSize++] = stk[i];
    }
    if (ansSize == 0) {
        ans[0] = '0', ans[1] = 0;
    } else {
        ans[ansSize] = 0;
    }
    return ans;
}
