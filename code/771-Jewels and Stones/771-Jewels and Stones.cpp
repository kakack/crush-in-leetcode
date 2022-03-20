// You're given strings jewels representing the types of stones that are jewels, and stones representing the stones you have. Each character in stones is a type of stone you have. You want to know how many of the stones you have are also jewels.

// Letters are case sensitive, so "a" is considered a different type of stone from "A".

 

// Example 1:

// Input: jewels = "aA", stones = "aAAbbbb"
// Output: 3
// Example 2:

// Input: jewels = "z", stones = "ZZ"
// Output: 0
 

// Constraints:

// 1 <= jewels.length, stones.length <= 50
// jewels and stones consist of only English letters.
// All the characters of jewels are unique.

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> jews;
        int n = jewels.size(), m = stones.size();
        for (int i = 0; i < n; i ++) {
            jews.emplace(jewels[i]);
        }
        int res = 0;
        for (int i = 0; i < m; i ++) {
            if (jews.find(stones[i]) != jews.end()) {
                res ++;
            }
        }
        return res;
    }
};