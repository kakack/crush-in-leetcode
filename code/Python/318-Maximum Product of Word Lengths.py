# Given a string array words, return the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. If no such two words exist, return 0.

 

# Example 1:

# Input: words = ["abcw","baz","foo","bar","xtfn","abcdef"]
# Output: 16
# Explanation: The two words can be "abcw", "xtfn".
# Example 2:

# Input: words = ["a","ab","abc","d","cd","bcd","abcd"]
# Output: 4
# Explanation: The two words can be "ab", "cd".
# Example 3:

# Input: words = ["a","aa","aaa","aaaa"]
# Output: 0
# Explanation: No such pair of words.
 

# Constraints:

# 2 <= words.length <= 1000
# 1 <= words[i].length <= 1000
# words[i] consists only of lowercase English letters.

# 本题主要问题是判断两个字符串是否含相同字符，由于字符串只含有小写字符，总共 26 位，因此可以用一个 32 位的整数来存储每个字符是否出现过。

class Solution:
    def maxProduct(self, words: List[str]) -> int:
        masks = defaultdict(int)
        for word in words:
            mask = reduce(lambda a, b: a | (1 << (ord(b) - ord('a'))), word, 0)
            masks[mask] = max(masks[mask], len(word))
        return max((masks[x] * masks[y] for x, y in product(masks, repeat=2) if x & y == 0), default=0)

        