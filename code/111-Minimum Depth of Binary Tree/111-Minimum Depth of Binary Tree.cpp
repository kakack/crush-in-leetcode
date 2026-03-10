/*
LeetCode 111 - Minimum Depth of Binary Tree

解题步骤（自动整理）
1. 根据题意选择前序/中序/后序遍历方式遍历二叉树
2. 在遍历过程中维护需要的状态（路径和、深度、父子关系等）
3. 遍历完成后返回答案
*/
/*
Minimum Depth of Binary Tree

*Given a binary tree, find its minimum depth.

The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode *root) {
        return minDepth(root, false);
    }

    int minDepth(TreeNode *root, bool hasbrother){
        if(root==NULL) return hasbrother? INT_MAX:0;

        return 1+min(minDepth(root->left, root->right!=NULL), minDepth(root->right, root->left!=NULL));
    }
};
