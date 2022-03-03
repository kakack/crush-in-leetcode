// Given the root of a binary tree, return the postorder traversal of its nodes' values.

 

// Example 1:


// Input: root = [1,null,2,3]
// Output: [3,2,1]
// Example 2:

// Input: root = []
// Output: []
// Example 3:

// Input: root = [1]
// Output: [1]
 

// Constraints:

// The number of the nodes in the tree is in the range [0, 100].
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

void postorder(struct TreeNode* root, int* returnSize, int* res) {
    if (root == NULL) {
        return;
    }
    postorder(root->left, returnSize, res);
    postorder(root->right, returnSize, res);
    res[(*returnSize) ++] = root->val;
}

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int* res = malloc(sizeof(int) * 100);
    *returnSize = 0;
    postorder(root, returnSize, res);
    return res;
}

// 迭代

int* postorderTraversal(struct TreeNode* root, int* returnSize){
    int* res = malloc(sizeof(int) * 100);
    *returnSize = 0;
    struct TreeNode* stk[100];
    int stk_top = 0;
    struct TreeNode* node = root;
    struct TreeNode* preNode = NULL;
    while (node != NULL || stk_top >0) {
        while (node != NULL) {
            stk[stk_top ++] = node;
            node = node->left;
        }
        node = stk[-- stk_top];
        if (node->right == preNode || node->right == NULL) {
            res[(*returnSize) ++] = node->val;
            preNode = node;
            node = NULL;
        } else {
            stk[stk_top ++] = node;
            node = node->right;
        }   
    }
    return res;
}