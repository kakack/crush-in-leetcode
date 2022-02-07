// Given the head of a linked list, rotate the list to the right by k places.

 

// Example 1:


// Input: head = [1,2,3,4,5], k = 2
// Output: [4,5,1,2,3]
// Example 2:


// Input: head = [0,1,2], k = 4
// Output: [2,0,1]
 

// Constraints:

// The number of nodes in the list is in the range [0, 500].
// -100 <= Node.val <= 100
// 0 <= k <= 2 * 109

struct ListNode* rotateRight(struct ListNode* head, int k){
    if (!head || !k) {
        return head;
    }
    int count = 1;
    struct ListNode *fast = head, *slow = head;
    while (fast->next) {
        fast = fast->next;
        count ++;
    }
    k = count - k % count; 
    while (k > 1) {
        slow = slow->next;
        k --;
    }
    fast->next = head;
    struct ListNode *res = slow->next;
    slow->next = NULL;
    return res;
}

struct ListNode* rotateRight(struct ListNode* head, int k){
    if (!head || !k) {
        return head;
    }
    int count = k;
    struct ListNode *fast = head, *slow = head;
    for (int i = 0; i < k; i ++) {
        if (fast->next) {
            fast = fast->next;
        } else {
            fast = head;
        }
    }
    while (fast->next) {
        fast = fast->next;
        slow = slow->next;
    }
    fast->next = head;
    struct ListNode *res = slow->next;
    slow->next = NULL;
    return res;
}