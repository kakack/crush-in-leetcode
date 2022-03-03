// Given a positive integer, check whether it has alternating bits: namely, if two adjacent bits will always have different values.

 

// Example 1:

// Input: n = 5
// Output: true
// Explanation: The binary representation of 5 is: 101
// Example 2:

// Input: n = 7
// Output: false
// Explanation: The binary representation of 7 is: 111.
// Example 3:

// Input: n = 11
// Output: false
// Explanation: The binary representation of 11 is: 1011.
 

// Constraints:

// 1 <= n <= 2^31 - 1

class Solution {
public:
    bool hasAlternatingBits(int n) {
        int base1 = 0, base2 = 0;
    for (int i = 0; i <= 15; i++) {
        base1 <<= 2;
        base1 += 1;
        base2 <<= 2;
        base2 += 2;
        }
        long xor1 = base1 ^ n, xor2 = base2 ^ n;
    return (xor1 & (-xor1)) > n || (xor2 & (-xor2)) > n || n == 1431655765;
    }
};