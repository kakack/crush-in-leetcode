"""
LeetCode 589 - N-ary Tree Preorder Traversal

解题步骤（自动整理）
1. 将起点/初始层入队，并用 visited 或原地标记避免重复访问
2. 按层或按队列弹出元素扩展相邻节点，满足条件时更新答案
3. 队列处理完毕后返回结果（或在首次到达目标时提前返回）
"""
# Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

# Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)



# Example 1:



# Input: root = [1,null,3,2,4,null,5,6]
# Output: [1,3,5,6,2,4]
# Example 2:



# Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
# Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]


# Constraints:

# The number of nodes in the tree is in the range [0, 10^4].
# 0 <= Node.val <= 10^4
# The height of the n-ary tree is less than or equal to 1000.

"""
# Definition for a Node.
class Node:
    def __init__(self, val=None, children=None):
        self.val = val
        self.children = children
"""

class Solution:
    # dfs
    def preorder(self, root: 'Node') -> List[int]:
        res = list()
        def dfs(node):
            if node != None:
                res.append(node.val)
                for n in node.children:
                    dfs(n)
        dfs(root)
        return res

    #bfs
    def preorder(self, root: 'Node') -> List[int]:
        res = list()
        stk = list()
        if root != None:
            stk.append(root)
        while len(stk) > 0:
            node = stk.pop()
            res.append(node.val)
            node.children.reverse()
            for n in node.children:
                stk.append(n)
        return res
