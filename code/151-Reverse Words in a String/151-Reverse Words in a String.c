// Given an input string s, reverse the order of the words.

// A word is defined as a sequence of non-space characters. The words in s will be separated by at least one space.

// Return a string of the words in reverse order concatenated by a single space.

// Note that s may contain leading or trailing spaces or multiple spaces between two words. The returned string should only have a single space separating the words. Do not include any extra spaces.

 

// Example 1:

// Input: s = "the sky is blue"
// Output: "blue is sky the"
// Example 2:

// Input: s = "  hello world  "
// Output: "world hello"
// Explanation: Your reversed string should not contain leading or trailing spaces.
// Example 3:

// Input: s = "a good   example"
// Output: "example good a"
// Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.
 

// Constraints:

// 1 <= s.length <= 10^4
// s contains English letters (upper-case and lower-case), digits, and spaces ' '.
// There is at least one word in s.

void reverse(char* s, int i, int j) {
    j --;
    while (i < j) {
        char tmp = s[i];
        s[i ++] = s[j];
        s[j--] = tmp;
    }
}

char * reverseWords(char * s){
    int n = strlen(s);
    reverse(s, 0, n);
    int idx = 0;
    for (int start = 0; start < n; start ++) {
        if (s[start] != ' ') {
            if (idx != 0) {
                s[idx++] = ' ';
            }
            int end = start;
            while (end < n && s[end] != ' ') {
                s[idx++] = s[end++];
            }
            reverse(s, idx - (end - start), idx);
            start = end;
        }
    }
    s[idx] = '\0';
    return s;
}