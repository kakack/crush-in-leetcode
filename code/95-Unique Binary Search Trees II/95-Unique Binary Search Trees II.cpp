/*
LeetCode 95 - Unique Binary Search Trees II

解题步骤（自动整理）
1. 用 DFS/递归遍历二叉树，在递归返回值中携带子树信息
2. 在当前节点聚合左右子树结果并完成题目要求的判断/更新
3. 递归结束后返回根节点对应的结果
*/
/*Unique Binary Search Trees II
Given n, generate all structurally unique BST's (binary search trees) that store values 1...n.

For example,
Given n = 3, your program should return all 5 unique BST's shown below.

   1         3     3      2      1
    \       /     /      / \      \
     3     2     1      1   3      2
    /     /       \                 \
   2     1         2                 3

思路跟之前判断个数的一样，选定一个root，递归左右子树
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
       vector<TreeNode *> generateTree(int start, int end){
        vector<TreeNode*> subTree;

        if(start>end){
            subTree.push_back(NULL);
            return subTree;
        }

        for (int k = start; k <= end; k++) {
            vector<TreeNode*> leftSubs = generateTree(start, k - 1);
            vector<TreeNode*> rightSubs = generateTree(k + 1, end);
            for(auto i:leftSubs )
                for(auto j:rightSubs){
                    TreeNode *node = new TreeNode(k);
                    node->left = i;
                    node->right = j;
                    subTree.push_back(node);
                }
            }
            return subTree;
    }

    vector<TreeNode *> generateTrees(int n) {

        if(n==0)
          return generateTree(1, 0);
        else
          return generateTree(1, n);
    }

};
