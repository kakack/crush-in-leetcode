"""
LeetCode 125 - Valid Palindrome

解题步骤（自动整理）
1. 将起点/初始层入队，并用 visited 或原地标记避免重复访问
2. 按层或按队列弹出元素扩展相邻节点，满足条件时更新答案
3. 队列处理完毕后返回结果（或在首次到达目标时提前返回）
"""
# Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
#
# Note: For the purpose of this problem, we define empty string as valid palindrome.
#
# Example 1:
# Input: "A man, a plan, a canal: Panama"
# Output: true
#
# Example 2:
# Input: "race a car"
# Output: false

class Solution(object):
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        deque = []
        for char in s:
            if char.isalpha() or char.isdigit():
                deque.append(char.lower())
        while len(deque) > 1:
            if deque.pop(0) != deque.pop(-1):
                return False
        return True
