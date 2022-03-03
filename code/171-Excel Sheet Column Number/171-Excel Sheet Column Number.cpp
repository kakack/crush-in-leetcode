//
// Created by c00453140 on 2021/7/30.
//

/*
 * Given a string columnTitle that represents the column title as appear in an Excel sheet, return its corresponding column number.

For example:

A -> 1
B -> 2
C -> 3
...
Z -> 26
AA -> 27
AB -> 28
...
 

Example 1:

Input: columnTitle = "A"
Output: 1
Example 2:

Input: columnTitle = "AB"
Output: 28
Example 3:

Input: columnTitle = "ZY"
Output: 701
Example 4:

Input: columnTitle = "FXSHRXW"
Output: 2147483647
 

Constraints:

1 <= columnTitle.length <= 7
columnTitle consists only of uppercase English letters.
columnTitle is in the range ["A", "FXSHRXW"].

 * */

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n = columnTitle.size();
        long res = 0;
        for (int i = 0; i < n; i++) {
            res = 26 * res + columnTitle[i] - 'A' + 1;
        }
        return res;
    }
};

