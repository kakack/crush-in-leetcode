/*
LeetCode 116 - Populating Next Right Pointers in Each Node

解题步骤（自动整理）
1. 将起点/初始层入队，并用 visited 或原地标记避免重复访问
2. 按层或按队列弹出元素扩展相邻节点，满足条件时更新答案
3. 队列处理完毕后返回结果（或在首次到达目标时提前返回）
*/
// You are given a perfect binary tree where all leaves are on the same level, and every parent has two children. The binary tree has the following definition:

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.



// Example 1:


// Input: root = [1,2,3,4,5,6,7]
// Output: [1,#,2,3,#,4,5,6,7,#]
// Explanation: Given the above perfect binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
// Example 2:

// Input: root = []
// Output: []


// Constraints:

// The number of nodes in the tree is in the range [0, 212 - 1].
// -1000 <= Node.val <= 1000


// Follow-up:

// You may only use constant extra space.
// The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.

/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    // 深度优先
    void build(Node* root) {
        if (root == nullptr) {
            return;
        }
        if (root->left != nullptr) {
            root->left->next = root->right;
        }
        if (root->right != nullptr && root->next != nullptr) {
            root->right->next = root->next->left;
        }
        build(root->left);
        build(root->right);
    }

    Node* connect(Node* root) {
        build(root);
        return root;
    }

    // 广度优先
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        queue<Node*> que;
        que.push(root);
        while (!que.empty()) {
            int len = que.size();
            for (int i = 0; i < len; i ++) {
                Node* n = que.front();
                que.pop();
                if (i == len - 1){
                    n->next = nullptr;
                } else {
                    n->next = que.front();
                }
                if (n->left != nullptr) {
                    que.push(n->left);
                }
                if (n->right != nullptr) {
                    que.push(n->right);
                }
            }
        }
        return root;
    }
};

