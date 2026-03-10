/*
LeetCode 606 - Construct String from Binary Tree

解题步骤（自动整理）
1. 根据题意选择前序/中序/后序遍历方式遍历二叉树
2. 在遍历过程中维护需要的状态（路径和、深度、父子关系等）
3. 遍历完成后返回答案
*/
// Given the root of a binary tree, construct a string consisting of parenthesis and integers from a binary tree with the preorder traversal way, and return it.

// Omit all the empty parenthesis pairs that do not affect the one-to-one mapping relationship between the string and the original binary tree.



// Example 1:


// Input: root = [1,2,3,4]
// Output: "1(2(4))(3)"
// Explanation: Originally, it needs to be "1(2(4)())(3()())", but you need to omit all the unnecessary empty parenthesis pairs. And it will be "1(2(4))(3)"
// Example 2:


// Input: root = [1,2,3,null,4]
// Output: "1(2()(4))(3)"
// Explanation: Almost the same as the first example, except we cannot omit the first parenthesis pair to break the one-to-one mapping relationship between the input and the output.


// Constraints:

// The number of nodes in the tree is in the range [1, 10^4].
// -1000 <= Node.val <= 1000

void helper(struct TreeNode* root, char * str, int * pos) {
    if (root == NULL) {
        return;
    } else if (root->left == NULL && root->right == NULL) {
        *pos += sprintf(str + *pos, "%d", root->val);
        return;
    } else if (root->right == NULL) {
        *pos += sprintf(str + *pos, "%d", root->val);
        str[(*pos) ++] = '(';
        helper(root->left, str, pos);
        str[(*pos) ++] = ')';
        return ;
    } else {
        *pos += sprintf(str + *pos, "%d", root->val);
        str[(*pos) ++] = '(';
        helper(root->left, str, pos);
        str[(*pos) ++] = ')';
        str[(*pos) ++] = '(';
        helper(root->right, str, pos);
        str[(*pos) ++] = ')';
        return ;
    }
}

char * tree2str(struct TreeNode* root) {
    char * res = (char *)malloc(sizeof(char) * 1000000);
    int pos = 0;
    helper(root, res, &pos);
    res[pos] = '\0';
    return res;
}
