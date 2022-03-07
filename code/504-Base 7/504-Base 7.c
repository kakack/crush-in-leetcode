Given an integer num, return a string of its base 7 representation.

 

// Example 1:

// Input: num = 100
// Output: "202"
// Example 2:

// Input: num = -7
// Output: "-10"
 

// Constraints:

// // -107 <= num <= 107



char * convertToBase7(int num){
    bool flag = true;
    if (num == 0) {
        return "0";
    } else if (num < 0) {
        flag = false;
        num = -num;
    }
    char* res = (char*)malloc(sizeof(char) * 32);
    int pos = 0;
    while (num > 0) {
        res[pos++] = num % 7 + '0';
        num /= 7;
    }
    if (!flag) {
        res[pos++] = '-';
    }
    for (int l = 0, r = pos - 1; l < r; l ++, r --) {
        char c = res[l];
        res[l] = res[r];
        res[r] = c;
    }
    res[pos] = '\0';
    return res;
}