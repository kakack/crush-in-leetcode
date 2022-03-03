// Given the root of a binary tree, return an array of the largest value in each row of the tree (0-indexed).

 

// Example 1:


// Input: root = [1,3,2,5,3,null,9]
// Output: [1,3,9]
// Example 2:

// Input: root = [1,2,3]
// Output: [1,3]
 

// Constraints:

// The number of nodes in the tree will be in the range [0, 104].
// -231 <= Node.val <= 231 - 1

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
    vector<int> layerMax;
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;
        if (root == NULL) {
            return res;
        }
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            int maxVal = INT_MIN;
            while (size --) {
                TreeNode* node = q.front();
                q.pop();
                if (node->left) {
                    q.push(node->left);
                }
                if (node->right) {
                    q.push(node->right);
                }
                maxVal = max(maxVal, node->val);
            }
            res.push_back(maxVal);
        }
    return res;
    }
};