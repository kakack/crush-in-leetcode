# -*- coding: utf-8 -*
"""
LeetCode 203 - Remove Linked List Elements

解题步骤（自动整理）
1. 用快慢指针/虚拟头节点等技巧处理链表边界
2. 按题意进行遍历、反转、合并或断链等操作
3. 返回处理后的链表头节点或计算结果
"""

r"""
@author: Kai Chen
@file: 203-Remove Linked List Elements.py
@time: 2020/6/19 10:54
@desc:
"""

# Remove all elements from a linked list of integers that have value val.
#
# Example:
#
# Input:  1->2->6->3->4->5->6, val = 6
# Output: 1->2->3->4->5

# Definition for singly-linked list.

class ListNode(object):
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution(object):
    def removeElements(self, head, val):
        """
        :type head: ListNode
        :type val: int
        :rtype: ListNode
        """
        sentinel = ListNode(0)
        sentinel.next = head

        pre, cur = sentinel, head
        while cur:
            if cur.val == val:
                pre.next = cur.next
            else:
                pre = cur
            cur = cur.next
        return sentinel.next
