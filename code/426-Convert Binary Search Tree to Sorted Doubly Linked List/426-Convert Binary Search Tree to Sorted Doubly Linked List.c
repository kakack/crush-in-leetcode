/*
LeetCode 426 - Convert Binary Search Tree to Sorted Doubly Linked List

解题步骤（自动整理）
1. 用快慢指针/虚拟头节点等技巧处理链表边界
2. 按题意进行遍历、反转、合并或断链等操作
3. 返回处理后的链表头节点或计算结果
*/
// Convert a Binary Search Tree to a sorted Circular Doubly-Linked List in place.

// You can think of the left and right pointers as synonymous to the predecessor and successor pointers in a doubly-linked list. For a circular doubly linked list, the predecessor of the first element is the last element, and the successor of the last element is the first element.

// We want to do the transformation in place. After the transformation, the left pointer of the tree node should point to its predecessor, and the right pointer should point to its successor. You should return the pointer to the smallest element of the linked list.

//

// Example 1:



// Input: root = [4,2,5,1,3]


// Output: [1,2,3,4,5]

// Explanation: The figure below shows the transformed BST. The solid line indicates the successor relationship, while the dashed line means the predecessor relationship.

// Example 2:

// Input: root = [2,1,3]
// Output: [1,2,3]
//

// Constraints:

// The number of nodes in the tree is in the range [0, 2000].
// -1000 <= Node.val <= 1000
// All the values of the tree are unique.


/*
// Definition for a Node.
struct Node {
    int val;
    struct Node* left;
    struct Node* right;
};
*/

void inorder(struct Node *node, struct Node **first, struct Node **last) {
    if (node != NULL) {
        inorder(node->left, first, last);
        if (*last != NULL) {
            (*last)->right = node;
            node->left = *last;
        } else {
            *first = node;
        }
        *last = node;
        inorder(node->right, first, last);
    }
}

struct Node* treeToDoublyList(struct Node *root) {
    if (root == NULL) {
        return NULL;
    }
    struct Node *first = NULL;
    struct Node *last = NULL;
    inorder(root, &first, &last);
    last->right = first;
    first->left = last;
    return first;
}
