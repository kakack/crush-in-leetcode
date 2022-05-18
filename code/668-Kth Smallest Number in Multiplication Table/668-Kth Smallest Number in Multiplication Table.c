// Nearly everyone has used the Multiplication Table. The multiplication table of size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).

// Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.

 

// Example 1:


// Input: m = 3, n = 3, k = 5
// Output: 3
// Explanation: The 5th smallest number is 3.
// Example 2:


// Input: m = 2, n = 3, k = 6
// Output: 6
// Explanation: The 6th smallest number is 6.
 

// Constraints:

// 1 <= m, n <= 3 * 10^4
// 1 <= k <= m * n


int count(int m, int n, int x) {
    int res = 0;
    for (int i = 1; i <= m; i++) {
        res += fmin(x / i, n);
    }
    return res;
}


int findKthNumber(int m, int n, int k){
    int left = 1, right = m * n;
    while (left < right) {
        int mid = (left + right) / 2;
        if (count(m, n, mid) >= k) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}