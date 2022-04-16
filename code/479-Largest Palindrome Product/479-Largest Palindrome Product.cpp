// Given an integer n, return the largest palindromic integer that can be represented as the product of two n-digits integers. Since the answer can be very large, return it modulo 1337.

 

// Example 1:

// Input: n = 2
// Output: 987
// Explanation: 99 x 91 = 9009, 9009 % 1337 = 987
// Example 2:

// Input: n = 1
// Output: 9
 

// Constraints:

// 1 <= n <= 8

class Solution {
public:
    int largestPalindrome(int n) {
        if (n == 1) {
            return 9
        }
        int upper = pow(10, n) - 1;
        for (int left = upper; ;left --) {
            long p = left;
            for (int x = left; x > 0; x /= 10) {
                p = p * 10 + x % 10;
            }
            for (long x = upper; x * x >= p; x --) {
                if (p % x == 0) {
                    return p % 1337;
                }
            }
        }
    }
};