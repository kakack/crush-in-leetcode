"""
LeetCode 105 - Construct Binary Tree from Preorder and Inorder Traversal

解题步骤（自动整理）
1. 根据题意选择前序/中序/后序遍历方式遍历二叉树
2. 在遍历过程中维护需要的状态（路径和、深度、父子关系等）
3. 遍历完成后返回答案
"""
# Given preorder and inorder traversal of a tree, construct the binary tree.
#
# Note:
# You may assume that duplicates do not exist in the tree.
#
# For example, given
#
# preorder = [3,9,20,15,7]
# inorder = [9,3,15,20,7]
# Return the following binary tree:
#
#     3
#    / \
#   9  20
#     /  \
#    15   7

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def buildTree(self, preorder, inorder):
        """
        :type preorder: List[int]
        :type inorder: List[int]
        :rtype: TreeNode
        """
        def buildBinaryTree(preorder, preStart, preEnd, inorder, inStart, inEnd):
            if preStart > preEnd or inStart > inEnd:
                return None
            root = TreeNode(preorder[preStart])
            if preStart == preEnd and inStart == inEnd:
                return root
            rootIndex = 0
            for i in range(inStart, inEnd + 1):
                if inorder[i] == preorder[preStart]:
                    rootIndex = i
            numLeft = rootIndex - inStart
            root.left = buildBinaryTree(preorder, preStart + 1, preStart + numLeft, inorder, inStart, rootIndex - 1)
            root.right = buildBinaryTree(preorder, preStart + numLeft +1, preEnd, inorder, rootIndex + 1, inEnd)
            return root

        if len(preorder) != len(inorder):
            return None
        else:
            return buildBinaryTree(preorder, 0, len(preorder) - 1, inorder, 0, len(inorder) - 1)
