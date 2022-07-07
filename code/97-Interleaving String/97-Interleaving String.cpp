// Given strings s1, s2, and s3, find whether s3 is formed by an interleaving of s1 and s2.

// An interleaving of two strings s and t is a configuration where they are divided into non-empty substrings such that:

// s = s1 + s2 + ... + sn
// t = t1 + t2 + ... + tm
// |n - m| <= 1
// The interleaving is s1 + t1 + s2 + t2 + s3 + t3 + ... or t1 + s1 + t2 + s2 + t3 + s3 + ...
// Note: a + b is the concatenation of strings a and b.

 

// Example 1:


// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
// Example 2:

// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false
// Example 3:

// Input: s1 = "", s2 = "", s3 = ""
// Output: true
 

// Constraints:

// 0 <= s1.length, s2.length <= 100
// 0 <= s3.length <= 200
// s1, s2, and s3 consist of lowercase English letters.
 

// Follow up: Could you solve it using only O(s2.length) additional memory space?

// class Solution {
// public:
//     bool isInterleave(string s1, string s2, string s3) {
//         int n1 = s1.size(), n2 = s2.size(), n3 = s3.size();
//         if (n1 + n2 != n3) {
//             return false;
//         }
//         vector<vector<bool>> boolean(n2 + 1, vector<bool>(n1 + 1, false));
//         boolean[0][0] = true;
//         for (int i = 0; i <= n1; i ++) {
//             for (int j = 0; j <= n2; j ++) {
//                 int p = i + j - 1;
//                 if (i > 0) {
//                     boolean[i][j] = boolean[i][j] || (boolean[i - 1][j] && s1[i - 1] == s3[p]);
//                 }
//                 if (j > 0) {
//                     boolean[i][j] = boolean[i][j] || (boolean[i][j - 1] && s2[j - 1] == s3[p]);
//                 }
//             }
//         }
//         return boolean[n1][n2];
//     }
// };


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        auto f = vector <int> (s2.size() + 1, false);

        int n = s1.size(), m = s2.size(), t = s3.size();

        if (n + m != t) {
            return false;
        }

        f[0] = true;
        for (int i = 0; i <= n; ++i) {
            for (int j = 0; j <= m; ++j) {
                int p = i + j - 1;
                if (i > 0) {
                    f[j] &= (s1[i - 1] == s3[p]);
                }
                if (j > 0) {
                    f[j] |= (f[j - 1] && s2[j - 1] == s3[p]);
                }
            }
        }

        return f[m];
    }
};
