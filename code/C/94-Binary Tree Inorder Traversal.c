// Given the root of a binary tree, return the inorder traversal of its nodes' values.

 

// Example 1:


// Input: root = [1,null,2,3]
// Output: [1,3,2]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [1]
// Output: [1]
 

// Constraints:

// The number of nodes in the tree is in the range [0, 100].
// -100 <= Node.val <= 100
 

// Follow up: Recursive solution is trivial, could you do it iteratively?

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// 递归
void inorder(struct TreeNode* root, int* returnSize, int* res) {
    if (root == NULL) {
        return;
    }
    inorder(root->left, returnSize, res);
    res[(*returnSize) ++] = root->val;
    inorder(root->right, returnSize, res);
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* res = malloc(sizeof(int) * 100);
    *returnSize = 0;
    inorder(root, returnSize, res);
    return res;
}

// 迭代

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* res = malloc(sizeof(int) * 100);
    *returnSize = 0;
    struct TreeNode* stk[100];
    int stk_top = 0;
    struct TreeNode* node = root;
    while (stk_top > 0 || node != NULL) {
        if (node != NULL) {
            stk[stk_top ++] = node;
            node = node->left;
        } else {
            node = stk[-- stk_top];
            res[(*returnSize) ++] = node->val;
            node = node->right;
        }
    }
    return res;
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    int* res = malloc(sizeof(int) * 100);
    *returnSize = 0;
    struct TreeNode* stk[100];
    int stk_top = 0;
    while (root != NULL || stk_top > 0) {
        while (root != NULL) {
            stk[stk_top ++] = root;
            root = root->left;
        }
        root = stk[--stk_top];
        res[(*returnSize) ++] = root->val;
        root = root->right;
    }
    return res;
}