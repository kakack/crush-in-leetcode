// A perfect number is a positive integer that is equal to the sum of its positive divisors, excluding the number itself. A divisor of an integer x is an integer that can divide x evenly.

// Given an integer n, return true if n is a perfect number, otherwise return false.

 

// Example 1:

// Input: num = 28
// Output: true
// Explanation: 28 = 1 + 2 + 4 + 7 + 14
// 1, 2, 4, 7, and 14 are all divisors of 28.
// Example 2:

// Input: num = 7
// Output: false
 

// Constraints:

// 1 <= num <= 10^8

bool checkPerfectNumber(int num){
    if (num <= 0) {
        return false;
    }
    int res = 0;
    int i = 1;
    while (i <= sqrt(num)) {
        if (num % i == 0) {
            res += i;
            if (pow(i, 2) != num) {
                res += num / i;
            }
        }
        i ++;
    }
    if (res == 2 * num) {
        return true;
    } else {
        return false;
    }
}