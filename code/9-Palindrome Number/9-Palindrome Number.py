"""
LeetCode 9 - Palindrome Number

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Determine whether an integer is a palindrome. Do this without extra space.

# click to show spoilers.

# Some hints:
# Could negative integers be palindromes? (ie, -1)

# If you are thinking of converting the integer to string, note the restriction of using extra space.

# You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?

# There is a more generic way of solving this problem.

# 因为不能用额外空间，所以不能用专程String的办法，单纯在x上做取余和除法计算，得到首位和末位

class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0:
            return False
        l = 1
        while x/l >= 10:
            l *= 10
        while x:
            if x%10 != x/l:
                return False
            else:
                x = (x % l) / 10
                l /= 100
        return True

