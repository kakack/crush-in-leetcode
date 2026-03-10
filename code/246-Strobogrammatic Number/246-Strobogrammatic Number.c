/*
LeetCode 246 - Strobogrammatic Number

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
*/
// Given a string num which represents an integer, return true if num is a strobogrammatic number.

// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).

//

// Example 1:

// Input: num = "69"
// Output: true
// Example 2:

// Input: num = "88"
// Output: true
// Example 3:

// Input: num = "962"
// Output: false
//

// Constraints:

// 1 <= num.length <= 50
// num consists of only digits.
// num does not contain any leading zeros except for zero itself.

bool isStrobogrammatic(char * num){
    int i = 0, j = strlen(num) - 1;
    while (i <= j) {
        if (num[i] == num[j]) {
            if (num[i] == '0' || num[i] == '1' || num[i] == '8') {
                i ++;
                j --;
            } else {
                return false;
            }
        } else {
            if ((num[i] == '6' && num[j] == '9') || (num[i] == '9' && num[j] == '6')) {
                i ++;
                j --;
            } else {
                return false;
            }
        }
    }
    return true;
}
