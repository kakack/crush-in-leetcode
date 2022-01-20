// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

 

// Example 1:

// Input: s = "anagram", t = "nagaram"
// Output: true
// Example 2:

// Input: s = "rat", t = "car"
// Output: false
 

// Constraints:

// 1 <= s.length, t.length <= 5 * 10^4
// s and t consist of lowercase English letters.
 

// Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?


class Solution {
public:
    bool isAnagram(string s, string t) {
        int alphat[26] = {0};
        if (s.size() != t.size()) {
            return false;
        } else {
            for (int i = 0; i < s.size(); i ++) {
                alphat[s[i] - 'a'] ++;
                alphat[t[i] - 'a'] --;
            }
        }
        for (int i = 0; i < 26; i ++) {
            if (alphat[i] != 0) {
                return false;
            }
        }
        return true;
    }
};







// /*Anagrams
// Given an array of strings, return all groups of strings that are anagrams.

// Note: All inputs will be in lower-case.

// Anagrams回文构词法只是改变了单词顺序，没有改变数目，所以如果属于同一个Anagrams那么他们sort一下后的结果是一样的。
// */

// class Solution {
// public:
//     vector<string> anagrams(vector<string> &strs) {
//         map<string,int> anagrams;
//         vector<string> result;
//         string s;
        
//         for(int i=0;i<strs.size();i++){
//             s=strs[i];
            
//             sort(s.begin(),s.end());
            
//             if(anagrams.find(s)==anagrams.end())//没找到
//               anagrams[s]=i;
              
//             else{//已经有了
//             if(anagrams[s]>=0)
//               {
//                   result.push_back(strs[anagrams[s]]);
//                   anagrams[s]=-1;//这是为了防止重复一样的字串
//               }
//                 result.push_back(strs[i]);
//             }
            
            
//         }
        
//         return result;
        
//     }
// };