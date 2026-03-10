/*
LeetCode 100 - Same Tree

解题步骤（自动整理）
1. 根据题意选择前序/中序/后序遍历方式遍历二叉树
2. 在遍历过程中维护需要的状态（路径和、深度、父子关系等）
3. 遍历完成后返回答案
*/
/*Same Tree

Given two binary trees, write a function to check if they are equal or not.

Two binary trees are considered equal if they are structurally identical and the nodes have the same value.
*/

/**
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
    bool isSameTree(TreeNode *p, TreeNode *q) {

        if(p==NULL&&q==NULL)

           return true;

        else if((p==NULL&&q!=NULL)||(p!=NULL&&q==NULL))

          return false;

        else if(p->val==q->val&&isSameTree(p->left,q->left)&&isSameTree(p->right,q->right))

           return true;

        else

           return false;

    }
};
