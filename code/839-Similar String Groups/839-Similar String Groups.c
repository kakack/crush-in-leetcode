/*
Two strings X and Y are similar if we can swap two letters (in different positions) of X, so that it equals Y. Also two strings X and Y are similar if they are equal.

For example, "tars" and "rats" are similar (swapping at positions 0 and 2), and "rats" and "arts" are similar, but "star" is not similar to "tars", "rats", or "arts".

Together, these form two connected groups by similarity: {"tars", "rats", "arts"} and {"star"}.  Notice that "tars" and "arts" are in the same group even though they are not similar.  Formally, each group is such that a word is in the group if and only if it is similar to at least one other word in the group.

We are given a list strs of strings where every string in strs is an anagram of every other string in strs. How many groups are there?



Example 1:

Input: strs = ["tars","rats","arts","star"]
Output: 2
Example 2:

Input: strs = ["omv","ovm"]
Output: 1


Constraints:

1 <= strs.length <= 100
1 <= strs[i].length <= 1000
sum(strs[i].length) <= 2 * 104
strs[i] consists of lowercase letters only.
All words in strs have the same length and are anagrams of each other.

*/

int find(int *f, int x) {
    return f[x] == x ? x : (f[x] = find(f, f[x]));
}

bool  check(char *a, char *b, int len) {
    int num = 0;
    for (int i = 0; i < len; i ++) {
        if (a[i] != b[i]) {
            num ++;
            if (num > 2) {
                return false;
            }
        }
    }
    return true;
}

int numSimilarGroups(char ** strs, int strsSize){
    int n = strsSize;
    int m = strlen(strs[0]);
    int f[n];
    for (int i = 0; i < n; i ++) {
        f[i] = i;
    }
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            int fi = find(f, i), fj = find(f, j);
            if (fi == fj) {
                continue;
            }
            if (check(strs[i], strs[j], m)) {
                f[fi] = fj;
            }
        }
    }
    int res = 0;
    for (int i = 0; i < n; i ++) {
        if (f[i] == i) {
            res ++;
        }
    }
    return res;
}