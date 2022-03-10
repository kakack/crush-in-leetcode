// Given the root of an n-ary tree, return the preorder traversal of its nodes' values.

// Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

 

// Example 1:



// Input: root = [1,null,3,2,4,null,5,6]
// Output: [1,3,5,6,2,4]
// Example 2:



// Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
// Output: [1,2,3,6,7,11,14,4,8,12,5,9,13,10]
 

// Constraints:

// The number of nodes in the tree is in the range [0, 10^4].
// 0 <= Node.val <= 10^4
// The height of the n-ary tree is less than or equal to 1000.

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */


// dfs

void dfs(struct Node* root, int* returnSize, int* res) {
    if (root != NULL) {
        res[(*returnSize) ++] = root->val;
        for (int i = 0; i < root->numChildren; i ++) {
            dfs(root->children[i], returnSize, res);
        }
    }
}
int* preorder(struct Node* root, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * 10000);
    *returnSize = 0;
    dfs(root, returnSize, res);
    return res;
}

// bfs


int* preorder(struct Node* root, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * 10001);
    *returnSize = 0;
    struct Node** stk = (int*)malloc(sizeof(struct Node*) * 10001);
    int top = 0;
    if (root != NULL){
        stk[top ++] = root;
    }
    while (top > 0) {
        struct Node* node = stk[-- top];
        res[(*returnSize) ++] = node->val;
        for (int i = node->numChildren - 1; i >= 0; i --) {
            stk[top ++] = node->children[i];
        }
    }
    free(stk);
    return res;
}
