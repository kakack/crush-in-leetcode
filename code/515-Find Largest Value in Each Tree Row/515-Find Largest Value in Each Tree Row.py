"""
LeetCode 515 - Find Largest Value in Each Tree Row

解题步骤（自动整理）
1. 根据题意选择前序/中序/后序遍历方式遍历二叉树
2. 在遍历过程中维护需要的状态（路径和、深度、父子关系等）
3. 遍历完成后返回答案
"""
# Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).



# Example 1:


# Input: root = [1,3,2,5,3,null,9]
# Output: [1,3,9]
# Example 2:

# Input: root = [1,2,3]
# Output: [1,3]


# Constraints:

# The number of nodes in the tree will be in the range [0, 104].
# -231 <= Node.val <= 231 - 1

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def largestValues(self, root: Optional[TreeNode]) -> List[int]:
        res, nodes = [], [root]
        if not root:
            return res
        while nodes:
            size = len(nodes)
            maxVal = float("-inf")
            while size > 0:
                node = nodes.pop(0)
                if node.left:
                    nodes.append(node.left)
                if node.right:
                    nodes.append(node.right)
                maxVal = max(maxVal, node.val)
                size -= 1
            res.append(maxVal)
        return res
