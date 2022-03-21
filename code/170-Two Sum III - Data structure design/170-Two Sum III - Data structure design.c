// Design a data structure that accepts a stream of integers and checks if it has a pair of integers that sum up to a particular value.

// Implement the TwoSum class:

// TwoSum() Initializes the TwoSum object, with an empty array initially.
// void add(int number) Adds number to the data structure.
// boolean find(int value) Returns true if there exists any pair of numbers whose sum is equal to value, otherwise, it returns false.
//  

// Example 1:

// Input
// ["TwoSum", "add", "add", "add", "find", "find"]
// [[], [1], [3], [5], [4], [7]]
// Output
// [null, null, null, null, true, false]

// Explanation
// TwoSum twoSum = new TwoSum();
// twoSum.add(1);   // [] --> [1]
// twoSum.add(3);   // [1] --> [1,3]
// twoSum.add(5);   // [1,3] --> [1,3,5]
// twoSum.find(4);  // 1 + 3 = 4, return true
// twoSum.find(7);  // No two integers sum up to 7, return false
//  

// Constraints:

// -10^5 <= number <= 10^5
// -2^31 <= value <= 2^31 - 1
// At most 104 calls will be made to add and find.

typedef struct {
    long key;
    int cnt;
    UT_hash_handle hh;
} HashItem;

typedef struct {
    HashItem* hashMap;
} TwoSum;


TwoSum* twoSumCreate() {
    TwoSum* obj = (TwoSum*)malloc(sizeof(TwoSum));
    obj->hashMap = NULL;
    return obj;
}

void twoSumAdd(TwoSum* obj, int number) {
    HashItem *pEntry = NULL;
    long val = (long)number;
    HASH_FIND(hh, obj->hashMap, &val, sizeof(long), pEntry);
    if (pEntry == NULL) {
        pEntry = (HashItem*)malloc(sizeof(HashItem));
        pEntry->key = val;
        pEntry->cnt = 1;
        HASH_ADD(hh, obj->hashMap, key, sizeof(long), pEntry);
    } else {
        pEntry->cnt ++;
    }
}

bool twoSumFind(TwoSum* obj, int value) {
    HashItem *iter = NULL, *curr = NULL;
    HASH_ITER(hh, obj->hashMap, iter, curr) {
        long diff = (long)value - iter->key;
        HashItem *tmp = NULL;
        HASH_FIND(hh, obj->hashMap, &diff, sizeof(long), tmp);
        if (tmp != NULL) {
            if (diff != iter->key || tmp->cnt > 1) {
                return true;
            }
        }
    }
    return false;
}

void twoSumFree(TwoSum* obj) {

}

/**
 * Your TwoSum struct will be instantiated and called as such:
 * TwoSum* obj = twoSumCreate();
 * twoSumAdd(obj, number);
 
 * bool param_2 = twoSumFind(obj, value);
 
 * twoSumFree(obj);
*/