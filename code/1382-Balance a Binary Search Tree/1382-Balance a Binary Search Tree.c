// Given the root of a binary search tree, return a balanced binary search tree with the same node values. If there is more than one answer, return any of them.

// A binary search tree is balanced if the depth of the two subtrees of every node never differs by more than 1.

 

// Example 1:


// Input: root = [1,null,2,null,3,null,4,null,null]
// Output: [2,1,3,null,null,null,4]
// Explanation: This is not the only correct answer, [3,1,4,null,2] is also correct.
// Example 2:


// Input: root = [2,1,3]
// Output: [2,1,3]
 

// Constraints:

// The number of nodes in the tree is in the range [1, 10^4].
// 1 <= Node.val <= 10^5

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

void getInorder(struct TreeNode* node, int* inorderSeq, int* seqSize) {
    if (node->left != NULL) {
        getInorder(node->left, inorderSeq, seqSize);
    }
    inorderSeq[(*seqSize)++] = node->val;
    if (node->right != NULL) {
        getInorder(node->right, inorderSeq, seqSize);
    }
}

struct TreeNode* build(int l, int r, int* inorderSeq) {
    if (l > r) {
        return;
    }
    int mid = (l + r) / 2;
    struct TreeNode* node = malloc(sizeof(struct TreeNode));
    node->val = inorderSeq[mid];
    node->left = build(l, mid - 1, inorderSeq);
    node->right = build(mid + 1, r, inorderSeq); 
    return node;
}

struct TreeNode* balanceBST(struct TreeNode* root){
    int* inorderSeq = malloc(sizeof(int) * 50000);
    int seqSize = 0;
    getInorder(root, inorderSeq, &seqSize);
    return build(0, seqSize - 1, inorderSeq);
}