/*
Given an integer n, return true if it is a power of four. Otherwise, return false.

An integer n is a power of four, if there exists an integer x such that n == 4x.



Example 1:

Input: n = 16
Output: true
Example 2:

Input: n = 5
Output: false
Example 3:

Input: n = 1
Output: true


Constraints:

-231 <= n <= 231 - 1
*/

#include<cmath>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        return n < 1 ? false : (log(n) / log(4)) == int((log(n) / log(4)));
    }

    bool isPowerOfFour(int n) {
        if (n <= 0) {
            return false;
        }
        while ((n & 3) == 0) {
            n >>= 2;
        }
        return n == 1;
    }
};