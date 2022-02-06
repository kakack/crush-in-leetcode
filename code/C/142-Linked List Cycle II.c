/*
Linked List Cycle II 

Given a linked list, return the node where the cycle begins. If there is no cycle, return null.

Follow up:
Can you solve it without using extra space?
*/


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
果然是个数学题，首先判断loop只要一快一慢两个指针走就可以了，如果相遇时候，那么我们令
head到环第一个节点长度为x，loop一周为y，从loop第一个节点到相遇的点距离为k
那么slow走过的总长度是：
t=x+n*y+k，n是未知整数，表示绕了loop已经n圈了
fast走过总长度是：
2t=x+m*y+k，表示绕loop已经m圈了
二式简化得到：x+k=(m-2n)y，也就是说从相遇点出发再走x的距离正好能到达一个loop起点

*/
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode *fast = head;
    struct ListNode *slow = head;
    while (fast) {
        slow = slow->next;
        if (!fast->next) {
            return NULL;
        } else {
            fast = fast->next->next;
        }
        if (fast == slow) {
            struct ListNode *tmp = head;
            while (tmp != slow) {
                tmp = tmp->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return NULL;
}

// struct ListNode *detectCycle(struct ListNode *head) {
//     struct ListNode *fast = head;
//     struct ListNode *slow = head;
//     if (!head || !head->next || !head->next->next) {
//         return NULL;
//     }
//     while (fast && fast->next) {
//         fast = fast->next->next;
//         slow = slow->next;
//         if (fast == slow) {
//             break;
//         }
//     }
//     if (!fast || !fast->next || !fast->next->next) {
//         return NULL;
//     }
//     struct ListNode *tmp = head;
//     while (tmp != slow) {
//         slow = slow->next;
//         tmp = tmp->next;
//     }
//     return tmp;
// }