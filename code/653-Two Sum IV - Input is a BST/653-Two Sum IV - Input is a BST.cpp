/*
LeetCode 653 - Two Sum IV - Input is a BST

解题步骤（自动整理）
1. 用 DFS/递归遍历二叉树，在递归返回值中携带子树信息
2. 在当前节点聚合左右子树结果并完成题目要求的判断/更新
3. 递归结束后返回根节点对应的结果
*/

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
