/*
LeetCode 513 - Find Bottom Left Tree Value

解题步骤（自动整理）
1. 将起点/初始层入队，并用 visited 或原地标记避免重复访问
2. 按层或按队列弹出元素扩展相邻节点，满足条件时更新答案
3. 队列处理完毕后返回结果（或在首次到达目标时提前返回）
*/
// Given the root of a binary tree, return the leftmost value in the last row of the tree.



// Example 1:


// Input: root = [2,1,3]
// Output: 1
// Example 2:


// Input: root = [1,2,3,4,null,5,6,null,null,7]
// Output: 7


// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -2^31 <= Node.val <= 2^31 - 1

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

 // dfs
class Solution {
public:
    void dfs(TreeNode *node, int height, int &curVal, int &curHeight) {
        if (node == nullptr) {
            return ;
        }
        height ++;
        dfs(node->left, height, curVal, curHeight);
        dfs(node->right, height, curVal, curHeight);
        if (height > curHeight) {
            curHeight = height;
            curVal = node->val;
        }
    }

    int findBottomLeftValue(TreeNode* root) {
        int curVal, curHeight = 0;
        dfs(root, 0, curVal, curHeight);
        return curVal;
    }
};

// bfs

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int res;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty()) {
            auto p = q.front();
            q.pop();
            if (p->right) {
                q.push(p->right);
            }
            if (p->left) {
                q.push(p->left);
            }
            res = p->val;
        }
        return res;
    }
};
