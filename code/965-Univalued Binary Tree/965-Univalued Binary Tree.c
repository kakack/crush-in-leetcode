// A binary tree is uni-valued if every node in the tree has the same value.

// Given the root of a binary tree, return true if the given tree is uni-valued, or false otherwise.

 

// Example 1:


// Input: root = [1,1,1,1,1,null,1]
// Output: true
// Example 2:


// Input: root = [2,2,2,5,2]
// Output: false
 

// Constraints:

// The number of nodes in the tree is in the range [1, 100].
// 0 <= Node.val < 100

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


bool isUnivalTree(struct TreeNode* root){
    if (root->left && root->right) {
        return root->val == root->left->val && root->val == root->right->val && isUnivalTree(root->left) && isUnivalTree(root->right);
    } else if (root->left) {
        return root->val == root->left->val && isUnivalTree(root->left);
    } else if (root->right) {
        return root->val == root->right->val && isUnivalTree(root->right);
    } else {
        return true;
    }
}