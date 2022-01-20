// Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.

 

// Example 1:

// Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
// Output: 16
// Explanation: The two words can be "abcw", "xtfn".
// Example 2:

// Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
// Output: 4
// Explanation: The two words can be "ab", "cd".
// Example 3:

// Input: words = ["a","aa","aaa","aaaa"]
// Output: 0
// Explanation: No such pair of words.
 

// Constraints:

// 2 <= words.length <= 1000
// 1 <= words[i].length <= 1000
// words[i] consists only of lowercase English letters.

// 本题主要问题是判断两个字符串是否含相同字符，由于字符串只含有小写字符，总共 26 位，因此可以用一个 32 位的整数来存储每个字符是否出现过。

class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> digits;
        int n = words.size();
        for (string word: words) {
            int digit = 0;
            for (int i = 0; i < word.size(); i ++) {
                digit |= (1 << (word[i] - 'a'));
            }
            digits.push_back(digit);
        }
        int res = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 1; j < n; j ++) {
                if ((digits[i] & digits[j]) == 0) {
                    res = max(res, words[i].size() * words[j].size());
                }
            }
        }
        return res;
    }
};