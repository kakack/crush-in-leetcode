/*
Given the root of a binary search tree, rearrange the tree in in-order so that the leftmost node in the tree is now the root of the tree, and every node has no left child and only one right child.



Example 1:


Input: root = [5,3,6,2,4,null,8,1,null,null,null,7,9]
Output: [1,null,2,null,3,null,4,null,5,null,6,null,7,null,8,null,9]
Example 2:


Input: root = [5,1,7]
Output: [1,null,5,null,7]


Constraints:

The number of nodes in the given tree will be in the range [1, 100].
0 <= Node.val <= 1000
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

struct TreeNode* createTreeNode(int val) {
    struct TreeNode* ret = malloc(sizeof(struct TreeNode));
    ret->val = val, ret->left = ret->right = NULL;
    return ret;
}


void inorder(struct TreeNode* node, int * res, int *resSize) {
    if (node == NULL) {
        return;
    }
    inorder(node->left, res, resSize);
    res[(*resSize) ++] = node->val;
    inorder(node->right, res, resSize);
}

struct TreeNode* increasingBST(struct TreeNode* root){
    int res[100], resSize = 0;
    inorder(root, res, &resSize);
    struct TreeNode *dummyNode = createTreeNode(-1);
    struct TreeNode* resNode = dummyNode;
    for (int i = 0; i < resSize; i++) {
        resNode->right = createTreeNode(res[i]);
        resNode = resNode->right;
    }
    return dummyNode->right;
}