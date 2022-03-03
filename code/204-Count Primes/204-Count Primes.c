/*
Count the number of prime numbers less than a non-negative number, n.

 

Example 1:

Input: n = 10
Output: 4
Explanation: There are 4 prime numbers less than 10, they are 2, 3, 5, 7.
Example 2:

Input: n = 0
Output: 0
Example 3:

Input: n = 1
Output: 0
 

Constraints:

0 <= n <= 5 * 106
*/
// bool isPrime(int x) {
//     for (int i = 2; i * i <= x; i ++) {
//         if ( x % i == 0) {
//             return false;
//         }
//     }
//     return true;
// }

// int countPrimes(int n){
//     int ans = 0;
//     for (int i = 2; i < n; i ++) {
//         ans += isPrime(i);
//     }
//     return ans;
// }

int countPrimes(int n){
    if (n < 2) {
        return 0;
    }
    int* isPrime = malloc(sizeof(int)*n);
    memset(isPrime, 0, sizeof(int)*n);
    isPrime[0] = 0, isPrime[1] = 0;
    int ans = 0;
    for (int i = 2; i < n; i ++) {
        if (!isPrime[i]) {
            ans ++;
            if ((long long)i * i < n) {
                for (int j = i * i; j < n; j += i) {
                    isPrime[j] = 1;
                }
            }
        }
    }
    return ans;
}