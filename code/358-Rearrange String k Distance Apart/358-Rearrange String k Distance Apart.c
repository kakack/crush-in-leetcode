// Given a string s and an integer k, rearrange s such that the same characters are at least distance k from each other. If it is not possible to rearrange the string, return an empty string "".

//  

// Example 1:

// Input: s = "aabbcc", k = 3
// Output: "abcabc"
// Explanation: The same letters are at least a distance of 3 from each other.
// Example 2:

// Input: s = "aaabc", k = 3
// Output: ""
// Explanation: It is not possible to rearrange the string.
// Example 3:

// Input: s = "aaadbbcc", k = 2
// Output: "abacabcd"
// Explanation: The same letters are at least a distance of 2 from each other.
//  

// Constraints:

// 1 <= s.length <= 3 * 10^5
// s consists of only lowercase English letters.
// 0 <= k <= s.length

#define MAX(a, b) ((a) > (b)) ? (a) : (b)

typedef struct letterCnt {
    int letterVal;
    int letterCnt;
    int prePos;
}LETTER_CNT;

char findNextChar(LETTER_CNT *letterCnt, int curPos, int k)
{
    char nextChar = 0;
    int i = 0;
    for (; i < 27; i++) {
        if (letterCnt[i].letterCnt == 0) {
            continue;
        }

        if (letterCnt[i].prePos == -1  ||  (curPos - letterCnt[i].prePos) >= k) {
            letterCnt[i].prePos = curPos;
            letterCnt[i].letterCnt -= 1;
            nextChar =  letterCnt[i].letterVal;
            break;
        }
    }

    return nextChar;
}
int compareLetterCnt(const void *elm1, const void *elm2) {
    return ((LETTER_CNT *)elm2)->letterCnt - ((LETTER_CNT *)elm1)->letterCnt;
}

char * rearrangeString(char * s, int k)
{
    LETTER_CNT letterCnt[27] = { 0 };
    int letterPrePos[27] = { 0 };
    int maxDupLetter = 0;

    if (s == NULL) {
        return "";
    } 

    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        letterCnt[s[i] - 'a'].letterVal = s[i];
        letterCnt[s[i] - 'a'].letterCnt += 1;
        letterCnt[s[i] - 'a'].prePos = -1;
        maxDupLetter = MAX(maxDupLetter, letterCnt[s[i] - 'a'].letterCnt);
    }

    if ((maxDupLetter - 1) * k + 1 > len) {
        return "";
    }

    qsort(letterCnt, 27, sizeof(LETTER_CNT),  compareLetterCnt);

    char *pNewStr = (char *)malloc(len + 1);
    memset(pNewStr, 0, len + 1);
    int i  = 0;
    for (i = 0; i < len; i++) {
        char c  =  findNextChar(letterCnt, i, k);
        qsort(letterCnt, 27, sizeof(LETTER_CNT),  compareLetterCnt); // 取完重新排序一下 保证优先取最多的字符
        if (c == 0) {
            break;
        }
        pNewStr[i] = c;
    }

    if (i != len) {
        free(pNewStr);
        return "";
    }
    return pNewStr;
}

