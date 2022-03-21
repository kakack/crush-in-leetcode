// Given the root of a Binary Search Tree and a target number k, return true if there exist two elements in the BST such that their sum is equal to the given target.

 

// Example 1:


// Input: root = [5,3,6,2,4,null,7], k = 9
// Output: true
// Example 2:


// Input: root = [5,3,6,2,4,null,7], k = 28
// Output: false
 

// Constraints:

// The number of nodes in the tree is in the range [1, 10^4].
// -10^4 <= Node.val <= 10^4
// root is guaranteed to be a valid binary search tree.
// -10^5 <= k <= 10^5

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

typedef struct {
    int key;
    UT_hash_handle hh;
} HashItem;


bool dfs(struct TreeNode* node, int k, HashItem** hashSet) {
    HashItem* pEntry = NULL;
    if (node == NULL) {
        return false;
    } else {
        int diff = k - node->val;
        HASH_FIND_INT(*hashSet, &diff, pEntry);
        if (pEntry != NULL) {
            return true;
        } 
    }
    pEntry = (HashItem*)malloc(sizeof(HashItem));
    pEntry->key = node->val;
    HASH_ADD_INT(*hashSet, key, pEntry);
    return dfs(node->left, k, hashSet) || dfs(node->right, k, hashSet);
}

bool findTarget(struct TreeNode* root, int k){
    HashItem* hashSet = NULL;
    return dfs(root, k, &hashSet);
}