// Given an n-ary tree, return the level order traversal of its nodes' values.

// Nary-Tree input serialization is represented in their level order traversal, each group of children is separated by the null value (See examples).

 

// Example 1:



// Input: root = [1,null,3,2,4,null,5,6]
// Output: [[1],[3,2,4],[5,6]]
// Example 2:



// Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
// Output: [[1],[2,3,4,5],[6,7,8,9,10],[11,12,13],[14]]
 

// Constraints:

// The height of the n-ary tree is less than or equal to 1000
// The total number of nodes is between [0, 10^4]

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numChildren;
 *     struct Node** children;
 * };
 */

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

#define MAX_LEVE_SIZE 1000
#define MAX_NODE_SIZE 10000

int** levelOrder(struct Node* root, int* returnSize, int** returnColumnSizes) {
    int ** res = (int **)malloc(sizeof(int *) * MAX_LEVE_SIZE);
    *returnColumnSizes = (int *)malloc(sizeof(int) * MAX_LEVE_SIZE);
    if (!root) {
        *returnSize = 0;
        return res;
    }
    struct Node ** queue = (struct Node **)malloc(sizeof(struct Node *) * MAX_NODE_SIZE);
    int head = 0, tail = 0;
    int level = 0;
    queue[tail ++] = root;
    while (head != tail) {
        int cnt = tail - head;
        res[level] = (int *)malloc(sizeof(int) * cnt);
        for (int i = 0; i < cnt; i ++) {
            struct Node* cur = queue[head ++];
            res[level][i] = cur->val;
            for (int j = 0; j < cur->numChildren; j ++) {
                queue[tail ++] = cur->children[j];
            }
        }
        (*returnColumnSizes)[level ++] = cnt;
    }
    *returnSize = level;
    free(queue);
    return res;
}