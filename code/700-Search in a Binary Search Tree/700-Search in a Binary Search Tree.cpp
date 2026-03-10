/*
LeetCode 700 - Search in a Binary Search Tree

解题步骤（自动整理）
1. 根据题意选择前序/中序/后序遍历方式遍历二叉树
2. 在遍历过程中维护需要的状态（路径和、深度、父子关系等）
3. 遍历完成后返回答案
*/
// You are given the root of a binary search tree (BST) and an integer val.

// Find the node in the BST that the node's value equals val and return the subtree rooted with that node. If such a node does not exist, return null.



// Example 1:


// Input: root = [4,2,7,1,3], val = 2
// Output: [2,1,3]
// Example 2:


// Input: root = [4,2,7,1,3], val = 5
// Output: []


// Constraints:

// The number of nodes in the tree is in the range [1, 5000].
// 1 <= Node.val <= 10^7
// root is a binary search tree.
// 1 <= val <= 10^7

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root->val == val) {
            return root;
        } else if (root->left != nullptr && root->val > val) {
            return searchBST(root->left, val);
        } else if (root->right != nullptr && root->val < val) {
            return searchBST(root->right, val);
        }
        return nullptr;
    }
};
