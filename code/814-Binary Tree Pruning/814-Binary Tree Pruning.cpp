/*
LeetCode 814 - Binary Tree Pruning

解题步骤（自动整理）
1. 根据题意选择前序/中序/后序遍历方式遍历二叉树
2. 在遍历过程中维护需要的状态（路径和、深度、父子关系等）
3. 遍历完成后返回答案
*/
// Given the root of a binary tree, return the same tree where every subtree (of the given tree) not containing a 1 has been removed.

// A subtree of a node node is node plus every node that is a descendant of node.



// Example 1:


// Input: root = [1,null,0,0,1]
// Output: [1,null,0,null,1]
// Explanation:
// Only the red nodes satisfy the property "every subtree not containing a 1".
// The diagram on the right represents the answer.
// Example 2:


// Input: root = [1,0,1,0,0,0,1]
// Output: [1,null,1,null,1]
// Example 3:


// Input: root = [1,1,0,1,1,0,1,0]
// Output: [1,1,0,1,1,null,1]


// Constraints:

// The number of nodes in the tree is in the range [1, 200].
// Node.val is either 0 or 1.

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
    TreeNode* pruneTree(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }
        root->left = pruneTree(root->left);
        root->right = pruneTree(root->right);
        if (root->left == nullptr && root->right == nullptr && root->val == 0) {
            return nullptr;
        }
        return root;
    }
};
