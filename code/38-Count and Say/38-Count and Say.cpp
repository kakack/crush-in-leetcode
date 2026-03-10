/*
LeetCode 38 - Count and Say

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/

/*Count and Say
The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.

*/
class Solution {
public:
   string getNext(const string &s){
       stringstream ss;

       for(auto i=s.begin();i!=s.end();){
           auto j =find_if(i,s.end(),bind1st(not_equal_to<char>(), *i));//巧妙使用STL，这两个方法怎么用的看笔记
           ss<<distance(i,j) <<*i;
           i=j;
       }
       return ss.str();
   }


    string countAndSay(int n) {
        string s("1");

        while(--n)
           s = getNext(s);

        return s;
    }
};
