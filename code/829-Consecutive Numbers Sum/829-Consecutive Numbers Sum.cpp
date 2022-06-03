// Given an integer n, return the number of ways you can write n as the sum of consecutive positive integers.

 

// Example 1:

// Input: n = 5
// Output: 2
// Explanation: 5 = 2 + 3
// Example 2:

// Input: n = 9
// Output: 3
// Explanation: 9 = 4 + 5 = 2 + 3 + 4
// Example 3:

// Input: n = 15
// Output: 4
// Explanation: 15 = 8 + 7 = 4 + 5 + 6 = 1 + 2 + 3 + 4 + 5
 

// Constraints:

// 1 <= n <= 10^9

class Solution {
private:
    bool isKConsecutive(int n, int k) {
        if (k % 2 == 1) {
            return n % k == 0;
        } else {
            return n % k != 0 && 2 *n % k == 0;
        }
    }
public:
    int consecutiveNumbersSum(int n) {
        int res = 0;
        int bound = 2 * n;
        for (int i = 1; i * (i + 1) <= bound; i ++) {
            if (isKConsecutive(n, i)) {
                res ++;
            }
        }
        return res;
    }
};