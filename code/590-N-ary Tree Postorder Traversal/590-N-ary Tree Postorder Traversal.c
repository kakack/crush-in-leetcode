// Given the root of an n-ary tree, return the postorder traversal of its nodes' values.

// Nary-Tree input serialization is represented in their level order traversal. Each group of children is separated by the null value (See examples)

 

// Example 1:


// Input: root = [1,null,3,2,4,null,5,6]
// Output: [5,6,3,2,4,1]
// Example 2:


// Input: root = [1,null,2,3,4,5,null,null,6,7,null,8,null,9,10,null,null,11,null,12,null,13,null,null,14]
// Output: [2,6,14,11,7,3,12,8,4,13,9,10,5,1]
 

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
        for (int i = 0; i < root->numChildren; i ++) {
            dfs(root->children[i], returnSize, res);
        }
        res[(*returnSize) ++] = root->val;
    }
}

int* postorder(struct Node* root, int* returnSize) {
    int* res = (int*)malloc(sizeof(int) * 10000);
    *returnSize = 0;
    dfs(root, returnSize, res);
    return res;
}

// bfs

typedef struct {
    void * key;
    int val;
    UT_hash_handle hh; 
} HashItem;

void freeHash(HashItem ** obj) {
    HashItem * curr = NULL, * next = NULL;
    HASH_ITER(hh, *obj, curr, next) {
        HASH_DEL(*obj, curr);
        free(curr);
    }
}

int* postorder(struct Node* root, int* returnSize) {
    if (NULL == root) {
        *returnSize = 0;
        return NULL;
    }
    int * res = (int *)malloc(sizeof(int) * 10000);
    struct Node ** stk = (struct Node **)malloc(sizeof(struct Node *) * 10000);
    int top = 0; 
    *returnSize = 0;
    struct Node * node = root;
    HashItem * cnt = NULL;
    HashItem * pEntry = NULL;
    while (top != 0 || node != NULL) {
        while (node != NULL) {
            stk[top ++] = node;
            if (node->numChildren > 0) {
                pEntry = (HashItem *)malloc(sizeof(HashItem));
                pEntry->key = node;
                pEntry->val = 0;
                HASH_ADD_PTR(cnt, key, pEntry);
                node = node->children[0];
            } else {
                node = NULL;
            }
        }
        node = stk[top - 1];
        int index = 0;
        HASH_FIND_PTR(cnt, &node, pEntry);
        if (pEntry != NULL) {
            index = pEntry->val + 1;
        }
        if (index < node->numChildren) {
            pEntry->val ++;
            node = node->children[index];
        } else {
            top --;
            res[(*returnSize) ++] = node->val;
            if (pEntry != NULL) {
                HASH_DEL(cnt, pEntry);
            } 
            node = NULL;
        }
    }
    free(stk);
    freeHash(&cnt);
    return res;
}