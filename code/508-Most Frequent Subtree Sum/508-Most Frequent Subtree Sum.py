# Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.

# The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).

 

# Example 1:


# Input: root = [5,2,-3]
# Output: [2,-3,4]
# Example 2:


# Input: root = [5,2,-5]
# Output: [2]
 

# Constraints:

# The number of nodes in the tree is in the range [1, 104].
# -10^5 <= Node.val <= 10^5

# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right

class Solution:
    def findFrequentTreeSum(self, root: TreeNode) -> List[int]:
        cnt = Counter()
        def dfs(node: TreeNode) -> int:
            if node is None:
                return 0
            sum = node.val + dfs(node.left) + dfs(node.right)
            cnt[sum] += 1
            return sum
        dfs(root)
        maxCnt = max(cnt.values())
        return [s for s, c in cnt.items() if c == maxCnt]