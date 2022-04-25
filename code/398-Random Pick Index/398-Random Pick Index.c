Given an integer array nums with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.

// Implement the Solution class:

// Solution(int[] nums) Initializes the object with the array nums.
// int pick(int target) Picks a random index i from nums where nums[i] == target. If there are multiple valid i's, then each index should have an equal probability of returning.
 

// Example 1:

// Input
// ["Solution", "pick", "pick", "pick"]
// [[[1, 2, 3, 3, 3]], [3], [1], [3]]
// Output
// [null, 4, 0, 2]

// Explanation
// Solution solution = new Solution([1, 2, 3, 3, 3]);
// solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
// solution.pick(1); // It should return 0. Since in the array only nums[0] is equal to 1.
// solution.pick(3); // It should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
 

// Constraints:

// 1 <= nums.length <= 2 * 10^4
// -2^31 <= nums[i] <= 2^31 - 1
// target is an integer from nums.
// At most 104 calls will be made to pick


typedef struct {
    int key;
    int *array;
    int capacity;
    int size;
    UT_hash_handle hh;
} HashItem;


typedef struct {
    HashItem *pos;
} Solution;
void hashInsert(HashItem **obj, int key, int idx) {
    HashItem * pEntry = NULL;
    HASH_FIND_INT(*obj, &key, pEntry);
    if (!pEntry) {
        pEntry = malloc(sizeof(HashItem));
        pEntry->key = key;
        pEntry->capacity = 64;
        pEntry->size = 0;
        pEntry->array = calloc(pEntry->capacity, sizeof(int));
        HASH_ADD_INT(*obj, key, pEntry);
    }
    if (pEntry->size == pEntry->capacity) {
        pEntry->capacity *= 2; 
        pEntry->array = realloc(pEntry->array, pEntry->capacity * sizeof(int));
    }
    pEntry->array[(pEntry->size)++] = idx;
}

Solution* solutionCreate(int* nums, int numsSize) {
    Solution *obj = (Solution*)malloc(sizeof(Solution));
    obj->pos = NULL;
    for (int i = 0; i < numsSize; i ++) {
        hashInsert(&obj->pos, nums[i], i);
    }
    return obj;
}

int solutionPick(Solution* obj, int target) {
    HashItem *pEntry = NULL;
    HASH_FIND_INT(obj->pos, &target, pEntry);
    if (!pEntry) {
        return -1;
    }
    return pEntry->array[rand() % pEntry->size];
}

void solutionFree(Solution* obj) {
    HashItem *curr, *tmp;
    HASH_ITER(hh, obj->pos, curr, tmp) {
        HASH_DEL(obj->pos, curr);
        free(curr->array);
        free(curr);
    }
    free(obj);
}

/**
 * Your Solution struct will be instantiated and called as such:
 * Solution* obj = solutionCreate(nums, numsSize);
 * int param_1 = solutionPick(obj, target);
 
 * solutionFree(obj);
*/

typedef struct {
    int *nums;
    int numsSize;
} Solution;

Solution* solutionCreate(int* nums, int numsSize) {
    Solution *obj = (Solution*)malloc(sizeof(Solution));
    obj->nums = nums;
    obj->numsSize = numsSize;
    return obj;
}

int solutionPick(Solution* obj, int target) {
    int ans;
    int cnt = 0;
    for (int i = 0; i < obj->numsSize; i ++) {
        if (obj->nums[i] == target) {
            cnt ++;
            if (rand() % cnt == 0) {
                ans = i;
            }
        }
    }
    return ans;
}

void solutionFree(Solution* obj) {
    free(obj);
}