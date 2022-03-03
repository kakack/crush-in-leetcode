// Given the root of a binary tree, return the level order traversal of its nodes' values. (i.e., from left to right, level by level).

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: [[3],[9,20],[15,7]]
// Example 2:

// Input: root = [1]
// Output: [[1]]
// Example 3:

// Input: root = []
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrder(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    int** res = malloc(sizeof(int*) * 2000);
    *returnColumnSizes = malloc(sizeof(int) * 2000);
    struct TreeNode* queue[2000];
    int head = 0, tail = 0;
    struct TreeNode* cur;
    queue[tail++] = root;
    if (root == NULL) {
        return res;
    }

    while (head < tail) {
        int colSize = 0, last = tail;
        res[*returnSize] = malloc(sizeof(int) * (last - head));
        while (head < last) {
            cur = queue[head ++];
            res[*returnSize][colSize++] = cur->val;
            if (cur->left != NULL) {
                queue[tail++] = cur->left;
            }
            if (cur->right != NULL) {
                queue[tail++] = cur->right;
            }
        }
        (*returnColumnSizes)[*returnSize] = colSize;
        (*returnSize) ++;
    }
    return res;
}