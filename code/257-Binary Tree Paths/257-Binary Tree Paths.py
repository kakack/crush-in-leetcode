# -*- coding: utf-8 -*
"""
LeetCode 257 - Binary Tree Paths

解题步骤（自动整理）
1. 将起点/初始层入队，并用 visited 或原地标记避免重复访问
2. 按层或按队列弹出元素扩展相邻节点，满足条件时更新答案
3. 队列处理完毕后返回结果（或在首次到达目标时提前返回）
"""
r"""
@author: Kai Chen
@file: 257-Binary Tree Paths.py
@time: 2020/9/4 10:14
@desc:
Given a binary tree, return all root-to-leaf paths.

Note: A leaf is a node with no children.

Example:

Input:

   1
 /   \
2     3
 \
  5

Output: ["1->2->5", "1->3"]

Explanation: All root-to-leaf paths are: 1->2->5, 1->3
"""


from collections import deque

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution(object):

    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        dfs
        """
        result, path = [], ''

        def dfs(root, path):
            if root:
                path += str(root.val)
                if not root.left and not root.right:
                    result.append(path)
                else:
                    path += '->'
                    dfs(root.left, path)
                    dfs(root.right, path)
        dfs(root, path)
        return result

    def binaryTreePaths(self, root):
        """
        :type root: TreeNode
        :rtype: List[str]
        bfs
        """
        result = []
        if not root:
            return result
        node_queue = deque([root])
        path_queue = deque([str(root.val)])

        while node_queue:
            node = node_queue.popleft()
            path = path_queue.popleft()

            if not node.left and not node.right:
                result.append(path)
            else:
                if node.left:
                    node_queue.append(node.left)
                    path_queue.append(path + '->' + str(node.left.val))
                if node.right:
                    node_queue.append(node.right)
                    path_queue.append(path + '->' + str(node.right.val))
        return result

