"""
LeetCode 1647 - Minimum Deletions to Make Character Frequencies Unique

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# A string s is called good if there are no two different characters in s that have the same frequency.

# Given a string s, return the minimum number of characters you need to delete to make s good.

# The frequency of a character in a string is the number of times it appears in the string. For example, in the string "aab", the frequency of 'a' is 2, while the frequency of 'b' is 1.



# Example 1:

# Input: s = "aab"
# Output: 0
# Explanation: s is already good.
# Example 2:

# Input: s = "aaabbbcc"
# Output: 2
# Explanation: You can delete two 'b's resulting in the good string "aaabcc".
# Another way it to delete one 'b' and one 'c' resulting in the good string "aaabbc".
# Example 3:

# Input: s = "ceabaacb"
# Output: 2
# Explanation: You can delete both 'c's resulting in the good string "eabaab".
# Note that we only care about characters that are still in the string at the end (i.e. frequency of 0 is ignored).


# Constraints:

# 1 <= s.length <= 10^5
# s contains only lowercase English letters.

class Solution:
    def minDeletions(self, s: str) -> int:
        cnt = [0] * 26
        res = 0
        dct = list()
        for ch in s:
            cnt[ord(ch) - ord('a')] += 1
        for i in range(26):
            while cnt[i] > 0 and cnt[i] in dct:
                cnt[i] -= 1
                res += 1
            if cnt[i] > 0:
                dct.append(cnt[i])
        return res
