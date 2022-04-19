// You are given the root of a binary search tree (BST), where the values of exactly two nodes of the tree were swapped by mistake. Recover the tree without changing its structure.

 

// Example 1:


// Input: root = [1,3,null,null,2]
// Output: [3,1,null,null,2]
// Explanation: 3 cannot be a left child of 1 because 3 > 1. Swapping 1 and 3 makes the BST valid.
// Example 2:


// Input: root = [3,1,4,null,null,2]
// Output: [2,1,4,null,null,3]
// Explanation: 2 cannot be in the right subtree of 3 because 2 < 3. Swapping 2 and 3 makes the BST valid.
 

// Constraints:

// The number of nodes in the tree is in the range [2, 1000].
// -231 <= Node.val <= 231 - 1
 

// Follow up: A solution using O(n) space is pretty straight-forward. Could you devise a constant O(1) space solution?


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
void recoverTree(struct TreeNode* root) {
    struct TreeNode ** stk = (struct TreeNode**)malloc(0);
    int stk_top = 0;
    struct TreeNode* x = NULL;
    struct TreeNode* y = NULL;
    struct TreeNode* pred = NULL;

    while (stk_top > 0 || root != NULL) {
        while (root != NULL) {
            stk_top ++;
            stk = (struct TreeNode**)realloc(stk, sizeof(struct TreeNode*) * stk_top);
            stk[stk_top - 1] = root;
            root = root->left;
        }
        root = stk[-- stk_top];
        if (pred != NULL && root->val < pred->val) {
             y = root;
            if (x == NULL) {
                x = pred;
            } else{
                break;
            }
        }
        pred = root;
        root = root->right;
    }
    int t = x->val;
    x->val = y->val;
    y->val = t;
}