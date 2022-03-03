// Given the root of a binary tree, return the average value of the nodes on each level in the form of an array. Answers within 10-5 of the actual answer will be accepted.
 

// Example 1:


// Input: root = [3,9,20,null,null,15,7]
// Output: [3.00000,14.50000,11.00000]
// Explanation: The average value of nodes on level 0 is 3, on level 1 is 14.5, and on level 2 is 11.
// Hence return [3, 14.5, 11].
// Example 2:


// Input: root = [3,9,20,15,7]
// Output: [3.00000,14.50000,11.00000]
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -2^31 <= Node.val <= 2^31 - 1

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
double* averageOfLevels(struct TreeNode* root, int* returnSize){
    double* res = malloc(sizeof(double) * 10001);
    *returnSize = 0;
    struct TreeNode* queue[10001];
    int head = 0, tail = 0;
    queue[tail++] = root;
    while (head < tail) {
        int len = tail - head;
        double sum = 0.0;
        for (int i = 0; i < len; i ++) {
            struct TreeNode* node = queue[head++];
            sum += node->val;
            if (node->left != NULL) {
                queue[tail++] = node->left;
            }
            if (node->right != NULL) {
                queue[tail++] = node->right;
            }
        }
        res[(*returnSize) ++] = sum / len;
    }
    return res;
}