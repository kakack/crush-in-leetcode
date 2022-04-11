// Given an integer n, return the count of all numbers with unique digits, x, where 0 <= x < 10n.

 

// Example 1:

// Input: n = 2
// Output: 91
// Explanation: The answer should be the total numbers in the range of 0 ≤ x < 100, excluding 11,22,33,44,55,66,77,88,99
// Example 2:

// Input: n = 0
// Output: 1
 

// Constraints:

// 0 <= n <= 8

/*
n = 0, return 1
n = 1, return 10
d(2<= d <= 10), 9 x A^(d-1)_9

*/

int countNumbersWithUniqueDigits(int n) {
    if (n == 0) {
        return 1;
    }
    if (n == 1) {
        return 10;
    }
    int ans = 10, cur = 9;
    for (int i = 0; i < n - 1; ++i) {
        cur *= 9 - i;
        ans += cur;
    }
    return ans;
}
