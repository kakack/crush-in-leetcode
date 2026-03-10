/*
LeetCode 9 - Palindrome Number

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/

//Palindrome Number
//Determine whether an integer is a palindrome. Do this without extra space.
//转换成string之后好做一点


class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
          return false;
        string tmp = toString(x);
        return isPalindrome(tmp);
    }

    string toString(int x){
        string res;
        while(x>0){
            res.insert(res.begin(), '0'+x%10);
            x=x/10;
        }
        return res;
    }

    bool isPalindrome(string x){
        int i=0, j=x.size()-1;
        while(i<=j){
            if(x[i]!=x[j])
              return false;
            else{
                i++;
                j--;
            }
        }
        return true;
    }
};
