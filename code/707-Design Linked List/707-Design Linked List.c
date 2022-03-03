// Design your implementation of the linked list. You can choose to use a singly or doubly linked list.
// A node in a singly linked list should have two attributes: val and next. val is the value of the current node, and next is a pointer/reference to the next node.
// If you want to use the doubly linked list, you will need one more attribute prev to indicate the previous node in the linked list. Assume all nodes in the linked list are 0-indexed.

// Implement the MyLinkedList class:

// MyLinkedList() Initializes the MyLinkedList object.
// int get(int index) Get the value of the indexth node in the linked list. If the index is invalid, return -1.
// void addAtHead(int val) Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list.
// void addAtTail(int val) Append a node of value val as the last element of the linked list.
// void addAtIndex(int index, int val) Add a node of value val before the indexth node in the linked list. If index equals the length of the linked list, the node will be appended to the end of the linked list. If index is greater than the length, the node will not be inserted.
// void deleteAtIndex(int index) Delete the indexth node in the linked list, if the index is valid.
 

// Example 1:

// Input
// ["MyLinkedList", "addAtHead", "addAtTail", "addAtIndex", "get", "deleteAtIndex", "get"]
// [[], [1], [3], [1, 2], [1], [1], [1]]
// Output
// [null, null, null, null, 2, null, 3]

// Explanation
// MyLinkedList myLinkedList = new MyLinkedList();
// myLinkedList.addAtHead(1);
// myLinkedList.addAtTail(3);
// myLinkedList.addAtIndex(1, 2);    // linked list becomes 1->2->3
// myLinkedList.get(1);              // return 2
// myLinkedList.deleteAtIndex(1);    // now the linked list is 1->3
// myLinkedList.get(1);              // return 3
 

// Constraints:

// 0 <= index, val <= 1000
// Please do not use the built-in LinkedList library.
// At most 2000 calls will be made to get, addAtHead, addAtTail, addAtIndex and deleteAtIndex.

typedef struct Node{
    int val;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    int n;
} MyLinkedList;


MyLinkedList* myLinkedListCreate() {
    MyLinkedList* res = malloc(sizeof(MyLinkedList));
    res->head = malloc(sizeof(Node));
    res->head->next = NULL;
    res->head->val = 0;
    res->n = 0;
    return res;
}

int myLinkedListGet(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->n) {
         return -1;
    }
    Node* p = obj->head;
    for (int i = 0; i <= index; i ++) {
        p = p->next;
    }
    return p->val;
}

void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
    Node* q = malloc(sizeof(Node));
    q->val = val;
    q->next = obj->head->next;
    obj->head->next = q;
    obj->n++;
}

void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
    Node* p = obj->head;
    for (int i = 0; i < obj->n; i ++) {
        p = p->next;
    }
    p->next = malloc(sizeof(Node));
    p->next->val = val;
    obj->n ++;
}

void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
    if (index == obj->n) {
        myLinkedListAddAtTail(obj, val);
    } else if (index <= 0) {
        myLinkedListAddAtHead(obj, val);
    } else if (index > obj->n) {
        return;
    } else {
        Node *p = obj->head;
        Node *q = malloc(sizeof(Node));
        q->val = val;
        for (int i = 0; i < index; i ++) {
            p = p->next;
        }
        q->next = p->next;
        p->next = q;
        obj->n ++;
    }
}

void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
    if (index < 0 || index >= obj->n) {
        return;
    } else {
        Node *p = obj->head;
        for (int i = 0; i < index; i ++) {
            p = p->next;
        }
        p->next = p->next->next;
        obj->n --;
    }
}

void myLinkedListFree(MyLinkedList* obj) {
    free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 
 * myLinkedListAddAtHead(obj, val);
 
 * myLinkedListAddAtTail(obj, val);
 
 * myLinkedListAddAtIndex(obj, index, val);
 
 * myLinkedListDeleteAtIndex(obj, index);
 
 * myLinkedListFree(obj);
*/