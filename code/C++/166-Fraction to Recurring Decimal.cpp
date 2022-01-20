// Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

// If the fractional part is repeating, enclose the repeating part in parentheses.

// If multiple answers are possible, return any of them.

// It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

 

// Example 1:

// Input: numerator = 1, denominator = 2
// Output: "0.5"
// Example 2:

// Input: numerator = 2, denominator = 1
// Output: "2"
// Example 3:

// Input: numerator = 4, denominator = 333
// Output: "0.(012)"
 

// Constraints:

// -2^31 <= numerator, denominator <= 2^31 - 1
// denominator != 0

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        long long num = numerator, den = denominator;
        string res;
        long long bit = num * den;
        num = abs(num);
        den = abs(den);
        if (bit == 0) {
            return "0";
        } else if (bit < 0) {
            res += "-";
        }
        // bit 是用来判断正负和0的
        
        long long pre = num / den;
        res += to_string(pre);
        // 整数部分

        num = num - (num / den) * den;
        if (num == 0) {
            return res;
        }
        res += ".";
        // 以下开始计算小数部分

        int idx = res.size();
        unordered_map<int, int> pos;
        while (num && (pos.find(num) == pos.end())) {
            pos[num] = idx ++;
            num *= 10;
            res += char('0' + num / den);
            num = num - (num / den) * den;
        }
        if (num != 0) {
            res = res.substr(0, pos[num]) + '(' + res.substr(pos[num]) + ')';
        }
        return res;
    }
};