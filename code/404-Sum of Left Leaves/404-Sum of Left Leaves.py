"""
LeetCode 404 - Sum of Left Leaves

解题步骤（自动整理）
1. 维护栈（或单调栈）保存候选元素的下标/值
2. 遍历序列时根据出栈条件更新答案，再将当前元素入栈
3. 遍历结束后处理剩余元素（如需要）并返回结果
"""
# Find the sum of all left leaves in a given binary tree.
#
# Example:
#
#     3
#    / \
#   9  20
#     /  \
#    15   7
#
# There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.

# Definition for a binary tree node.
class TreeNode(object):
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution(object):
    def sumOfLeftLeaves(self, root):
        """
        :type root: TreeNode
        :rtype: int
        """
        # if not root:
        #     return 0
        # stack = [root]
        # res = 0
        # while stack:
        #     cur = stack.pop()
        #     if cur:
        #         if cur.left and not cur.left.left and not cur.left.right:
        #             res += cur.left.val
        #         stack.append(cur.left)
        #         stack.append(cur.right)
        # return res


        self.res = 0
        def sumLeft(root):
            if not root:
                return 0
            if root.left and not root.left.left and not root.left.right:
                self.res += root.left.val
            sumLeft(root.left)
            sumLeft(root.right)
        sumLeft(root)
        return self.res



