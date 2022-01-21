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

class Solution {
public:
    string reverseWords(string s) {
        int wordStart = 0, wordlen = 0;;
        int n = s.size();
        vector<string> wordCache;
        while (wordStart + wordlen < n) {
            while (s[wordStart] == ' ') {
                wordStart ++;
            }
            while (s[wordStart + wordlen] != ' ' && wordStart + wordlen < n) {
                wordlen ++;
            }
            if (wordStart < n){
                wordCache.insert(wordCache.begin(), s.substr(wordStart, wordlen));
            }
            wordStart += wordlen;
            wordlen = 0;
        }
        string res = "";
        for (string word : wordCache) {
            res += word + ' ';
        }
        if (wordCache.size() == 0) {
            return res;
        } else {
            return res.substr(0, res.size() - 1);
        }
    }
};


// 官方解答这个不错，直接在原字符串上操作
class Solution {
public:
    string reverseWords(string s) {
        // 反转整个字符串
        reverse(s.begin(), s.end());

        int n = s.size();
        int idx = 0;
        for (int start = 0; start < n; ++start) {
            if (s[start] != ' ') {
                // 填一个空白字符然后将idx移动到下一个单词的开头位置
                if (idx != 0) s[idx++] = ' ';

                // 循环遍历至单词的末尾
                int end = start;
                while (end < n && s[end] != ' ') s[idx++] = s[end++];

                // 反转整个单词
                reverse(s.begin() + idx - (end - start), s.begin() + idx);

                // 更新start，去找下一个单词
                start = end;
            }
        }
        s.erase(s.begin() + idx, s.end());
        return s;
    }
};
