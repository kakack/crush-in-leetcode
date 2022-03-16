// Design a HashSet without using any built-in hash table libraries.

// Implement MyHashSet class:

// void add(key) Inserts the value key into the HashSet.
// bool contains(key) Returns whether the value key exists in the HashSet or not.
// void remove(key) Removes the value key in the HashSet. If key does not exist in the HashSet, do nothing.
 

// Example 1:

// Input
// ["MyHashSet", "add", "add", "contains", "contains", "add", "contains", "remove", "contains"]
// [[], [1], [2], [1], [3], [2], [2], [2], [2]]
// Output
// [null, null, null, true, false, null, true, null, false]

// Explanation
// MyHashSet myHashSet = new MyHashSet();
// myHashSet.add(1);      // set = [1]
// myHashSet.add(2);      // set = [1, 2]
// myHashSet.contains(1); // return True
// myHashSet.contains(3); // return False, (not found)
// myHashSet.add(2);      // set = [1, 2]
// myHashSet.contains(2); // return True
// myHashSet.remove(2);   // set = [1]
// myHashSet.contains(2); // return False, (already removed)
 

// Constraints:

// 0 <= key <= 106
// At most 104 calls will be made to add, remove, and contains.

typedef struct {
    int* data;
    int count;
} MyHashSet;


MyHashSet* myHashSetCreate() {
    MyHashSet* newHash= (MyHashSet* )malloc(sizeof(MyHashSet));
    newHash->data = (int* )calloc(1000001,sizeof(int));
    newHash->count = 0;
    return newHash;
}


void myHashSetAdd(MyHashSet* obj, int key) {
    if (obj->data[key] == 0) {
        obj->count ++;
    }
    obj->data[key] = 1;
}

void myHashSetRemove(MyHashSet* obj, int key) {
    if (obj->data[key]) {
        obj->count --;
    }
    obj->data[key] = 0;
}

bool myHashSetContains(MyHashSet* obj, int key) {
    if (obj->count == 0) {
        return false;
    }
    if (obj->data[key]) {
        return true;
    }
    return false;
}

void myHashSetFree(MyHashSet* obj) {
    free(obj->data);
    free(obj);
}

/**
 * Your MyHashSet struct will be instantiated and called as such:
 * MyHashSet* obj = myHashSetCreate();
 * myHashSetAdd(obj, key);
 
 * myHashSetRemove(obj, key);
 
 * bool param_3 = myHashSetContains(obj, key);
 
 * myHashSetFree(obj);
*/