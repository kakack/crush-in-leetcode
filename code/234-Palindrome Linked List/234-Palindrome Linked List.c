/*
LeetCode 234 - Palindrome Linked List

解题步骤（自动整理）
1. 用快慢指针/虚拟头节点等技巧处理链表边界
2. 按题意进行遍历、反转、合并或断链等操作
3. 返回处理后的链表头节点或计算结果
*/
// Given the head of a singly linked list, return true if it is a palindrome.



// Example 1:


// Input: head = [1,2,2,1]
// Output: true
// Example 2:


// Input: head = [1,2]
// Output: false


// Constraints:

// The number of nodes in the list is in the range [1, 10^5].
// 0 <= Node.val <= 9


// Follow up: Could you do it in O(n) time and O(1) space?

bool isPalindrome(struct ListNode* head){
    int *q = malloc(sizeof(int) * 100001);
    struct ListNode *p = head;
    int l = 0, r = 0;
    while (p) {
        q[r ++] = p->val;
        p = p->next;
    }
    r --;
    while (l < r) {
        if (q[l ++] != q[r --]) {
            return false;
        }
    }
    return true;
}
