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
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

#define MAX_NODE_SIZE 5001


void dfs(struct TreeNode* root, int *nodes, int *pos) {
    if (root) {
        dfs(root->left, nodes, pos);
        nodes[(*pos) ++] = root->val;
        dfs(root->right, nodes, pos);
    }
}

int* getAllElements(struct TreeNode* root1, struct TreeNode* root2, int* returnSize){
    int *nodes1 = (int *)malloc(sizeof(int) * MAX_NODE_SIZE);
    int *nodes2 = (int *)malloc(sizeof(int) * MAX_NODE_SIZE);
    int pos1 = 0, pos2 = 0;
    dfs(root1, nodes1, &pos1);
    dfs(root2, nodes2, &pos2);
    *returnSize = pos1 + pos2;
    int *res = (int *)malloc(sizeof(int) * (pos1 + pos2));
    int p1 = 0, p2 = 0;
    int pos = 0;
    while (true) {
        if (p1 == pos1) {
            memcpy(res + pos, nodes2 + p2, sizeof(int) * (pos2 - p2));
            break;
        } else if (p2 == pos2) {
            memcpy(res + pos, nodes1 + p1, sizeof(int) * (pos1 - p1));
            break;
        } else if (nodes1[p1] < nodes2[p2]) {
            res[pos ++] = nodes1[p1 ++];
        } else {
            res[pos ++] = nodes2[p2 ++];
        }
    }
    free(nodes1);
    free(nodes2);
    return res;
}