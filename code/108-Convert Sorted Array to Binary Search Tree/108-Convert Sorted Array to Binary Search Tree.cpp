/*
LeetCode 108 - Convert Sorted Array to Binary Search Tree

解题步骤（自动整理）
1. 用 DFS/递归遍历二叉树，在递归返回值中携带子树信息
2. 在当前节点聚合左右子树结果并完成题目要求的判断/更新
3. 递归结束后返回根节点对应的结果
*/
/*Convert Sorted Array to Binary Search Tree
 *Given an array where elements are sorted in ascending order, convert it to a height balanced BST.
 *
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };

RandomAccessIterator真是容器中的神器，请务必要会用，这个题没啥难度，也是递归
 */
class Solution {
public:
    TreeNode *sortedArrayToBST(vector<int> &num) {

        return sortedArrayToBST(num.begin(), num.end());

    }

    template<typename RandomAccessIterator>

    TreeNode *sortedArrayToBST(RandomAccessIterator first, RandomAccessIterator last){
        const auto length = distance(first, last);
        if(length==0) return NULL;
        if (length == 1) return new TreeNode(*first);

        auto mid = first + length / 2;
        TreeNode* root = new TreeNode (*mid);
        root->left = sortedArrayToBST(first, mid);
        root->right = sortedArrayToBST(mid + 1, last);

        return root;
    }
};
