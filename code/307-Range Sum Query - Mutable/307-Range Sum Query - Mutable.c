// Given an integer array nums, handle multiple queries of the following types:

// Update the value of an element in nums.
// Calculate the sum of the elements of nums between indices left and right inclusive where left <= right.
// Implement the NumArray class:

// NumArray(int[] nums) Initializes the object with the integer array nums.
// void update(int index, int val) Updates the value of nums[index] to be val.
// int sumRange(int left, int right) Returns the sum of the elements of nums between indices left and right inclusive (i.e. nums[left] + nums[left + 1] + ... + nums[right]).
 

// Example 1:

// Input
// ["NumArray", "sumRange", "update", "sumRange"]
// [[[1, 3, 5]], [0, 2], [1, 2], [0, 2]]
// Output
// [null, 9, null, 8]

// Explanation
// NumArray numArray = new NumArray([1, 3, 5]);
// numArray.sumRange(0, 2); // return 1 + 3 + 5 = 9
// numArray.update(1, 2);   // nums = [1, 2, 5]
// numArray.sumRange(0, 2); // return 1 + 2 + 5 = 8
 

// Constraints:

// 1 <= nums.length <= 3 * 10^4
// -100 <= nums[i] <= 100
// 0 <= index < nums.length
// -100 <= val <= 100
// 0 <= left <= right < nums.length
// At most 3 * 10^4 calls will be made to update and sumRange.

typedef struct {
    int * segmentTree;
    int numsSize; 
} NumArray;

void build(int * segmentTree, int node, int s, int e, const int * nums) {
    if (s == e) {
        segmentTree[node] = nums[s];
        return;
    }
    int m = s + (e - s) / 2;
    build(segmentTree, node * 2 + 1, s, m, nums);
    build(segmentTree, node * 2 + 2, m + 1, e, nums);
    segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2];
}

void change(int * segmentTree, int index, int val, int node, int s, int e) {
    if (s == e) {
        segmentTree[node] = val;
        return;
    }
    int m = s + (e - s) / 2;
    if (index <= m) {
        change(segmentTree, index, val, node * 2 + 1, s, m);
    } else {
        change(segmentTree, index, val, node * 2 + 2, m + 1, e);
    }
    segmentTree[node] = segmentTree[node * 2 + 1] + segmentTree[node * 2 + 2];
}

int range(const int * segmentTree, int left, int right, int node, int s, int e) {
    if (left == s && right == e) {
        return segmentTree[node];
    }
    int m = s + (e - s) / 2;
    if (right <= m) {
        return range(segmentTree, left, right, node * 2 + 1, s, m);
    } else if (left > m) {
        return range(segmentTree, left, right, node * 2 + 2, m + 1, e);
    } else {
        return range(segmentTree, left, m, node * 2 + 1, s, m) + \
               range(segmentTree, m + 1, right, node * 2 + 2, m + 1, e);
    }
}


NumArray* numArrayCreate(int* nums, int numsSize) {
    NumArray * obj = (int *)malloc(sizeof(NumArray));
    obj->numsSize = numsSize;
    obj->segmentTree = (int *)malloc(sizeof(int) * 4 * numsSize);
    build(obj->segmentTree, 0, 0, numsSize - 1, nums);
    return obj;
}

void numArrayUpdate(NumArray* obj, int index, int val) {
    change(obj->segmentTree, index, val, 0, 0, obj->numsSize - 1);
}

int numArraySumRange(NumArray* obj, int left, int right) {
    return range(obj->segmentTree, left, right, 0, 0, obj->numsSize - 1);
}

void numArrayFree(NumArray* obj) {
    free(obj->segmentTree);
    free(obj);
}


/**
 * Your NumArray struct will be instantiated and called as such:
 * NumArray* obj = numArrayCreate(nums, numsSize);
 * numArrayUpdate(obj, index, val);
 
 * int param_2 = numArraySumRange(obj, left, right);
 
 * numArrayFree(obj);
*/