// We define the string s to be the infinite wraparound string of "abcdefghijklmnopqrstuvwxyz", so s will look like this:

// "...zabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcd....".
// Given a string p, return the number of unique non-empty substrings of p are present in s.

 

// Example 1:

// Input: p = "a"
// Output: 1
// Explanation: Only the substring "a" of p is in s.
// Example 2:

// Input: p = "cac"
// Output: 2
// Explanation: There are two substrings ("a", "c") of p in s.
// Example 3:

// Input: p = "zab"
// Output: 6
// Explanation: There are six substrings ("z", "a", "b", "za", "ab", and "zab") of p in s.
 

// Constraints:

// 1 <= p.length <= 10^5
// p consists of lowercase English letters.

#define MAX(a, b) ((a) > (b) ? (a) : (b)) 

int findSubstringInWraproundString(char * p){
    int dp[26];
    int n = strlen(p);
    memset(dp, 0, sizeof(dp));
    int k = 0;
    for (int i = 0; i < n; i ++) {
        if (i && (p[i] - p[i - 1] + 26) % 26 == 1) {
            k ++;
        } else {
            k = 1;
        }
        dp[p[i] - 'a'] = MAX(dp[p[i] - 'a'], k);
    }
    int res = 0;
    for (int i = 0; i < 26; i ++) {
        res += dp[i];
    }
    return res;
}