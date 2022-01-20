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

int maxProduct(char ** words, int wordsSize){
    int* digits = malloc(sizeof(int) * wordsSize);
    for (int i = 0; i < wordsSize; i ++) {
        int digit = 0;
        for (int j = 0; j < strlen(words[i]); j ++) {
            digit |= (1 << (words[i][j] - 'a'));
        }
        digits[i] = digit;
    }
    int res = 0;
    for (int i = 0; i < wordsSize; i ++) {
        for (int j = i + 1; j < wordsSize; j ++) {
            if ((digits[i] & digits[j]) == 0) {
                res = fmax(res, strlen(words[i]) * strlen(words[j]));
            }
        }
    }
    return res;
}