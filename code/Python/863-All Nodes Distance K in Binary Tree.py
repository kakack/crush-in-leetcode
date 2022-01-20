# Given the root of a binary tree, the value of a target node target, and an integer k, return an array of the values of all nodes that have a distance k from the target node.
#
# You can return the answer in any order.
#
#
#
# Example 1:
#
#
# Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, k = 2
# Output: [7,4,1]
# Explanation: The nodes that are a distance 2 from the target node (with value 5) have values 7, 4, and 1.
# Example 2:
#
# Input: root = [1], target = 1, k = 3
# Output: []
#
#
# Constraints:
#
# The number of nodes in the tree is in the range [1, 500].
# 0 <= Node.val <= 500
# All the values Node.val are unique.
# target is the value of one of the nodes in the tree.
# 0 <= k <= 1000


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

from collections import defaultdict

class Solution(object):
    def distanceK(self, root, target, k):
        """
        :type root: TreeNode
        :type target: TreeNode
        :type k: int
        :rtype: List[int]
        """
        parents = defaultdict(int)
        ans = []

        def findParents(node):
            if node.left:
                parents[node.left.val] = node
                findParents(node.left)
            if node.right:
                parents[node.right.val] = node
                findParents(node.right)

        findParents(root)

        def findAns(node, front, depth, k):
            if not node:
                return None
            if depth == k:
                ans.append(node.val)
                return None
            if node.left != front:
                findAns(node.left, node, depth + 1, k)
            if node.right != front:
                findAns(node.right, node, depth + 1, k)
            if parents[node.val] != front:
                findAns(parents[node.val], node, depth + 1, k)

        findAns(target, None, 0, k)
        return ans
