/*
We have a collection of stones, each stone has a positive integer weight.

Each turn, we choose the two heaviest stones and smash them together.  Suppose the stones have weights x and y with x <= y.  The result of this smash is:

If x == y, both stones are totally destroyed;
If x != y, the stone of weight x is totally destroyed, and the stone of weight y has new weight y-x.
At the end, there is at most 1 stone left.  Return the weight of this stone (or 0 if there are no stones left.)

 

Example 1:

Input: [2,7,4,1,8,1]
Output: 1
Explanation: 
We combine 7 and 8 to get 1 so the array converts to [2,4,1,1,1] then,
we combine 2 and 4 to get 2 so the array converts to [2,1,1,1] then,
we combine 2 and 1 to get 1 so the array converts to [1,1,1] then,
we combine 1 and 1 to get 0 so the array converts to [1] then that's the value of last stone.
 

Note:

1 <= stones.length <= 30
1 <= stones[i] <= 1000
*/

void swap(int * a, int * b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void push(int *heap, int *heapSize, int x) {
    heap[++(*heapSize)] = x;
    for (int i = (*heapSize); i > 1 && heap[i] > heap[i >> 1]; i >>= 1) {
        swap(&heap[i], &heap[i >> 1]);
    }
}

void pop(int *heap, int *heapSize) {
    int tmp = heap[1] = heap[(*heapSize)--];
    int i = 1, j = 2;
    while (j <= (*heapSize)) {
        if (j != (*heapSize) && heap[j + 1] > heap[j]) ++j;
        if (heap[j] > tmp) {
            heap[i] = heap[j];
            i = j;
            j = i << 1;
        } else {
            break;
        }
    }
    heap[i] = tmp;
}

int top(int *heap) {
    return heap[1];
}

int lastStoneWeight(int* stones, int stonesSize){
    if (stonesSize == 1) {
        return stones[0];
    } else if (stonesSize == 2) {
        return fabs(stones[1] - stones[0]);
    }
    int heap[stonesSize + 2], heapSize = 0;
    for (int i = 0; i < stonesSize; i ++) {
        push(heap, &heapSize, stones[i]);
    }
    while (heapSize > 1) {
        int a = top(heap);
        pop(heap, &heapSize);
        int b = top(heap);
        pop(heap, &heapSize);
        if (a > b) {
            push(heap, &heapSize, a - b);
        }
    }
    return heapSize ? top(heap) : 0;
}