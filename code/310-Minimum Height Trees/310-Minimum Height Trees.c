// A tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.

// Given a tree of n nodes labelled from 0 to n - 1, and an array of n - 1 edges where edges[i] = [ai, bi] indicates that there is an undirected edge between the two nodes ai and bi in the tree, you can choose any node of the tree as the root. When you select a node x as the root, the result tree has height h. Among all possible rooted trees, those with minimum height (i.e. min(h))  are called minimum height trees (MHTs).

// Return a list of all MHTs' root labels. You can return the answer in any order.

// The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

 

// Example 1:


// Input: n = 4, edges = [[1,0],[1,2],[1,3]]
// Output: [1]
// Explanation: As shown, the height of the tree is 1 when the root is the node with label 1 which is the only MHT.
// Example 2:


// Input: n = 6, edges = [[3,0],[3,1],[3,2],[3,4],[5,4]]
// Output: [3,4]
 

// Constraints:

// 1 <= n <= 2 * 104
// edges.length == n - 1
// 0 <= ai, bi < n
// ai != bi
// All the pairs (ai, bi) are distinct.
// The given input is guaranteed to be a tree and there will be no repeated edges.

int findLongestNode(int u, int * parent, const struct ListNode ** adj, int n) {
    int * queue = (int *)malloc(sizeof(int) * n);
    int head = 0, tail = 0;
    bool * visit = (bool *)malloc(sizeof(bool) * n);
    memset(visit, 0, sizeof(bool) * n);
    queue[tail++] = u;
    visit[u] = true;
    int res = -1;

    while (head != tail) {
        int curr = queue[head++];
        res = curr;
        struct ListNode * node = adj[curr];
        while (node) {
            if (!visit[node->val]) {
                visit[node->val] = true;
                parent[node->val] = curr;
                queue[tail++] = node->val;
            }
            node = node->next;
        }
    }
    free(queue);
    free(visit);
    return res;
}

int* findMinHeightTrees(int n, int** edges, int edgesSize, int* edgesColSize, int* returnSize){
    int * res = NULL;
    if (n == 1) {
        res = (int *)malloc(sizeof(int));
        *res = 0;
        *returnSize = 1;
        return res;
    }

    struct ListNode ** adj = (struct ListNode *)malloc(sizeof(struct ListNode *) * n);
    for (int i = 0; i < n; i++) {
        adj[i] = NULL;
    }
    for (int i = 0; i < edgesSize; i++) {
        int u = edges[i][0];
        int v = edges[i][1];
        struct ListNode * node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = u;
        node->next = adj[v];
        adj[v] = node;
        node = (struct ListNode *)malloc(sizeof(struct ListNode));
        node->val = v;
        node->next = adj[u];
        adj[u] = node;
    }
    
    int * parent = (int *)malloc(sizeof(int) * n);
    /* 找到与节点 0 最远的节点 x */
    int x = findLongestNode(0, parent, adj, n);
    /* 找到与节点 x 最远的节点 y */
    int y = findLongestNode(x, parent, adj, n);
    /* 求出节点 x 到节点 y 的路径 */
    int * path = (int *)malloc(sizeof(int) * n);
    int pos = 0;
    parent[x] = -1;
    while (y != -1) {
        path[pos++] = y;
        y = parent[y];
    }
    if (pos % 2 == 0) {
        res = (int *)malloc(sizeof(int) * 2);
        res[0] = path[pos / 2 - 1];
        res[1] = path[pos / 2];
        *returnSize = 2;
    } else {
        res = (int *)malloc(sizeof(int));
        *res = path[pos / 2];
        *returnSize = 1;
    }
    free(path);
    free(parent);
    for (int i = 0; i < n; i++) {
        struct ListNode * node = adj[i];
        while (node) {
            struct ListNode * curr = node;
            node = curr->next;
            free(curr);
        }
    }
    free(adj);
    return res;
}