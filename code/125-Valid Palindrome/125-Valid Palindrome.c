/*
LeetCode 125 - Valid Palindrome

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

// Given a string s, return true if it is a palindrome, or false otherwise.

//

// Example 1:

// Input: s = "A man, a plan, a canal: Panama"
// Output: true
// Explanation: "amanaplanacanalpanama" is a palindrome.
// Example 2:

// Input: s = "race a car"
// Output: false
// Explanation: "raceacar" is not a palindrome.
// Example 3:

// Input: s = " "
// Output: true
// Explanation: s is an empty string "" after removing non-alphanumeric characters.
// Since an empty string reads the same forward and backward, it is a palindrome.
//

// Constraints:

// 1 <= s.length <= 2 * 10^5
// s consists only of printable ASCII characters.

bool validLetter(char c) {
    int low = c - 'a';
    int high = c - 'A';
    int digit = c - '0';
    return (low >=0 && low <= 25) || (high >= 0 && high <= 25) || (digit >= 0 && digit <= 9);
}

bool sameLetter(char a, char b) {
    int lowa = a - 'a', lowb = b - 'a', higha = a - 'A', highb = b - 'A';
    if (a == b){
        return true;
    } else if (lowa >= 0 && lowa <= 25 && lowa == highb) {
        return true;
    } else if (higha >= 0 && higha <= 25 && higha == lowb) {
        return true;
    } else {
        return false;
    }

}

bool isPalindrome(char * s){
    int left = 0, right = strlen(s) - 1;
    while (left < right) {
        while (!validLetter(s[left]) && left < right) {
            left ++;
        }
        while (!validLetter(s[right]) && left < right) {
            right --;
        }
        if (!sameLetter(s[left], s[right])) {
            return false;
        } else {
            left ++;
            right --;
        }
    }
    return true;
}
