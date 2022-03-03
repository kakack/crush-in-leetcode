# In an infinite binary tree where every node has two children, the nodes are labelled in row order.
#
# In the odd numbered rows (ie., the first, third, fifth,...), the labelling is left to right, while in the even numbered rows (second, fourth, sixth,...), the labelling is right to left.
#
#
#
# Given the label of a node in this tree, return the labels in the path from the root of the tree to the node with that label.
#
#
#
# Example 1:
#
# Input: label = 14
# Output: [1,3,4,14]
# Example 2:
#
# Input: label = 26
# Output: [1,2,6,10,26]
#
#
# Constraints:
#
# 1 <= label <= 10^6

class Solution(object):
    def pathInZigZagTree(self, label):
        """
        :type label: int
        :rtype: List[int]
        """
        ans = [1]

        def dfs(label, k):
            if k == 1:
                return
            tmp = label - (1 << (k - 1))
            tmp >>= 1
            tmp = (1 << (k - 1)) - tmp - 1
            dfs(tmp, k - 1)
            ans.append(label)

        k, tmp = 0, label
        while tmp:
            tmp >>= 1
            k += 1
        dfs(label, k)
        return ans
