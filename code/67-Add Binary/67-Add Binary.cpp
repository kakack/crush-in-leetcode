/*
LeetCode 67 - Add Binary

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
/*
Add Binary

Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100".

这个还是挺简单的，技巧在于reverse那一步
*/

class Solution {
public:
    string addBinary(string a, string b) {
           const int len = a.size()>b.size()?a.size():b.size();
	       string result;
	       int carry=0;

	       reverse(a.begin(),a.end());
	       reverse(b.begin(),b.end());

	       for(int i=0;i<len;i++){
	               int ai = i<a.size()?a[i]-'0':0;
	               int bi = i<b.size()?b[i]-'0':0;
	               int val = (ai + bi + carry)%2;

		           result.insert(result.begin(),val+'0');
		           carry = (ai+bi+carry)/2;
		       }


		   if(carry==1)
		     result.insert(result.begin(), '1');

	       return result;


    }
};
