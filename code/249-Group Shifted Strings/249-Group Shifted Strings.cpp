/*
LeetCode 249 - Group Shifted Strings

解题步骤（自动整理）
1. 使用哈希表记录已遍历元素（或频次/索引）以支持 O(1) 查询
2. 遍历输入并在哈希表中查找所需互补/状态，命中时更新答案
3. 遍历结束后返回答案或默认值
*/
// We can shift a string by shifting each of its letters to its successive letter.

// For example, "abc" can be shifted to be "bcd".
// We can keep shifting the string to form a sequence.

// For example, we can keep shifting "abc" to form the sequence: "abc" -> "bcd" -> ... -> "xyz".
// Given an array of strings strings, group all strings[i] that belong to the same shifting sequence. You may return the answer in any order.

//

// Example 1:

// Input: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]
// Output: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]
// Example 2:

// Input: strings = ["a"]
// Output: [["a"]]
//

// Constraints:

// 1 <= strings.length <= 200
// 1 <= strings[i].length <= 50
// strings[i] consists of lowercase English letters.

class Solution {
private:
    string processStr(string str) {
        int n = str.size();
        string res = str;
        int diff = str[0] - 'a';
        for (int i = 0; i < n; i ++) {
            res[i] = 'a' + (res[i] -'a' + 26 - diff) % 26;
        }
        return res;
    }

public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string, int> strMap;
        vector<vector<string>> res;
        int idx = 0;
        for (string str: strings) {
            string key = processStr(str);
            if (strMap.find(key) == strMap.end()) {
                res.push_back(vector<string>{str});
                strMap[key] = idx ++;
            } else {
                int curIdx = strMap[key];
                res[curIdx].push_back(str);
            }
        }
        return res;
    }
};
