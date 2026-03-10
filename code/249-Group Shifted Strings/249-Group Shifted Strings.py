"""
LeetCode 249 - Group Shifted Strings

解题步骤（自动整理）
1. 使用哈希表记录已遍历元素（或频次/索引）以支持 O(1) 查询
2. 遍历输入并在哈希表中查找所需互补/状态，命中时更新答案
3. 遍历结束后返回答案或默认值
"""
# We can shift a string by shifting each of its letters to its successive letter.

# For example, "abc" can be shifted to be "bcd".
# We can keep shifting the string to form a sequence.

# For example, we can keep shifting "abc" to form the sequence: "abc" -> "bcd" -> ... -> "xyz".
# Given an array of strings strings, group all strings[i] that belong to the same shifting sequence. You may return the answer in any order.

#

# Example 1:

# Input: strings = ["abc","bcd","acef","xyz","az","ba","a","z"]
# Output: [["acef"],["a","z"],["abc","bcd","xyz"],["az","ba"]]
# Example 2:

# Input: strings = ["a"]
# Output: [["a"]]
#

# Constraints:

# 1 <= strings.length <= 200
# 1 <= strings[i].length <= 50
# strings[i] consists of lowercase English letters.


class Solution:
    def groupStrings(self, strings: List[str]) -> List[List[str]]:
        def hashCounter(string):
            return tuple(((ord(string[i]) - ord(string[i-1])) % 26) for i in range(1 , len(string))) if len(string) > 1 else 0

        ans = defaultdict(list)
        for s in strings:
            ans[hashCounter(s)].append(s)
        return list(ans.values())
