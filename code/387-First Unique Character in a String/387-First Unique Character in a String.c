/*
Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.
*/

int firstUniqChar(char * s){
    int n = strlen(s);
    int freq[26];
    memset(freq, 0, sizeof(int) * 26);
    for(int i = 0; i < n; i ++) {
        int idx = s[i] - 'a';
        freq[idx] ++;
    }
    for (int i = 0; i < n; i ++) {
        if (freq[s[i] - 'a'] == 1){
            return i;
        }
    }
    return -1;
}