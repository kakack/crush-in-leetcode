# There is a new alien language that uses the English alphabet. However, the order among the letters is unknown to you.

# You are given a list of strings words from the alien language's dictionary, where the strings in words are sorted lexicographically by the rules of this new language.

# Return a string of the unique letters in the new alien language sorted in lexicographically increasing order by the new language's rules. If there is no solution, return "". If there are multiple solutions, return any of them.

# A string s is lexicographically smaller than a string t if at the first letter where they differ, the letter in s comes before the letter in t in the alien language. If the first min(s.length, t.length) letters are the same, then s is smaller if and only if s.length < t.length.

#  

# Example 1:

# Input: words = ["wrt","wrf","er","ett","rftt"]
# Output: "wertf"
# Example 2:

# Input: words = ["z","x"]
# Output: "zx"
# Example 3:

# Input: words = ["z","x","z"]
# Output: ""
# Explanation: The order is invalid, so return "".
#  

# Constraints:

# 1 <= words.length <= 100
# 1 <= words[i].length <= 100
# words[i] consists of only lowercase English letters.

class Solution:
    def alienOrder(self, words: List[str]) -> str:
        g = {}
        for c in words[0]:
            g[c] = []
        for s, t in pairwise(words):
            for c in t:
                g.setdefault(c, [])
            for u, v in zip(s, t):
                if u != v:
                    g[u].append(v)
                    break
            else:
                if len(s) > len(t):
                    return ""

        VISITING, VISITED = 1, 2
        states = {}
        order = []
        def dfs(u: str) -> bool:
            states[u] = VISITING
            for v in g[u]:
                if v not in states:
                    if not dfs(v):
                        return False
                elif states[v] == VISITING:
                    return False
            order.append(u)
            states[u] = VISITED
            return True

        return ''.join(reversed(order)) if all(dfs(u) for u in g if u not in states) else ""
