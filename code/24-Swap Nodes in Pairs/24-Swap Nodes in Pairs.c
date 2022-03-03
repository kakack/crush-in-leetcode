/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode* swapPairs(struct ListNode* head){
    struct ListNode *p, *q, *pre;
    p = head;
    pre = head;
    while (p && p->next) {
        if (pre == head) {
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

