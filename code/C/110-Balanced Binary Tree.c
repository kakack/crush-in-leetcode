// Given a binary tree, determine if it is height-balanced.

// For this problem, a height-balanced binary tree is defined as:

// a binary tree in which the left and right subtrees of every node differ in height by no more than 1.

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: true
// Example 2:


// Input: root = [1,2,2,3,3,null,null,4,4]
// Output: false
// Example 3:

// Input: root = []
// Output: true
 

// Constraints:

// The number of nodes in the tree is in the range [0, 5000].
// -10^4 <= Node.val <= 10^4

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int max(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int getDepth(struct TreeNode* root) {
    int depth = 0;
    if (root == NULL) {
        return 0;
    } else {
        return 1 + max(getDepth(root->left), getDepth(root->right));
    }
}

bool isBalanced(struct TreeNode* root){
    if (root == NULL) {
        return true;
    } else if (abs(getDepth(root->left) - getDepth(root->right)) > 1){
        return false;
    } else {
        return isBalanced(root->left) && isBalanced(root->right);
    }
}