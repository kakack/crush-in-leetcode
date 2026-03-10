/*
LeetCode 24 - Swap Nodes in Pairs

解题步骤（自动整理）
1. 用快慢指针/虚拟头节点等技巧处理链表边界
2. 按题意进行遍历、反转、合并或断链等操作
3. 返回处理后的链表头节点或计算结果
*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

class Solution {
public:
    ListNode *swapPairs(ListNode *head) {
        ListNode *p, *q, *pre;
        p = pre = head;
        while( p && p->next ) {
            if ( pre == head ){
                head = pre->next;
            }
            q = p->next;
            pre->next = p->next;
            p->next = p->next->next;
            q->next = p;
            pre = p;
            p = p->next;

        }
        return head;
    }
};
