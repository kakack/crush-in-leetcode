/*
LeetCode 66 - Plus One

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/

/*
Plus One

Given a non-negative number represented as an array of digits, plus one to the number.

The digits are stored such that the most significant digit is at the head of the list.
*/
class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
       	int n=digits.size()-1;

			digits[n]+=1;

			while(digits[n]>=10&&n>0){
				digits[n]=digits[n]%10;
				  digits[n-1]+=1;
				  n--;
			}

			if(digits[0]>=10){
				digits[0]=digits[0]%10;
				digits.insert(digits.begin(),1);

			}
        return digits;

    }
};
