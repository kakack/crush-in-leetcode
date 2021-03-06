# -*- coding: utf-8 -*
"""
@author: Kai Chen
@file: 331-Verify Preorder Serialization of a Binary Tree.py
@time: 2021/3/12 9:14
@desc:
One way to serialize a binary tree is to use pre-order traversal. When we encounter a non-null node, we record the node's value. If it is a null node, we record using a sentinel value such as #.

     _9_
    /   \
   3     2
  / \   / \
 4   1  #  6
/ \ / \   / \
# # # #   # #
For example, the above binary tree can be serialized to the string "9,3,4,#,#,1,#,#,2,#,6,#,#", where # represents a null node.

Given a string of comma separated values, verify whether it is a correct preorder traversal serialization of a binary tree. Find an algorithm without reconstructing the tree.

Each comma separated value in the string must be either an integer or a character '#' representing null pointer.

You may assume that the input format is always valid, for example it could never contain two consecutive commas such as "1,,3".

Example 1:

Input: "9,3,4,#,#,1,#,#,2,#,6,#,#"
Output: true
Example 2:

Input: "1,#"
Output: false
Example 3:

Input: "9,#,#,1"
Output: false
"""


class Solution(object):
    def isValidSerialization(self, preorder):
        """
        :type preorder: str
        :rtype: bool
        """
        n, i = len(preorder), 0
        stk = [1]
        while i < n:
            if len(stk) == 0:
                return False
            if preorder[i] == ',':
                i += 1
            elif preorder[i] == '#':
                stk[-1] -= 1
                if stk[-1] == 0:
                    stk.pop()
                i += 1
            else:
                while i < n and preorder[i] != ',':
                    i += 1
                stk[-1] -= 1
                if stk[-1] == 0:
                    stk.pop()
                stk.append(2)
        return len(stk) == 0
