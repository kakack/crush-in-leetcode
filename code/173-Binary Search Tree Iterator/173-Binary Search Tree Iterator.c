/*

Implement the BSTIterator class that represents an iterator over the in-order traversal of a binary search tree (BST):

BSTIterator(TreeNode root) Initializes an object of the BSTIterator class. The root of the BST is given as part of the constructor. The pointer should be initialized to a non-existent number smaller than any element in the BST.
boolean hasNext() Returns true if there exists a number in the traversal to the right of the pointer, otherwise returns false.
int next() Moves the pointer to the right, then returns the number at the pointer.
Notice that by initializing the pointer to a non-existent smallest number, the first call to next() will return the smallest element in the BST.

You may assume that next() calls will always be valid. That is, there will be at least a next number in the in-order traversal when next() is called.



Example 1:


Input
["BSTIterator", "next", "next", "hasNext", "next", "hasNext", "next", "hasNext", "next", "hasNext"]
[[[7, 3, 15, null, null, 9, 20]], [], [], [], [], [], [], [], [], []]
Output
[null, 3, 7, true, 9, true, 15, true, 20, false]

Explanation
BSTIterator bSTIterator = new BSTIterator([7, 3, 15, null, null, 9, 20]);
bSTIterator.next();    // return 3
bSTIterator.next();    // return 7
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 9
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 15
bSTIterator.hasNext(); // return True
bSTIterator.next();    // return 20
bSTIterator.hasNext(); // return False


Constraints:

The number of nodes in the tree is in the range [1, 105].
0 <= Node.val <= 106
At most 105 calls will be made to hasNext, and next.


Follow up:

Could you implement next() and hasNext() to run in average O(1) time and use O(h) memory, where h is the height of the tree?

*/

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

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */



typedef struct {
    int *res;
    int size;
    int idx; 
} BSTIterator;

int getTreeSize(struct TreeNode* root) {
    if (root == NULL) {
        return 0;
    }
    return 1 + getTreeSize(root->left) + getTreeSize(root->right);
}

void inorder(int* ret, int* retSize, struct TreeNode* root) {
    if (root == NULL) {
        return;
    }
    inorder(ret, retSize, root->left);
    ret[(*retSize)++] = root->val;
    inorder(ret, retSize, root->right);
}

int* inorderTraversal(int* retSize, struct TreeNode* root) {
    *retSize = 0;
    int* ret = malloc(sizeof(int) * getTreeSize(root));
    inorder(ret, retSize, root);
    return ret;
}

BSTIterator* bSTIteratorCreate(struct TreeNode* root) {
    BSTIterator *ret = malloc(sizeof(BSTIterator));
    ret->res = inorderTraversal(&(ret->size), root);
    ret->idx = 0;
    return ret;
}

int bSTIteratorNext(BSTIterator* obj) {
    return obj->res[(obj->idx) ++];
}

bool bSTIteratorHasNext(BSTIterator* obj) {
    return obj->idx < obj->size;
}

void bSTIteratorFree(BSTIterator* obj) {
    free(obj->res);
    free(obj);
}

/**
 * Your BSTIterator struct will be instantiated and called as such:
 * BSTIterator* obj = bSTIteratorCreate(root);
 * int param_1 = bSTIteratorNext(obj);
 
 * bool param_2 = bSTIteratorHasNext(obj);
 
 * bSTIteratorFree(obj);
*/