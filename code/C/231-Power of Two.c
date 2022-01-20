// Given an integer n, return true if it is a power of two. Otherwise, return false.

// An integer n is a power of two, if there exists an integer x such that n == 2x.

 

// Example 1:

// Input: n = 1
// Output: true
// Explanation: 20 = 1
// Example 2:

// Input: n = 16
// Output: true
// Explanation: 24 = 16
// Example 3:

// Input: n = 3
// Output: false
 

// Constraints:

// -2^31 <= n <= 2^31 - 1
 

// Follow up: Could you solve it without loops/recursion?



bool isPowerOfTwo(int n){
    bool flag = false;
    while (n > 0) {
        if (n & 1) {
            if (flag) {
                return false;
            } else {
                flag = true;
            }
        }
    }
    return flag;
}

bool isPowerOfTwo(int n){
    return n > 0 && (1 << 30) % n == 0; 
}

bool isPowerOfTwo(int n){
    return n > 0 && (n & (n - 1)) == 0;  
}

bool isPowerOfTwo(int n){
    return n > 0 && (n & -n) == n;
}