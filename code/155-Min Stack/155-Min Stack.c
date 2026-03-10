/*
LeetCode 155 - Min Stack

解题步骤（自动整理）
1. 维护栈（或单调栈）保存候选元素的下标/值
2. 遍历序列时根据出栈条件更新答案，再将当前元素入栈
3. 遍历结束后处理剩余元素（如需要）并返回结果
*/
// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

// MinStack() initializes the stack object.
// void push(int val) pushes the element val onto the stack.
// void pop() removes the element on the top of the stack.
// int top() gets the top element of the stack.
// int getMin() retrieves the minimum element in the stack.
//

// Example 1:

// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2
//

// Constraints:

// -2^31 <= val <= 2^31 - 1
// Methods pop, top and getMin operations will always be called on non-empty stacks.
// At most 3 * 10^4 calls will be made to push, pop, top, and getMin.

typedef struct {
    int* min;
    int* origin;
    int minSize;
    int originSize;
} MinStack;


MinStack* minStackCreate() {
    MinStack* mStack = malloc(sizeof(MinStack));
    mStack->min = malloc(sizeof(int) * 30001);
    mStack->origin = malloc(sizeof(int) * 30001);
    mStack->minSize = 0;
    mStack->originSize = 0;
    return mStack;
}

void minStackPush(MinStack* obj, int val) {
    obj->origin[obj->originSize ++] = val;
    if (obj->minSize == 0 || val <= obj->min[obj->minSize - 1]) {
        obj->min[obj->minSize ++] = val;
    }
}

void minStackPop(MinStack* obj) {
    int tmp = obj->origin[obj->originSize - 1];
    obj->originSize --;
    if (tmp == obj->min[obj->minSize - 1]) {
        obj->minSize --;
    }
}

int minStackTop(MinStack* obj) {
    return obj->origin[obj->originSize - 1];
}

int minStackGetMin(MinStack* obj) {
    return obj->min[obj->minSize - 1];
}

void minStackFree(MinStack* obj) {
    free(obj->min);
    free(obj->origin);
    free(obj);
}

/**
 * Your MinStack struct will be instantiated and called as such:
 * MinStack* obj = minStackCreate();
 * minStackPush(obj, val);

 * minStackPop(obj);

 * int param_3 = minStackTop(obj);

 * int param_4 = minStackGetMin(obj);

 * minStackFree(obj);
*/
