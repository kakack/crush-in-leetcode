/*
You are given two linked lists representing two non-negative numbers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8

*/



/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//逻辑和算法很简单，只是操作链表的时候记得先new一个ListNode再去操作，然后不要破坏数组原有的形状，用一个新的指针去指向需要操作的数组的头部，然后操作指针来计算


class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode();
        ListNode *pre = res;
        int carry = 0;
        while (l1 || l2) {
            int x = (l1) ? l1->val : 0;
            int y = (l2) ? l2->val : 0;
            int ans = (x + y + carry) % 10;
            carry = (x + y + carry) / 10;
            pre->next = new ListNode(ans);
            pre = pre->next;
            if (l1) {
                l1 = l1->next;
            }
            if (l2) {
                l2 = l2->next;
            }
        }
        if (carry) {
            pre->next = new ListNode(carry);
        }
        return res->next;
    }
};