/*
LeetCode 143 - Reorder List

解题步骤（自动整理）
1. 用快慢指针/虚拟头节点等技巧处理链表边界
2. 按题意进行遍历、反转、合并或断链等操作
3. 返回处理后的链表头节点或计算结果
*/
/**
Reorder List
Given a singly linked list L: L0→L1→…→Ln-1→Ln,
reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…

You must do this in-place without altering the nodes' values.

For example,
Given {1,2,3,4}, reorder it to {1,4,2,3}.


 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void reorderList(ListNode *head) {

        if(head==NULL)
          return ;

          ListNode *p=head;

        int len=1;
        while(p->next!=NULL){
            len++;
            p=p->next;
        }

        p=head;
        for(int i=0;i<len/2;i++){
            p=p->next;
        }//p指向链表中点

        //然后将后半部分反转,最末接到链表中点上

        ListNode *curr=p->next;
        ListNode *next;
        p->next=NULL;

        while(curr!=NULL){
            next=curr->next;
            curr->next=p;
            p=curr;
            curr=next;
        }

        ListNode *h=head;

        while(h!=p&&h->next!=p){
            ListNode *tmpH=h->next;
            ListNode *tmpP=p->next;

            h->next=p;
            p->next=tmpH;
            h=tmpH;
            p=tmpP;
        }

        return ;

    }
};
