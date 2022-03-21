// Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.

 

// Example 1:

// Input: nums = [1,1,1,2,2,3], k = 2
// Output: [1,2]
// Example 2:

// Input: nums = [1], k = 1
// Output: [1]
 

// Constraints:

// 1 <= nums.length <= 105
// k is in the range [1, the number of unique elements in the array].
// It is guaranteed that the answer is unique.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

struct hash_table {
    int key;
    int val;
    UT_hash_handle hh;
};

typedef struct hash_table* hash_ptr;

struct pair {
    int first;
    int second;
};

struct pair* heap;
int heapSize;

void swap(struct pair* a, struct pair* b) {
    struct pair t = *a;
    *a = *b, *b = t;
}

bool cmp(struct pair* a, struct pair* b) {
    return a->second < b->second;
}

struct pair top() {
    return heap[1];
}

int push(hash_ptr x) {
    heap[++heapSize].first = x->key;
    heap[heapSize].second = x->val;
    int p = heapSize, s;
    while (p > 1) {
        s = p >> 1;
        if (cmp(&heap[s], &heap[p])) return;
        swap(&heap[p], &heap[s]);
        p = s;
    }
}

int pop() {
    heap[1] = heap[heapSize--];
    int p = 1, s;
    while ((p << 1) <= heapSize) {
        s = p << 1;
        if (s < heapSize && cmp(&heap[s + 1], &heap[s])) s++;
        if (cmp(&heap[p], &heap[s])) return;
        swap(&heap[p], &heap[s]);
        p = s;
    }
}

int* topKFrequent(int* nums, int numsSize, int k, int* returnSize){
    hash_ptr head = NULL;
    hash_ptr p = NULL, tmp = NULL;
    for (int i = 0; i < numsSize; i ++) {
        HASH_FIND_INT(head, &nums[i], p);
        if (p == NULL) {
            p = malloc(sizeof(struct hash_table));
            p->key = nums[i];
            p->val = 1;
            HASH_ADD_INT(head, key, p);
        } else {
            p->val ++;
        }
    }
    heap = malloc(sizeof(struct pair) * (k + 1));
    heapSize = 0;

    HASH_ITER(hh, head, p, tmp) {
        if (heapSize == k) {
            struct pair tmp = top();
            if (tmp.second < p->val) {
                pop();
                push(p);
            }
        } else {
            push(p);
        }
    }
    *returnSize = k;
    int* ret = malloc(sizeof(int) * k);
    for (int i = 0; i < k; i++) {
        struct pair tmp = top();
        pop();
        ret[i] = tmp.first;
    }
    return ret;
}