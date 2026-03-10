"""
LeetCode 237 - Delete Node in a Linked List

解题步骤（自动整理）
1. 用快慢指针/虚拟头节点等技巧处理链表边界
2. 按题意进行遍历、反转、合并或断链等操作
3. 返回处理后的链表头节点或计算结果
"""
# Write
# a
# function
# to
# delete
# a
# node(except the
# tail) in a
# singly
# linked
# list, given
# only
# access
# to
# that
# node.
#
#     Given
# linked
# list - - head = [4, 5, 1, 9], which
# looks
# like
# following:
#
# Example
# 1:
#
# Input: head = [4, 5, 1, 9], node = 5
# Output: [4, 1, 9]
# Explanation: You
# are
# given
# the
# second
# node
# with value 5, the linked list should become 4 -> 1 -> 9 after calling your function.
# Example 2:
#
#     Input: head = [4, 5, 1, 9], node = 1
# Output: [4, 5, 9]
# Explanation: You
# are
# given
# the
# third
# node
# with value 1, the linked list should become 4 -> 5 -> 9 after calling your function.


# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def deleteNode(self, node):
        """
        :type node: ListNode
        :rtype: void Do not return anything, modify node in-place instead.
        """
        node.val = node.next.val
        node.next = node.next.next
