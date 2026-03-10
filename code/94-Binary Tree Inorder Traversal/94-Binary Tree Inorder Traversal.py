# -*- coding: utf-8 -*
"""
LeetCode 94 - Binary Tree Inorder Traversal

解题步骤（自动整理）
1. 根据题意选择前序/中序/后序遍历方式遍历二叉树
2. 在遍历过程中维护需要的状态（路径和、深度、父子关系等）
3. 遍历完成后返回答案
"""
r"""
@author: Kai Chen
@file: 94-Binary Tree Inorder Traversal.py
@time: 2020/7/29 9:50
@desc:
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
"""


# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
class Solution(object):
    def inorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        res = []
        def travel(root_):
            if root_ is None:
                return
            else:
                travel(root_.left)
                res.append(root_.val)
                travel(root_.right)

        travel(root)
        return res
