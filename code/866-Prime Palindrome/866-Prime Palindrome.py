# Given an integer n, return the smallest prime palindrome greater than or equal to n.

# An integer is prime if it has exactly two divisors: 1 and itself. Note that 1 is not a prime number.

# For example, 2, 3, 5, 7, 11, and 13 are all primes.
# An integer is a palindrome if it reads the same from left to right as it does from right to left.

# For example, 101 and 12321 are palindromes.
# The test cases are generated so that the answer always exists and is in the range [2, 2 * 108].

 

# Example 1:

# Input: n = 6
# Output: 7
# Example 2:

# Input: n = 8
# Output: 11
# Example 3:

# Input: n = 13
# Output: 101
 

# Constraints:

# 1 <= n <= 10^8

class Solution:
    def primePalindrome(self, N: int) -> int:
        def is_prime(n):
            return n > 1 and all(n%d for d in range(2, int(n**.5) + 1))

        for length in range(1, 6):
            #Check for odd-length palindromes
            for root in range(10**(length - 1), 10**length):
                s = str(root)
                x = int(s + s[-2::-1]) #eg. s = '123' to x = int('12321')
                if x >= N and is_prime(x):
                    return x
                    #If we didn't check for even-length palindromes:
                    #return min(x, 11) if N <= 11 else x

            #Check for even-length palindromes
            for root in range(10**(length - 1), 10**length):
                s = str(root)
                x = int(s + s[-1::-1]) #eg. s = '123' to x = int('123321')
                if x >= N and is_prime(x):
                    return x

class Solution:
    def primePalindrome(self, n: int) -> int:
        def is_prime(n):
            return n > 1 and all(n % d for d in xrange(2, int(n**.5) + 1))
        
        def reverse(n):
            ans = 0
            while n:
                ans = 10 * ans + n % 10
                n /= 10
            return ans
        
        while 1:
            if n == reverse(n) and is_prime(n):
                return n
            n += 1
            if 10 ** 7 < n < 10 ** 8:
                n = 10 ** 8 
