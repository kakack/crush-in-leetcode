// Given the root of a binary tree, return the preorder traversal of its nodes' values.

 

// Example 1:


// Input: root = [1,null,2,3]
// Output: [1,2,3]
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

void preorder(struct TreeNode* root, int* returnSize, int* res) {
    if (root == NULL) {
        return;
    }
    res[(*returnSize)++] = root->val;
    preorder(root->left, returnSize, res);
    preorder(root->right, returnSize, res);
}

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int* res = malloc(sizeof(int) * 100);
    *returnSize = 0;
    preorder(root, returnSize, res);
    return res;
}

// 迭代

int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int* res = malloc(sizeof(int) * 100);
    *returnSize = 0;
    struct TreeNode* stk[100];
    if (root == NULL) {
        return;
    }

    int stk_top = 0;
    stk[stk_top ++] = root;
    while (stk_top > 0) {
        struct TreeNode* node = stk[-- stk_top];
        res[(*returnSize) ++] = node->val;
        if (node->right != NULL) {
            stk[stk_top ++] = node->right;
        }
        if (node->left != NULL) {
            stk[stk_top ++] = node->left;
        }
    }
    return res;
}


int* preorderTraversal(struct TreeNode* root, int* returnSize){
    int* res = malloc(sizeof(int) * 100);
    *returnSize = 0;
    struct TreeNode* stk[100];

    int stk_top = 0;
    while (stk_top > 0 || root != NULL) {
        while (root != NULL) {
            res[(*returnSize) ++] = root->val;
            stk[stk_top ++] = root;
            root = root->left;
        }
        root = stk[--stk_top];
        root = root->right;
    }
    return res;
}
