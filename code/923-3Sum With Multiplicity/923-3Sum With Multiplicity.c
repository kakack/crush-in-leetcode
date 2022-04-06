// Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.

// As the answer can be very large, return it modulo 10^9 + 7.

 

// Example 1:

// Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
// Output: 20
// Explanation: 
// Enumerating by the values (arr[i], arr[j], arr[k]):
// (1, 2, 5) occurs 8 times;
// (1, 3, 4) occurs 8 times;
// (2, 2, 4) occurs 2 times;
// (2, 3, 3) occurs 2 times.
// Example 2:

// Input: arr = [1,1,2,2,2,2], target = 5
// Output: 12
// Explanation: 
// arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
// We choose one 1 from [1,1] in 2 ways,
// and two 2s from [2,2,2,2] in 6 ways.
 

// Constraints:

// 3 <= arr.length <= 3000
// 0 <= arr[i] <= 100
// 0 <= target <= 300


typedef struct {
    int key;
    int cnt;
    UT_hash_handle hh;
} HashItem;


int threeSumMulti(int* arr, int arrSize, int target){
    int sum = 0;
    HashItem *hm = NULL;
    for (int i = 1; i < arrSize; i ++) {
        int prev = arr[i - 1];
        HashItem * pEntry = NULL;
        HASH_FIND_INT(hm, &prev, pEntry);
        if (pEntry == NULL) {
            pEntry = (HashItem*)malloc(sizeof(HashItem));
            pEntry->key = prev;
            pEntry->cnt = 1;
            HASH_ADD_INT(hm, key, pEntry);
        } else {
            pEntry->cnt ++;
        }
        for (int j = i + 1; j < arrSize; j ++) {
            int item = target - arr[i] - arr[j];
            HashItem *tmp = NULL;
            HASH_FIND_INT(hm, &item, tmp);
            if (tmp != NULL) {
                sum += tmp->cnt;
            }
            sum = sum % 1000000007;
        }
    }
    return sum;
}