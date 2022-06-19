// Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.

// The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).

 

// Example 1:


// Input: root = [5,2,-3]
// Output: [2,-3,4]
// Example 2:


// Input: root = [5,2,-5]
// Output: [2]
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
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
    unordered_map<int, int> cnt;
    int maxCnt = 0;
    int dfs(TreeNode* node) {
        if (node == nullptr) {
            return 0;
        }
        int sum = node->val + dfs(node->left) + dfs(node->right);
        maxCnt = max(maxCnt, ++ cnt[sum]);
        return sum;
    }
public:
    vector<int> findFrequentTreeSum(TreeNode* root) {
        dfs(root);
        vector<int> res;
        for (auto &[s, c]: cnt) {
            if (c == maxCnt) {
                res.emplace_back(s);
            }
        }
        return res;
    }
};