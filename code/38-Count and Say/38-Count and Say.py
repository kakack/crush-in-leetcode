"""
LeetCode 38 - Count and Say

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# The count-and-say sequence is the sequence of integers with the first five terms as following:
#
# 1.     1
# 2.     11
# 3.     21
# 4.     1211
# 5.     111221
# 1 is read off as "one 1" or 11.
# 11 is read off as "two 1s" or 21.
# 21 is read off as "one 2, then one 1" or 1211.
#
# Given an integer n where 1 ≤ n ≤ 30, generate the nth term of the count-and-say sequence. You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.
#
# Note: Each term of the sequence of integers will be represented as a string.
#
# Example 1:
# Input: 1
# Output: "1"
# Explanation: This is the base case.

# Example 2:
# Input: 4
# Output: "1211"
# Explanation: For n = 3 the term was "21" in which we have two groups "2" and "1", "2" can be read as "12" which means frequency = 1 and value = 2, the same way "1" is read as "11", so the answer is the concatenation of "12" and "11" which is "1211".


class Solution(object):
    def trans(self, str):
        res = ''
        pre = ''
        count = 1
        for c in str[::-1]:
            if c != pre:
                pre = c
                res = c + count.__str__() + res
                count = 1
            else:
                count += 1
        n = len(res) - 1
        res = count.__str__() + res[:n]
        return res


    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n == 1:
            return '1'
        else:
            return self.trans(self.countAndSay(n - 1))

if __name__ == '__main__':
    s = Solution()
    for _ in range(1, 7):
        print(s.countAndSay(_))
