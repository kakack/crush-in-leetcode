/*
LeetCode 82 - Remove Duplicates from Sorted List II

解题步骤（自动整理）
1. 用快慢指针/虚拟头节点等技巧处理链表边界
2. 按题意进行遍历、反转、合并或断链等操作
3. 返回处理后的链表头节点或计算结果
*/
/*
Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.



Example 1:


Input: head = [1,2,3,3,4,4,5]
Output: [1,2,5]
Example 2:


Input: head = [1,1,1,2,3]
Output: [2,3]


Constraints:

The number of nodes in the list is in the range [0, 300].
-100 <= Node.val <= 100
The list is guaranteed to be sorted in ascending order.
*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
      ListNode *deleteDuplicates(ListNode *head) {
          if (!head || !head->next) return head;
          ListNode *p = head->next;
          if (head->val == p->val) {
              while (p && head->val == p->val) {
                  ListNode *tmp = p;
                  p = p->next;
                  delete tmp;
              }
              delete head;
              return deleteDuplicates(p);
          } else {
              head->next = deleteDuplicates(head->next);
              return head;
            }
      }
};
