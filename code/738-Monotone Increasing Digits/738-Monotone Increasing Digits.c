// An integer has monotone increasing digits if and only if each pair of adjacent digits x and y satisfy x <= y.

// Given an integer n, return the largest number that is less than or equal to n with monotone increasing digits.

 

// Example 1:

// Input: n = 10
// Output: 9
// Example 2:

// Input: n = 1234
// Output: 1234
// Example 3:

// Input: n = 332
// Output: 299
 

// Constraints:

// 0 <= n <= 10^9

void itoa(int num, char* str, int* strSize) {
    *strSize = 0;
    while (num > 0) {
        str[(*strSize) ++] = num % 10 +'0';
        num /= 10;
    }
    for (int i = 0; i < (*strSize) / 2; i ++) {
        int tmp = str[i];
        str[i] = str[(*strSize) - i - 1];
        str[(*strSize) - i - 1] = tmp;
    }
}

int monotoneIncreasingDigits(int n) {
    int strNSize;
    char strN[11];
    itoa(n, strN, &strNSize);

    int i = 1;
    while (i < strNSize && strN[i - 1] <= strN[i]) {
        i ++;
    }
    if (i < strNSize) {
        while (i > 0 && strN[i - 1] > strN[i]) {
            strN[i - 1] --;
            i --;
        }
        for (i += 1; i < strNSize; i ++) {
            strN[i] = '9';
        }
    }
    return atoi(strN);
}