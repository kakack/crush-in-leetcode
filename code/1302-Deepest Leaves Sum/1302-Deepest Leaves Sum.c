// Given the root of a binary tree, return the sum of values of its deepest leaves.
 

// Example 1:


// Input: root = [1,2,3,4,5,null,6,7,null,null,null,null,8]
// Output: 15
// Example 2:

// Input: root = [6,7,8,2,7,1,3,9,null,1,4,null,null,null,5]
// Output: 19
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// 1 <= Node.val <= 100

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


int deepestLeavesSum(struct TreeNode* root){
    if (!root) {
        return 0;
    }
    int res;
    struct TreeNode** que[10001];
    int head = 0, tail = 0;
    que[tail ++] = root;
    while (tail > head) {
        int n = tail - head;
        res = 0;
        for (int i = 0; i < n; i ++) {
            struct TreeNode* tmp = malloc(sizeof(struct TreeNode*));
            tmp = que[head ++];
            res += tmp->val;
            if (tmp->left) {
                que[tail ++] = tmp->left;
            }
            if (tmp->right) {
                que[tail ++] = tmp->right;
            }
        }
    }
    return res;
}