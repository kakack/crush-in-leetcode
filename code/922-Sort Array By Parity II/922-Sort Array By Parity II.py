# -*- coding: utf-8 -*
"""
@author: Kai Chen
@file: 922-Sort Array By Parity II.py
@time: 2020/11/12 9:22
@desc:
Given an array A of non-negative integers, half of the integers in A are odd, and half of the integers are even.

Sort the array so that whenever A[i] is odd, i is odd; and whenever A[i] is even, i is even.

You may return any answer array that satisfies this condition.



Example 1:

Input: [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.


Note:

2 <= A.length <= 20000
A.length % 2 == 0
0 <= A[i] <= 1000

"""


class Solution(object):
    def sortArrayByParityII(self, A):
        """
        :type A: List[int]
        :rtype: List[int]
        """
        # even, odd, res = [], [], []
        # for i in A:
        #     if i % 2 == 0:
        #         even.append(i)
        #     else:
        #         odd.append(i)
        # for i in range(len(odd)):
        #     res.append(even[i])
        #     res.append(odd[i])
        # return res
        n = len(A)
        j = 1
        for i in range(0, n, 2):
            if A[i] % 2 == 1:
                while A[j] % 2 == 1:
                    j += 2
                A[i], A[j] = A[j], A[i]
        return A
