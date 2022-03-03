// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in parentheses.

// If multiple answers are possible, return any of them.

// It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

 

// Example 1:

// Input: numerator = 1, denominator = 2
// Output: "0.5"
// Example 2:

// Input: numerator = 2, denominator = 1
// Output: "2"
// Example 3:

// Input: numerator = 4, denominator = 333
// Output: "0.(012)"
 

// Constraints:

// -2^31 <= numerator, denominator <= 2^31 - 1
// denominator != 0

struct  HashTable {
    int key;
    int val;
    UT_hash_handle hh;
};


char * fractionToDecimal(int numerator, int denominator){
    long long num = numerator, den = denominator;
    struct HashTable *hashTable = NULL;
    char* res = malloc(sizeof(char) * 100000);
    long long bit = num * den;
    num = fabs(num);
    den = fabs(den);
    int resIdx = 0;
    if (bit == 0) {
        return "0";
    } else if (bit < 0) {
        res[resIdx++] = '-';
    }
    long long pre = num / den;
    num = num % den;
    sprintf(res + resIdx, "%u", pre);
    resIdx = strlen(res);
    if (num != 0) {
        res[resIdx++] = '.';
    }
    while (num > 0) {
        struct HashTable *tmp;
        HASH_FIND_INT(hashTable, &num, tmp);
        if (tmp != NULL) {
            for (int i = resIdx; i > tmp->val; i--) {
                res[i] = res[i - 1];
            } 
            res[tmp->val] = '(';
            res[++resIdx] = ')';
            resIdx ++;
            break;
        } else {
            tmp = malloc(sizeof(struct HashTable));
            tmp->key = num;
            tmp->val = resIdx;
            HASH_ADD_INT(hashTable, key, tmp);
        }
        num *= 10;
        res[resIdx++] = num / den + '0';
        num = num % den;
    }
    res[resIdx] = '\0';
    return res;
}