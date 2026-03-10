"""
LeetCode 572 - Subtree of Another Tree

解题步骤（自动整理）
1. 根据题意选择前序/中序/后序遍历方式遍历二叉树
2. 在遍历过程中维护需要的状态（路径和、深度、父子关系等）
3. 遍历完成后返回答案
"""
# Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
#
# Example 1:
# Given tree s:
#
#      3
#     / \
#    4   5
#   / \
#  1   2
# Given tree t:
#    4
#   / \
#  1   2
# Return true, because t has the same structure and node values with a subtree of s.
# Example 2:
# Given tree s:
#
#      3
#     / \
#    4   5
#   / \
#  1   2
#     /
#    0
# Given tree t:
#    4
#   / \
#  1   2
# Return false.

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def compare(self, a, b):
        if a is None and b is None:
            return True
        if a is None or b is None:
            return False
        return (
            a.val == b.val
            and self.compare(a.left, b.left)
            and self.compare(a.right, b.right)
        )


    def isSubtree(self, s, t):
        """
        :type s: TreeNode
        :type t: TreeNode
        :rtype: bool
        """
        if s is None:
            return False
        return self.compare(s, t) or self.isSubtree(s.left, t) or self.isSubtree(s.right, t)
