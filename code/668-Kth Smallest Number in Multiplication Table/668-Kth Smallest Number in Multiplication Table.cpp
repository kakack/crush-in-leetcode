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

// 于第 i行的数字分别是i, 2*i, 3*i, 4*i...，因此这一行小于等于x的数的个数是min(x/i, n)
// 那么矩阵中小于x的数字个数就是各行的累加sum(min(x/i, n))
// 本题的目标就是求 $\sum^m_{i=1}min(x/i, n)=k $时，x的值，可以用二分法进行尝试，即有一个最大值和最小值，将其二分之一值代入后看看是大了还是小了，然后再调整上下边界


class Solution {
private:
    int count(int m, int n, int x) {
        int res = 0;
        for (int i = 1; i <= m; i++) {
            res += min(x / i, n);
        }
        return res;
    }
public:
    int findKthNumber(int m, int n, int k) {
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
};