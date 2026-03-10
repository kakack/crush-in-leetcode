/*
LeetCode 117 - Populating Next Right Pointers in Each Node II

解题步骤（自动整理）
1. 维护栈（或单调栈）保存候选元素的下标/值
2. 遍历序列时根据出栈条件更新答案，再将当前元素入栈
3. 遍历结束后处理剩余元素（如需要）并返回结果
*/
// Given a binary tree

// struct Node {
//   int val;
//   Node *left;
//   Node *right;
//   Node *next;
// }
// Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.

// Initially, all next pointers are set to NULL.



// Example 1:


// Input: root = [1,2,3,4,5,null,7]
// Output: [1,#,2,3,#,4,5,7,#]
// Explanation: Given the above binary tree (Figure A), your function should populate each next pointer to point to its next right node, just like in Figure B. The serialized output is in level order as connected by the next pointers, with '#' signifying the end of each level.
// Example 2:

// Input: root = []
// Output: []


// Constraints:

// The number of nodes in the tree is in the range [0, 6000].
// -100 <= Node.val <= 100


// Follow-up:

// You may only use constant extra space.
// The recursive approach is fine. You may assume implicit stack space does not count as extra space for this problem.

/**
 * Definition for a Node.
 * struct Node {
 *     int val;
 *     struct Node *left;
 *     struct Node *right;
 *     struct Node *next;
 * };
 */

struct Node* connect(struct Node* root) {
	if (root == NULL) {
        return NULL;
    }
    struct Node** stk = (struct Node**)malloc(sizeof(struct Node*) * 6001);
    int head = 0, tail = 0;
    stk[tail ++] = root;
    while (head < tail) {
        int n = tail - head;
        struct Node *last = NULL;
        for (int i = 0; i < n; i ++) {
            struct Node * node = stk[head ++];
            if (node->left) {
                stk[tail ++] = node->left;
            }
            if (node->right) {
                stk[tail ++] = node->right;
            }
            if (i != 0) {
                last->next = node;
            }
            last = node;
        }
    }
    return root;
}
