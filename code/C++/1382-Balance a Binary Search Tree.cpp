// Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

// A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

 

// Example 1:


// Input: root = [1,null,2,null,3,null,4,null,null]
// Output: [2,1,3,null,null,null,4]
// Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
// Example 2:


// Input: root = [2,1,3]
// Output: [2,1,3]
 

// Constraints:

// The number of nodes in the tree is in the range [1, 10^4].
// 1 <= Node.val <= 10^5

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
    vector<int> inorderSeq;
    
    void getInorder(TreeNode* node) {
        if (node->left != nullptr) {
            getInorder(node->left);
        }
        inorderSeq.push_back(node->val);
        if (node->right != nullptr) {
            getInorder(node->right);
        }
    }

    TreeNode* build(int l, int r) {
        int mid = (l + r) / 2;
        TreeNode* node = new TreeNode(inorderSeq[mid]);
        if (l <= mid - 1) {
            node->left = build(l, mid - 1);
        }
        if (r >= mid + 1) {
            node->right = build(mid + 1, r);
        }
        return node;
    }

    TreeNode* balanceBST(TreeNode* root) {
        getInorder(root);
        return build(0, inorderSeq.size() - 1);
    }
};