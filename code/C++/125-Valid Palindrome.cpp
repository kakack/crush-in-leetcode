
/*
Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

For example,
"A man, a plan, a canal: Panama" is a palindrome.
"race a car" is not a palindrome.

Note:
Have you consider that the string might be empty? This is a good question to ask during an interview.

For the purpose of this problem, we define empty string as valid palindrome.

分别从左向右和从右向左扫一遍字符串，遇到非字母的跳过，直到相遇为止

*/
class Solution {
public:
    bool isPalindrome(string s) {
        
        transform(s.begin(),s.end(),s.begin(),::tolower);//转成lowcase的
        
        int len=s.length();
        if(len==0)
          return true;
          
        auto left=s.begin(),right=prev(s.end());
          
        while(left<right){
            if(!isalnum(*left)) left++;
            else if(!isalnum(*right)) right--;
            else if(*left!=*right) return false;
            else {
                left++;
                right--;
            }
        }
        
        return true;
        
        
    }
};