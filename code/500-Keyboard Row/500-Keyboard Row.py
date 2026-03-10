"""
LeetCode 500 - Keyboard Row

解题步骤（自动整理）
1. 先把题目目标拆成可操作的子任务（比较/统计/构造等）
2. 选择合适的数据结构并按一次遍历或分治步骤实现核心逻辑
3. 补齐边界条件（空输入、单元素、重复元素等）并返回结果
"""
# Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below.
# Example:
# Input: ["Hello", "Alaska", "Dad", "Peace"]
# Output: ["Alaska", "Dad"]

class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """

        def char_in_row(char):
            row = ['qwertyuiop', 'asdfghjkl', 'zxcvbnm']
            for i in range(3):
                if char in row[i]:
                    return i
        ans_, ans = [], []
        for word in words:
            index = -1
            for c in word:
                c = c.lower()
                if index < 0:
                    index = char_in_row(c)
                elif index != char_in_row(c):
                    ans_.append(word)
                    break
        for word_ in words:
            if word_ not in ans_:
                ans.append(word_)
        return ans

if __name__ == '__main__':
    s = Solution()
    input = ["Hello", "Alaska", "Dad", "Peace"]
    print(s.findWords(input))
