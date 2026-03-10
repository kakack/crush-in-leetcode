"""
LeetCode 24 - Swap Nodes in Pairs

解题步骤（自动整理）
1. 用快慢指针/虚拟头节点等技巧处理链表边界
2. 按题意进行遍历、反转、合并或断链等操作
3. 返回处理后的链表头节点或计算结果
"""
# Given a linked list, swap every two adjacent nodes and return its head.
#
# You may not modify the values in the list's nodes, only nodes itself may be changed.
#
# Example:
#
# Given 1->2->3->4, you should return the list as 2->1->4->3.

# Definition for singly-linked list.
class ListNode(object):
    def __init__(self, x):
        self.val = x
        self.next = None

class Solution(object):
    def swapPairs(self, head):
        """
        :type head: ListNode
        :rtype: ListNode
        """
        pre = tmp = ListNode()
        pre.next = head
        while tmp.next and tmp.next.next:
            a = tmp.next
            b = tmp.next.next
            c = tmp.next.next.next
            tmp.next = b
            b.next = a
            a.next = c
            tmp = tmp.next.next
        return pre.next
