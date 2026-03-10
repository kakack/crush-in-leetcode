/*
LeetCode 387 - First Unique Character in a String

解题步骤（自动整理）
1. 使用哈希表记录已遍历元素（或频次/索引）以支持 O(1) 查询
2. 遍历输入并在哈希表中查找所需互补/状态，命中时更新答案
3. 遍历结束后返回答案或默认值
*/
/*
Given a string, find the first non-repeating character in it and return its index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode"
return 2.
*/

#include "string"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<int, int> frequency;
        for(auto c: s){
            frequency[c] ++;
        }
        for (int i = 0; i < s.size(); i ++){
            if(frequency[s[i]] == 1){
                return i;
            }
        }
        return -1;
    }
};
