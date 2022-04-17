// Given a string paragraph and a string array of the banned words banned, return the most frequent word that is not banned. It is guaranteed there is at least one word that is not banned, and that the answer is unique.

// The words in paragraph are case-insensitive and the answer should be returned in lowercase.

 

// Example 1:

// Input: paragraph = "Bob hit a ball, the hit BALL flew far after it was hit.", banned = ["hit"]
// Output: "ball"
// Explanation: 
// "hit" occurs 3 times, but it is a banned word.
// "ball" occurs twice (and no other word does), so it is the most frequent non-banned word in the paragraph. 
// Note that words in the paragraph are not case sensitive,
// that punctuation is ignored (even if adjacent to words, such as "ball,"), 
// and that "hit" isn't the answer even though it occurs more because it is banned.
// Example 2:

// Input: paragraph = "a.", banned = []
// Output: "a"
 

// Constraints:

// 1 <= paragraph.length <= 1000
// paragraph consists of English letters, space ' ', or one of the symbols: "!?',;.".
// 0 <= banned.length <= 100
// 1 <= banned[i].length <= 10
// banned[i] consists of only lowercase English letters.

class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> bannedSet;
        for (auto &word: banned) {
            bannedSet.emplace(word);
        }
        int maxFreq = 0;
        unordered_map<string, int> freqs;
        string word;
        int length = paragraph.size();
        for (int i = 0; i <= length; i ++) {
            if (i < length && isalpha(paragraph[i])) {
                word.push_back(tolower(paragraph[i]));
            } else if (word.size() > 0) {
                if (!bannedSet.count(word)) {
                    freqs[word] ++;
                    maxFreq = max(maxFreq, freqs[word]);
                }
                word = "";
            }
        }
        string mostCommon = "";
        for (auto &[word, freq] : freqs) {
            if (freq == maxFreq) {
                mostCommon = word;
                break;
            }
        }
        return mostCommon;
    }
};