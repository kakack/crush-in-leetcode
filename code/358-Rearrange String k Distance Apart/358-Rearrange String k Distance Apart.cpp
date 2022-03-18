// Given a string s and an integer k, rearrange s such that the same characters are at least distance k from each other. If it is not possible to rearrange the string, return an empty string "".

//  

// Example 1:

// Input: s = "aabbcc", k = 3
// Output: "abcabc"
// Explanation: The same letters are at least a distance of 3 from each other.
// Example 2:

// Input: s = "aaabc", k = 3
// Output: ""
// Explanation: It is not possible to rearrange the string.
// Example 3:

// Input: s = "aaadbbcc", k = 2
// Output: "abacabcd"
// Explanation: The same letters are at least a distance of 2 from each other.
//  

// Constraints:

// 1 <= s.length <= 3 * 10^5
// s consists of only lowercase English letters.
// 0 <= k <= s.length

class Solution {
public:
    string rearrangeString(string s, int k) {
        if (k == 0) return s;
        priority_queue<pair<int, char>> pq;
        unordered_map<char, int> mp;
        queue<pair<int, char>> q;
        string ret;
        for (char c : s)  ++mp[c];
        for (auto [c, i] : mp) pq.emplace(i, c);
        while (!pq.empty()) {
            auto& [i, c] = pq.top();
            ret += c;
            q.emplace(i - 1, c);
            pq.pop();
            if (q.size() == k) { // 队列长度为 k 说明重复元素相距达到了 k， 可以出队
                if (q.front().first > 0) pq.emplace(q.front().first, q.front().second);
                q.pop();
            }
        }
        return ret.size() < s.size() ? "" : ret;
    }
};
