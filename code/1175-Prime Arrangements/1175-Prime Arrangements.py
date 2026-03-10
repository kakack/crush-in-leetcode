"""
LeetCode 1175 - Prime Arrangements

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Return the number of permutations of 1 to n so that prime numbers are at prime indices (1-indexed.)

# (Recall that an integer is prime if and only if it is greater than 1, and cannot be written as a product of two positive integers both smaller than it.)

# Since the answer may be large, return the answer modulo 10^9 + 7.



# Example 1:

# Input: n = 5
# Output: 12
# Explanation: For example [1,2,5,4,3] is a valid permutation, but [5,2,3,4,1] is not because the prime number 5 is at index 1.
# Example 2:

# Input: n = 100
# Output: 682289015


# Constraints:

# 1 <= n <= 100

class Solution:
    def numPrimeArrangements(self, n: int) -> int:
        def isPrime(n: int) -> int:
            if n == 1:
                return 0
            for i in range(2, int(sqrt(n) + 1)):
                if n % i == 0:
                    return 0
            return 1

        def factorial(n: int) -> int:
            res = 1
            for i in range(1, n + 1):
                res *= i
                res %= (10 ** 9 + 7)
            return res
        numPrimes = sum(isPrime(i) for i in range(1, n + 1))
        return factorial(numPrimes) * factorial(n - numPrimes) % (10 ** 9 + 7)
