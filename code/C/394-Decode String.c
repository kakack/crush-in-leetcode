// Given an encoded string, return its decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; there are no extra white spaces, square brackets are well-formed, etc.

// Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there will not be input like 3a or 2[4].

 

// Example 1:

// Input: s = "3[a]2[bc]"
// Output: "aaabcbc"
// Example 2:

// Input: s = "3[a2[c]]"
// Output: "accaccacc"
// Example 3:

// Input: s = "2[abc]3[cd]ef"
// Output: "abcabccdcdcdef"
 

// Constraints:

// 1 <= s.length <= 30
// s consists of lowercase English letters, digits, and square brackets '[]'.
// s is guaranteed to be a valid input.
// All the integers in s are in the range [1, 300].

#define L_MAX_SIZE 10000
#define N_MAX_SIZE 100
void reverse(char* region) {
    int len = strlen(region);
    for (int i = 0, j = len - 1; i < j; i++, j--) {
        char tmp;
        tmp = region[i];
        region[i] = region[j];
        region[j] = tmp;
    }
    return;
}

char * decodeString(char * s){
    int nTop = -1, lTop = -1;
    char lStack[L_MAX_SIZE] = "";
    int nStack[N_MAX_SIZE] = {0};
    int size = strlen(s);
    int numTmp = 0;
    for (int i = 0; i < size; i++) {
        if (s[i] == '[') {
            nStack[++nTop] = numTmp;
            numTmp = 0;
            lStack[++lTop] = s[i];
            continue;
        }
        if (s[i] >= '0' && s[i] <= '9') {
            numTmp = numTmp * 10 + s[i] - '0';
            continue;
        }
        if (s[i] != ']') {
            lStack[++lTop] = s[i];
            continue;
        }
        char tmpAlph[1000] = "";
        int k = 0;
        while (lTop != -1 && lStack[lTop] != '[') {
            tmpAlph[k++] = lStack[lTop--];
        }
        /* 将'['出栈 */
        lTop--;
        reverse(tmpAlph);
        int times = nStack[nTop--];
        for (int t = 0; t < times; t++) {
            for (int j = 0; j < k; j++) {
                lStack[++lTop] = tmpAlph[j];
            }
        }
    }
    char* ans = (char*)calloc(sizeof(char), L_MAX_SIZE);
    /* 注意不能直接strcpy，因为lStack可能不只是答案，因为lTop中间的值可能是++又--过了 */
    /* 因此，有效字符应为存储在lStack中，长度为lTop + 1的字符串 */
    memcpy(ans, lStack, sizeof(char) * (lTop + 1));
    return ans;
}
