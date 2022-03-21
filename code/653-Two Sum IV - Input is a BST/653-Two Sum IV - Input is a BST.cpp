
// Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

 

// Example 1:


// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true
// Example 2:


// Input: root = [5,3,6,2,4,null,7], k = 28
// Output: false
 

// Constraints:

// The number of nodes in the tree is in the range [1, 10^4].
// -10^4 <= Node.val <= 10^4
// root is guaranteed to be a valid binary search tree.
// -10^5 <= k <= 10^5

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
    unordered_set<int> mp;
    bool dfs(TreeNode *node, int k) {
        if (node == nullptr) {
            return false;
        } else if (mp.find(k - node->val) != mp.end()) {
            return true;
        } else {
            if (mp.find(node->val) == mp.end()) {
                mp.emplace(node->val);
            } 
        }
        return dfs(node->left, k) || dfs(node->right, k);
    }
    bool findTarget(TreeNode* root, int k) {
        return dfs(root, k);
    }
};