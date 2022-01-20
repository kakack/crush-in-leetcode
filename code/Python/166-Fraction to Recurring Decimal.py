# Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.

# If the fractional part is repeating, enclose the repeating part in parentheses.

# If multiple answers are possible, return any of them.

# It is guaranteed that the length of the answer string is less than 104 for all the given inputs.

 

# Example 1:

# Input: numerator = 1, denominator = 2
# Output: "0.5"
# Example 2:

# Input: numerator = 2, denominator = 1
# Output: "2"
# Example 3:

# Input: numerator = 4, denominator = 333
# Output: "0.(012)"
 

# Constraints:

# -2^31 <= numerator, denominator <= 2^31 - 1
# denominator != 0

class Solution:
    def fractionToDecimal(self, numerator: int, denominator: int) -> str:
        res = ""
        if numerator * denominator == 0:
            return "0"
        elif numerator * denominator < 0:
            res += "-"
        numerator, denominator = abs(numerator), abs(denominator)
        res += str(numerator // denominator)
        numerator = numerator - (numerator // denominator) * denominator
        if numerator == 0:
            return res
        else:
            res += "."
        idx = len(res)
        pos = {}
        while numerator and numerator not in pos.keys():
            pos[numerator] = idx
            idx += 1
            numerator *= 10
            res += str(numerator // denominator)
            numerator = numerator - (numerator // denominator) * denominator
        if numerator != 0:
            return res[:pos[numerator]] + "(" + res[pos[numerator]:] + ")"
        else:
            return res    