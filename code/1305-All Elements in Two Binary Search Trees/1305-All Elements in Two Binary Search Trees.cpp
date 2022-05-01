// Given two binary search trees root1 and root2, return a list containing all the integers from both trees sorted in ascending order.

 

// Example 1:


// Input: root1 = [2,1,4], root2 = [1,0,3]
// Output: [0,1,1,2,3,4]
// Example 2:


// Input: root1 = [1,null,8], root2 = [8,1]
// Output: [1,1,8,8]
 

// Constraints:

// The number of nodes in each tree is in the range [0, 5000].
// -10^5 <= Node.val <= 10^5

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
private:
    void dfs(TreeNode* root, vector<int> &nodes) {
        if (root) {
            dfs(root->left, nodes);
            nodes.push_back(root->val);
            dfs(root->right, nodes);
        }
    }
public:
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> nodes1, nodes2;
        dfs(root1, nodes1);
        dfs(root2, nodes2);
        
        vector<int> res;
        auto p1 = nodes1.begin(), p2 = nodes2.begin();
        while (true) {
            if (p1 == nodes1.end()) {
                res.insert(res.end(), p2, nodes2.end());
                break;
            } else if (p2 == nodes2.end()) {
                res.insert(res.end(), p1, nodes1.end());
                break;
            } else if (*p1 < *p2) {
                res.push_back(*p1 ++);
            } else {
                res.push_back(*p2 ++);
            }
        }
        return res;
    }
};