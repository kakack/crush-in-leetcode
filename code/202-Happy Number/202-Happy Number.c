// Write an algorithm to determine if a number n is happy.

// A happy number is a number defined by the following process:

// Starting with any positive integer, replace the number by the sum of the squares of its digits.
// Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
// Those numbers for which this process ends in 1 are happy.
// Return true if n is a happy number, and false if not.

 

// Example 1:

// Input: n = 19
// Output: true
// Explanation:
// 12 + 92 = 82
// 82 + 22 = 68
// 62 + 82 = 100
// 12 + 02 + 02 = 1
// Example 2:

// Input: n = 2
// Output: false
 

// Constraints:

// 1 <= n <= 2^31 - 1


typedef struct {
    int key;
    UT_hash_handle hh;
} HashItem;

int cal(int n) {
    int res = 0;
    while(n) {
        res += (n % 10) * (n % 10);
        n /= 10;
    }
    return res;
}

bool isHappy(int n){
    HashItem *cnt = NULL;
    while (n != 1) {
        HashItem *pEntry = NULL;
        HASH_FIND_INT(cnt, &n, pEntry);
        if (pEntry == NULL) {
            pEntry = (HashItem*)malloc(sizeof(HashItem));
            pEntry->key = n;
            HASH_ADD_INT(cnt, key, pEntry);
        } else {
            return false;
        }
        n = cal(n);
    }
    return true;
}