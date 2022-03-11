// There is a binary tree rooted at 0 consisting of n nodes. The nodes are labeled from 0 to n - 1. You are given a 0-indexed integer array parents representing the tree, where parents[i] is the parent of node i. Since node 0 is the root, parents[0] == -1.

// Each node has a score. To find the score of a node, consider if the node and the edges connected to it were removed. The tree would become one or more non-empty subtrees. The size of a subtree is the number of the nodes in it. The score of the node is the product of the sizes of all those subtrees.

// Return the number of nodes that have the highest score.

 

// Example 1:

// example-1
// Input: parents = [-1,2,0,2,0]
// Output: 3
// Explanation:
// - The score of node 0 is: 3 * 1 = 3
// - The score of node 1 is: 4 = 4
// - The score of node 2 is: 1 * 1 * 2 = 2
// - The score of node 3 is: 4 = 4
// - The score of node 4 is: 4 = 4
// The highest score is 4, and three nodes (node 1, node 3, and node 4) have the highest score.
// Example 2:

// example-2
// Input: parents = [-1,2,0]
// Output: 2
// Explanation:
// - The score of node 0 is: 2 = 2
// - The score of node 1 is: 2 = 2
// - The score of node 2 is: 1 * 1 = 1
// The highest score is 2, and two nodes (node 0 and node 1) have the highest score.
 

// Constraints:

// n == parents.length
// 2 <= n <= 105
// parents[0] == -1
// 0 <= parents[i] <= n - 1 for i != 0
// parents represents a valid binary tree.

int dfs(int node, long * maxScore, int * cnt, int n, const struct ListNode ** children) {
    long score = 1;
    int size = n - 1;
    for (struct ListNode * curr = children[node]; curr; curr = curr->next) {
        int t = dfs(curr->val, maxScore, cnt, n, children);
        score *= t;
        size -= t;
    }
    if (node != 0) {
        score *= size;
    }
    if (score == *maxScore) {
        (*cnt)++;
    } else if (score > *maxScore) {
        *maxScore = score;
        *cnt = 1;
    }
    return n - size;
}

int countHighestScoreNodes(int* parents, int parentsSize){
    int n = parentsSize;
    int cnt = 0;
    long maxScore = 0;
    struct ListNode ** children = (struct ListNode **)malloc(sizeof(struct ListNode *) * n);
    for (int i = 0; i < n; i++) {
        children[i] = NULL;
    }
    for (int i = 0; i < n; i++) {
        int p = parents[i];
        if (p != -1) {
            struct ListNode * node = (struct ListNode *)malloc(sizeof(struct ListNode));
            node->val = i;
            node->next = children[p];
            children[p] = node;
        }
    }
    dfs(0, &maxScore, &cnt, n, children);
    for (int i = 0; i < n; i++) {
        for (struct ListNode * curr = children[i]; curr; ) {
            struct ListNode * next = curr->next;
            free(curr);
            curr = next;
        }
    }
    free(children);
    return cnt;
}
