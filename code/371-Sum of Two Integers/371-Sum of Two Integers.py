# -*- coding: utf-8 -*
"""
@author: Kai Chen
@file: 371-Sum of Two Integers.py
@time: 2020/8/7 10:21
@desc:
Calculate the sum of two integers a and b, but you are not allowed to use the operator + and -.

Example 1:

Input: a = 1, b = 2
Output: 3
Example 2:

Input: a = -2, b = 3
Output: 1
"""


class Solution(object):
    def getSum(self, a, b):
        """
        :type a: int
        :type b: int
        :rtype: int
        """
        MASK = 0x100000000
        MAX_INT = 0x7FFFFFFF
        MIN_INT = MAX_INT + 1
        while b != 0:
            carry = (a & b) << 1 # 进位计算，取和运算然后往左进一位
            a = (a ^ b) % MASK
            b = carry % MASK
        return a if a <= MAX_INT else ~((a % MIN_INT) ^ MAX_INT)

    """
    a if a <= MAX_INT else ~((a % MIN_INT) ^ MAX_INT)   
~((a % MIN_INT) ^ MAX_INT) 其实可以简化为~(a ^ mask) 为什么要对负数做这样的处理呢？ 因为在python中int不是32位的，输出是64位，所以一个负数比如-2, 64位表示就是0x00000000FFFFFFFE, 用python求取这个16进制的值int('0x00000000FFFFFFFE', 16), 得到的数字是4294967294 不是我们想要的-2，所以： a^mask是先对a的前32位取反，对应-2，就得到0x0000000000000002 再用～操作符对所以位置取反，对应-2，得到0xFFFFFFFFFFFFFFFE

总结一下就是，由于oj系统python最后返回的是64位，如果不对负数特殊处理，那么负数的前32位是0，最后输出的是大于32位的正数
    """


if __name__ == '__main__':
    s = Solution()
    print(s.getSum(1, 2))
    print(s.getSum(-2, 3))