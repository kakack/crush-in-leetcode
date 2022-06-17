// You are given the root of a binary tree. We install cameras on the tree nodes where each camera at a node can monitor its parent, itself, and its immediate children.

// Return the minimum number of cameras needed to monitor all nodes of the tree.

 

// Example 1:


// Input: root = [0,0,null,0,0]
// Output: 1
// Explanation: One camera is enough to monitor all nodes if placed as shown.
// Example 2:


// Input: root = [0,0,null,0,null,0,null,null,0]
// Output: 2
// Explanation: At least two cameras are needed to monitor all nodes of the tree. The above image shows one of the valid configurations of camera placement.
 

// Constraints:

// The number of nodes in the tree is in the range [1, 1000].
// Node.val == 0


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
    int minCameraCover(TreeNode* root) {
        int res = 0;
        dfs(root, root, res);   //根节点的父节点设置为其自身，用于最后情况的判断
        return res;
    }

    void dfs(TreeNode* pre, TreeNode* root, int& res)
    {
        if (!root) {
            return ;
        } 
        dfs(root, root->left, res);
        dfs(root, root->right, res);

        //左右子节点中有未被监控的，那就必须放，不需要考虑父节点
        if ((root->left && root->left->val == 0) || (root->right && root->right->val == 0) || pre == root && root->val == 0) {
            if (root->left) root->left->val = 1;
            if (root->right) root->right->val = 1;
            pre->val = 1;
            root->val = 1;
            res += 1;
        }
    }
};
