/*
Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

//思路是先准备两个链表，一个存比partition小的值，small，一个存比partition大的值，large，最后把他们连起来即可，写的时候{1,2},2这个case一直过不了，一直说超时，后来看了评论才知道，需要把large的尾指针置null，不然最后结果是一个loop。

#include "vector"
using namespace std;

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode* preLess = new ListNode(0);
        ListNode* less = preLess;
        ListNode* preMore = new ListNode(0);
        ListNode* more = preMore;

        while (head != nullptr)
        {
            if (head->val < x) {
                less->next = head;
                less = less->next;
            } else {
                more->next = head;
                more = more->next; 
            }
            head = head->next;
        }
        less->next = preMore->next;
        more->next = nullptr;
        return preLess->next;
    }
};