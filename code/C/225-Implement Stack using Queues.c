// Implement a last-in-first-out (LIFO) stack using only two queues. The implemented stack should support all the functions of a normal stack (push, top, pop, and empty).

// Implement the MyStack class:

// void push(int x) Pushes element x to the top of the stack.
// int pop() Removes the element on the top of the stack and returns it.
// int top() Returns the element on the top of the stack.
// boolean empty() Returns true if the stack is empty, false otherwise.
// Notes:

// You must use only standard operations of a queue, which means that only push to back, peek/pop from front, size and is empty operations are valid.
// Depending on your language, the queue may not be supported natively. You may simulate a queue using a list or deque (double-ended queue) as long as you use only a queue's standard operations.
 

// Example 1:

// Input
// ["MyStack", "push", "push", "top", "pop", "empty"]
// [[], [1], [2], [], [], []]
// Output
// [null, null, null, 2, 2, false]

// Explanation
// MyStack myStack = new MyStack();
// myStack.push(1);
// myStack.push(2);
// myStack.top(); // return 2
// myStack.pop(); // return 2
// myStack.empty(); // return False
 

// Constraints:

// 1 <= x <= 9
// At most 100 calls will be made to push, pop, top, and empty.
// All the calls to pop and top are valid.
 

// Follow-up: Can you implement the stack using only one queue?

typedef struct {
    int *que;
    int queCapacity;
    int head, tail;
} Queue;

Queue* queueCreate(int capacity) {
    Queue* ret = malloc(sizeof(Queue));
    ret->que = malloc(sizeof(int) * capacity);
    ret->head = 0;
    ret->tail = 0;
    ret->queCapacity = capacity;
    return ret;
}

void queuePush(Queue* obj, int x) {
    if (obj->tail < obj->queCapacity){
        obj->que[obj->tail ++] = x;
    } else {
        return;
    }
}

bool queueEmpty(Queue* obj) {
    return obj->head == obj->tail;
}

int queuePop(Queue* obj) {
    if (!queueEmpty(obj)){
        obj->tail --;
        return obj->que[obj->tail];
    } else {
        return 0;
    }
}

int queueTop(Queue* obj) {
    if (!queueEmpty(obj)){
        return obj->que[obj->tail - 1];
    } else {
        return 0;
    }
}

void freeQueue(Queue* obj) {
    free(obj->que);
    free(obj);
}

typedef struct {
    Queue* queue;
} MyStack;

MyStack* myStackCreate() {
    MyStack* ret = malloc(sizeof(MyStack));
    ret->queue = queueCreate(101);
    return ret;
}

void myStackPush(MyStack* obj, int x) {
    queuePush(obj->queue, x);
}

int myStackPop(MyStack* obj) {
    return queuePop(obj->queue);
}

int myStackTop(MyStack* obj) {
    return queueTop(obj->queue);
}

bool myStackEmpty(MyStack* obj) {
    return queueEmpty(obj->queue);
}

void myStackFree(MyStack* obj) {
    freeQueue(obj->queue);
    free(obj);
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/