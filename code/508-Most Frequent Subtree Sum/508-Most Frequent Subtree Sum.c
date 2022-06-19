// Given the root of a binary tree, return the most frequent subtree sum. If there is a tie, return all the values with the highest frequency in any order.

// The subtree sum of a node is defined as the sum of all the node values formed by the subtree rooted at that node (including the node itself).

 

// Example 1:


// Input: root = [5,2,-3]
// Output: [2,-3,4]
// Example 2:


// Input: root = [5,2,-5]
// Output: [2]
 

// Constraints:

// The number of nodes in the tree is in the range [1, 104].
// -10^5 <= Node.val <= 10^5

#define MAX(a, b) ((a) > (b) ? (a) : (b))

typedef struct {
    int key;
    int val;
    UT_hash_handle hh;
} HashItem;

int dfs(struct TreeNode *node, HashItem **cnt, int *maxCnt) {
    if (node == NULL) {
        return 0;
    }
    int sum = node->val + dfs(node->left, cnt, maxCnt) + dfs(node->right, cnt, maxCnt);
    HashItem *pEntry = NULL;
    HASH_FIND_INT(*cnt, &sum, pEntry);
    if (NULL == pEntry) {
        pEntry = (HashItem *)malloc(sizeof(HashItem));
        pEntry->key = sum;
        pEntry->val = 1;
        HASH_ADD_INT(*cnt, key, pEntry);
    } else {
        pEntry->val++;
    }
    *maxCnt = MAX(*maxCnt, pEntry->val);
    return sum;
}

int* findFrequentTreeSum(struct TreeNode* root, int* returnSize) {
    HashItem * cnt = NULL;
    int maxCnt = 0;
    dfs(root, &cnt, &maxCnt);
    unsigned int n = HASH_COUNT(cnt);
    int *ans = (int *)malloc(sizeof(int) * n);
    int pos = 0;
    for (HashItem *pEntry = cnt; pEntry; pEntry = pEntry->hh.next) {
        if (pEntry->val == maxCnt) {
            ans[pos++] = pEntry->key;
        }
    }
    HashItem *curr, *tmp;
    HASH_ITER(hh, cnt, curr, tmp) {
        HASH_DEL(cnt, curr);  
        free(curr);
    }
    *returnSize = pos;
    return ans;
}
