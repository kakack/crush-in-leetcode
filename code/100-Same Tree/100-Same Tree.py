"""
LeetCode 100 - Same Tree

解题步骤（自动整理）
1. 根据题意选择前序/中序/后序遍历方式遍历二叉树
2. 在遍历过程中维护需要的状态（路径和、深度、父子关系等）
3. 遍历完成后返回答案
"""
# Given two binary trees, write a function to check if they are the same or not.
#
# Two binary trees are considered the same if they are structurally identical and the nodes have the same value.
#
# Example 1:
#
# Input:     1         1
#           / \       / \
#          2   3     2   3
#
#         [1,2,3],   [1,2,3]
#
# Output: true
# Example 2:
#
# Input:     1         1
#           /           \
#          2             2
#
#         [1,2],     [1,null,2]
#
# Output: false
# Example 3:
#
# Input:     1         1
#           / \       / \
#          2   1     1   2
#
#         [1,2,1],   [1,1,2]
#
# Output: false

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def isSameTree(self, p, q):
        """
        :type p: TreeNode
        :type q: TreeNode
        :rtype: bool
        """
        if not q and not p:
            return True
        elif not q and p:
            return False
        elif not p and q:
            return False
        else:
            return p.val == q.val and self.isSameTree(p.left,  q.left) and self.isSameTree(p.right, q.right)
