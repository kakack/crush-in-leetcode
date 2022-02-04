// Given a reference of a node in a connected undirected graph.

// Return a deep copy (clone) of the graph.

// Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

// class Node {
//     public int val;
//     public List<Node> neighbors;
// }
 

// Test case format:

// For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

// An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

// The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

 

// Example 1:


// Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
// Output: [[2,4],[1,3],[2,4],[1,3]]
// Explanation: There are 4 nodes in the graph.
// 1st node (val = 1)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 2nd node (val = 2)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
// 3rd node (val = 3)'s neighbors are 2nd node (val = 2) and 4th node (val = 4).
// 4th node (val = 4)'s neighbors are 1st node (val = 1) and 3rd node (val = 3).
// Example 2:


// Input: adjList = [[]]
// Output: [[]]
// Explanation: Note that the input contains one empty list. The graph consists of only one node with val = 1 and it does not have any neighbors.
// Example 3:

// Input: adjList = []
// Output: []
// Explanation: This an empty graph, it does not have any nodes.
 

// Constraints:

// The number of nodes in the graph is in the range [0, 100].
// 1 <= Node.val <= 100
// Node.val is unique for each node.
// There are no repeated edges and no self-loops in the graph.
// The Graph is connected and all nodes can be visited starting from the given node.

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     int numNeighbors;
 *     struct Node** neighbors;
 * };
 */


// dfs

struct Node ** visited;

struct Node *dfs(struct Node *s) {
	if (s == NULL) {
        return NULL;
    }
    if (visited[s->val]) {
        return visited[s->val];
    }

    struct Node* cloneNode = (struct Node*)malloc(sizeof(struct Node));
    cloneNode->val = s->val;
    cloneNode->numNeighbors = s->numNeighbors;

    visited[cloneNode->val] = cloneNode;
    cloneNode->neighbors = (struct Node**)malloc(sizeof(struct Node*) * cloneNode->numNeighbors);

    for (int i = 0; i < cloneNode->numNeighbors; i ++) {
        cloneNode->neighbors[i] = dfs(s->neighbors[i]);
    }
    return cloneNode;
}

struct Node* cloneGraph(struct Node* s) {
    visited = (struct Node**)malloc(sizeof(struct Node*) * 101);
    memset(visited, 0, sizeof(struct Node*) * 101);
    return dfs(s);
}

// bfs

struct Node** visited;
int* state;  //数组存放结点状态 0：结点未创建 1：仅创建结点 2：结点已创建并已填入所有内容

void bfs(struct Node* s) {
    if (visited[s->val] && state[s->val] == 2) {
        return;
    }
    struct Node* neighbor;
    if (visited[s->val]) {
        neighbor = visited[s->val];
        neighbor->val = s->val;
        neighbor->numNeighbors = s->numNeighbors;
        neighbor->neighbors = (struct Node**)malloc(sizeof(struct Node*) * neighbor->numNeighbors);
    } else {
        // 如果没有被访问过，就克隆并存储在哈希表中
        neighbor = (struct Node*)malloc(sizeof(struct Node));
        neighbor->val = s->val;
        neighbor->numNeighbors = s->numNeighbors;
        neighbor->neighbors = (struct Node**)malloc(sizeof(struct Node*) * neighbor->numNeighbors);
        visited[s->val] = neighbor;
    }
    for (int i = 0; i < neighbor->numNeighbors; i++) {
        if (visited[s->neighbors[i]->val]) {
            neighbor->neighbors[i] = visited[s->neighbors[i]->val];
        } else {
            visited[s->neighbors[i]->val] = (struct Node*)malloc(sizeof(struct Node));
            state[s->neighbors[i]->val] = 1;
            neighbor->neighbors[i] = visited[s->neighbors[i]->val];
        }
    }
    state[neighbor->val] = 2;
}

struct Node* cloneGraph(struct Node* s) {
    if (s == NULL) {
        return NULL;
    }

    // 将题目给定的节点添加到队列
    struct Node *QUEUE[101], *p;
    int head = -1, eneighbor = -1, i, flag[101];

    visited = (struct Node**)malloc(sizeof(struct Node*) * 101);
    memset(visited, 0, sizeof(struct Node*) * 101);
    state = (int*)malloc(sizeof(int) * 101);
    memset(state, 0, sizeof(int) * 101);
    memset(flag, 0, sizeof(int) * 101);

    // 克隆第一个节点并存储到哈希表中
    QUEUE[++eneighbor] = s;

    // 广度优先搜索
    while (head != eneighbor) {
        // 取出队列的头节点
        p = QUEUE[++head];
        // 遍历该节点的邻居
        bfs(p);
        for (i = 0; i < p->numNeighbors; i++) {
            if (!flag[p->neighbors[i]->val]) {
                // 将邻居节点加入队列中
                QUEUE[++eneighbor] = p->neighbors[i];
                flag[p->neighbors[i]->val] = 1;
            }
        }
    }

    return visited[s->val];
}
