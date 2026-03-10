/*
LeetCode 101 - Symmetric Tree

解题步骤（自动整理）
1. 根据题意选择前序/中序/后序遍历方式遍历二叉树
2. 在遍历过程中维护需要的状态（路径和、深度、父子关系等）
3. 遍历完成后返回答案
*/
// Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).



// Example 1:


// Input: root = [1,2,2,3,4,4,3]
// Output: true
// Example 2:


// Input: root = [1,2,2,null,3,null,3]
// Output: false


// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// -100 <= Node.val <= 100


// Follow up: Could you solve it both recursively and iteratively?

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
    bool helper(struct TreeNode* p, struct TreeNode* q) {
        if (!p && !q) {
            return true;
        } else if ((!p && q) || (!q && p) || (p->val != q->val)) {
            return false;
        } else {
            return helper(p->left, q->right) && helper(p->right, q->left);
        }
    }

    bool isSymmetric(TreeNode* root) {
        return helper(root->left, root->right);
    }
};
