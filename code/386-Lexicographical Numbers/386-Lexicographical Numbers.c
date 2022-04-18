
// Given an integer n, return 1 - n in lexicographical order.

// For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].

// Please optimize your algorithm to use less time and space.
// The input size may be as large as 5,000,000.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* lexicalOrder(int n, int* returnSize){
    int *res = (int*)malloc(sizeof(int) * n);
    int num = 1;
    for (int i = 0; i < n; i ++) {
        res[i] = num;
        if (num *10 <= n) {
            num *= 10;
        } else {
            while (num % 10 == 9 || num + 1 > n) {
                num /= 10;
            }
            num ++;
        }
    }
    *returnSize = n;
    return res;
}