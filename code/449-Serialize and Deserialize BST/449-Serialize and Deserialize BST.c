// Serialization is converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment.

// Design an algorithm to serialize and deserialize a binary search tree. There is no restriction on how your serialization/deserialization algorithm should work. You need to ensure that a binary search tree can be serialized to a string, and this string can be deserialized to the original tree structure.

// The encoded string should be as compact as possible.

 

// Example 1:

// Input: root = [2,1,3]
// Output: [2,1,3]
// Example 2:

// Input: root = []
// Output: []
 

// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// 0 <= Node.val <= 104
// The input tree is guaranteed to be a binary search tree.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/** Encodes a tree to a single string. */

#define MAX_NODE_SIZE 10000

void postOrder(struct TreeNode *root, int *arr, int *pos) {
    if (root == NULL) {
        return;
    }
    postOrder(root->left, arr, pos);
    postOrder(root->right, arr, pos);
    arr[(*pos)++] = root->val;
}

struct TreeNode * construct(int lower, int upper, int *stack, int *top) {
    if (*top == 0 || stack[*top - 1] < lower || stack[*top - 1] > upper) {
        return NULL;
    }
    int val = stack[*top - 1];
    (*top)--;
    struct TreeNode *root = (struct TreeNode *)malloc(sizeof(struct TreeNode));
    root->val = val;
    root->right = construct(val, upper, stack, top);
    root->left = construct(lower, val, stack, top);
    return root;
}

char* serialize(struct TreeNode* root) {
    char *res = NULL;
    int *arr = (int *)malloc(sizeof(int) * MAX_NODE_SIZE);
    int pos = 0;
    postOrder(root, arr, &pos);
    if (pos == 0) {
        return "";
    }
    res = (char *)malloc(sizeof(char) * pos * 6);
    int len = 0;
    for (int i = 0; i < pos - 1; i++) {
        len += sprintf(res + len, "%d,", arr[i]);
    }
    sprintf(res + len, "%d", arr[pos - 1]);
    free(arr);
    return res;
}

struct TreeNode* deserialize(char* data) {
    int len = strlen(data);
    if (len == 0) {
        return NULL;
    }
    int *stack = (int *)malloc(sizeof(int) * MAX_NODE_SIZE);
    int pos = 0;
    int top = 0;
    while (pos < len) {
        while (pos < len && data[pos] == ',') {
            pos++;
        }
        int val = 0;
        int start = pos;
        while (pos < len && data[pos] != ',') {
            val = val * 10 + data[pos] - '0';
            pos++;
        }
        if (start < pos) {
            stack[top++] = val;
        }
    }
    struct TreeNode *root = construct(INT_MIN, INT_MAX, stack, &top);
    free(stack);
    return root;
}


// Your functions will be called as such:
// char* data = serialize(root);
// deserialize(data);