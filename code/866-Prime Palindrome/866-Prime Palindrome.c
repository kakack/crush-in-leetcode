// Given an integer n, return the smallest prime palindrome greater than or equal to n.

// An integer is prime if it has exactly two divisors: 1 and itself. Note that 1 is not a prime number.

// For example, 2, 3, 5, 7, 11, and 13 are all primes.
// An integer is a palindrome if it reads the same from left to right as it does from right to left.

// For example, 101 and 12321 are palindromes.
// The test cases are generated so that the answer always exists and is in the range [2, 2 * 108].

 

// Example 1:

// Input: n = 6
// Output: 7
// Example 2:

// Input: n = 8
// Output: 11
// Example 3:

// Input: n = 13
// Output: 101
 

// Constraints:

// 1 <= n <= 10^8

bool isPrime(int n) {
    if (n < 2) {
        return false;
    }
    int r = sqrt(n);
    for (int i = 2; i <= r; i ++) {
        if (n % i == 0) {
            return false;
        } 
    }
    return true;
}

int reverse(int n) {
    int ans = 0;
    while (n > 0) {
        ans = 10 * ans + n % 10;
        n /= 10;
    }
    return ans;
}

int primePalindrome(int n){
    while (true) {
        if (n == reverse(n) && isPrime(n)) {
            return n;
        }
        n ++;
        if (10000000 < n && n < 100000000){
            n = 100000000;
        }
    }
}
