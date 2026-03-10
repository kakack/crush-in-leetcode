"""
LeetCode 1305 - All Elements in Two Binary Search Trees

解题步骤（自动整理）
1. 用 DFS/递归遍历二叉树，在递归返回值中携带子树信息
2. 在当前节点聚合左右子树结果并完成题目要求的判断/更新
3. 递归结束后返回根节点对应的结果
"""
# Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.



# Example 1:


# Input: root1 = [2,1,4], root2 = [1,0,3]
# Output: [0,1,1,2,3,4]
# Example 2:


# Input: root1 = [1,null,8], root2 = [8,1]
# Output: [1,1,8,8]


# Constraints:

# The number of nodes in each tree is in the range [0, 5000].
# -10^5 <= Node.val <= 10^5

# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        nodes1, nodes2 = list(), list()

        def dfs(root, nodes):
            if root == None:
                return
            dfs(root.left, nodes)
            nodes.append(root.val)
            dfs(root.right, nodes)
        dfs(root1, nodes1)
        dfs(root2, nodes2)
        p1, n1 = 0, len(nodes1)
        p2, n2 = 0, len(nodes2)
        res = list()
        while True:
            if p1 == n1:
                res.extend(nodes2[p2:])
                break
            elif p2 == n2:
                res.extend(nodes1[p1:])
                break
            elif nodes1[p1] < nodes2[p2]:
                res.append(nodes1[p1])
                p1 += 1
            else:
                res.append(nodes2[p2])
                p2 += 1
        return res
