/*
LeetCode 21 - Merge Two Sorted Lists

解题步骤（自动整理）
1. 用快慢指针/虚拟头节点等技巧处理链表边界
2. 按题意进行遍历、反转、合并或断链等操作
3. 返回处理后的链表头节点或计算结果
*/
/*Merge Two Sorted Lists
Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.
 *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */


// 之前写的什么垃圾

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *preHead = new ListNode();
        ListNode *cur = preHead;
        while (list1 && list2) {
            if (list1->val <= list2->val) {
                cur->next = list1;
                list1 = list1->next;
            } else {
                cur->next = list2;
                list2 = list2->next;
            }
            cur = cur->next;
        }
        if (list1) {
            cur->next = list1;
        } else {
            cur->next = list2;
        }
        return preHead->next;
    }
};
// class Solution {
// public:
//     ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
//         if(l1==NULL)
//           return l2;
//         else if(l2==NULL)
//           return l1;

//         ListNode res(-1);
//         ListNode *tmp = &res;//链表赋初值的办法，要掌握一下
//         while(l1!=NULL&&l2!=NULL){
//             if(l1->val<=l2->val){
//                 tmp->next = l1;
//                 l1 = l1->next;
//             }
//             else{
//                 tmp->next = l2;
//                 l2 = l2->next;
//             }
//             tmp = tmp->next;
//         }

//         if(l1!=NULL)
//           tmp->next = l1;
//         else if(l2!=NULL)
//           tmp->next = l2;

//         return res.next;
//     }
// };
