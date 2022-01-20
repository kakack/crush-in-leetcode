// Given the root of a binary tree, return the bottom-up level order traversal of its nodes' values. (i.e., from left to right, level by level from leaf to root).

 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: [[15,7],[9,20],[3]]
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
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** levelOrderBottom(struct TreeNode* root, int* returnSize, int** returnColumnSizes){
    *returnSize = 0;
    *returnColumnSizes = malloc(sizeof(int) * 2000);
    int** res = malloc(sizeof(int*) * 2000);
    if (root == NULL) {
        return res;
    }
    struct TreeNode* queue[2000];
    int head = 0, tail = 0;
    queue[tail ++] = root;
    struct TreeNode* cur;
    while (head < tail) {
        int len = tail - head;
        int* level = malloc(sizeof(int) * len);
        (*returnColumnSizes)[*returnSize] = len;
        for (int i = 0; i < len; i++) {
            cur = queue[head++];
            level[i] = cur->val;
            if (cur->left != NULL) {
                queue[tail++] = cur->left;
            }
            if (cur->right != NULL) {
                queue[tail++] = cur->right;
            }
        }
        res[(*returnSize)++] = level;
    }
    for (int i = 0; 2 * i < *returnSize; i++) {
        int* tmp1 = res[i];
        res[i] = res[(*returnSize) - 1 - i];
        res[(*returnSize) - 1 - i] = tmp1;
        int tmp2 = (*returnColumnSizes)[i];
        (*returnColumnSizes)[i] = (*returnColumnSizes)[(*returnSize) - 1 - i];
        (*returnColumnSizes)[(*returnSize) - 1 - i] = tmp2;
    }
    return res;
}