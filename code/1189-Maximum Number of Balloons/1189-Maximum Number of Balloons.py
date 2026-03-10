"""
LeetCode 1189 - Maximum Number of Balloons

解题步骤（自动整理）
1. 使用哈希表记录已遍历元素（或频次/索引）以支持 O(1) 查询
2. 遍历输入并在哈希表中查找所需互补/状态，命中时更新答案
3. 遍历结束后返回答案或默认值
"""
# Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.
#
# You can use each character in text at most once. Return the maximum number of instances that can be formed.
#
# Example 1:
# Input: text = "nlaebolko"
# Output: 1
#
# Example 2:
# Input: text = "loonbalxballpoon"
# Output: 2
#
# Example 3:
# Input: text = "leetcode"
# Output: 0
#
#
# Constraints:
# - 1 <= text.length <= 10^4
# - text consists of lower case English letters only.

class Solution(object):
    def maxNumberOfBalloons(self, text):
        """
        :type text: str
        :rtype: int
        """
        hashMap = {'b': 0, 'a': 0, 'l': 0, 'o': 0, 'n': 0}
        balloon = ['b', 'a', 'l', 'o', 'n']
        for item in text:
            if item in balloon:
                hashMap[item] += 1
        return min(hashMap['b'], hashMap['a'], hashMap['n'], hashMap['o'] / 2, hashMap['l'] / 2)
