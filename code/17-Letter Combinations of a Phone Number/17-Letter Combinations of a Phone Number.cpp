/*
LeetCode 17 - Letter Combinations of a Phone Number

解题步骤（自动整理）
1. 用 DFS/回溯枚举所有可能选择，并维护当前路径/状态
2. 在递归过程中进行剪枝（如边界、重复、提前失败条件）
3. 到达终止条件时收集结果或返回，并回溯撤销选择
*/
/*Letter Combinations of a Phone Number

My Submissions Question Solution
Given a digit string, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below.



Input:Digit string "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
*/

class Solution {
public:

    const vector<string> keyword {"","","abc","def","ghi","jkl","mno", "pqrs","tuv","wxyz"};

    void dfs(string &digits, size_t cur, string path, vector<string> &result){

        if(cur == digits.size()){
            result.push_back(path);
            return ;
        }

        for(char c: keyword[digits[cur] - '0'])
           dfs(digits, cur + 1, path + c, result);
    }

    vector<string> letterCombinations(string digits) {

        vector<string> result;

        if(digits.size() == 0)
          return result;

        dfs(digits, 0, "", result);

        return result;

    }


};
