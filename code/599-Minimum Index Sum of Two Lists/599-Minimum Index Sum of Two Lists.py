"""
LeetCode 599 - Minimum Index Sum of Two Lists

解题步骤（自动整理）
1. 使用哈希表记录已遍历元素（或频次/索引）以支持 O(1) 查询
2. 遍历输入并在哈希表中查找所需互补/状态，命中时更新答案
3. 遍历结束后返回答案或默认值
"""
# Suppose Andy and Doris want to choose a restaurant for dinner, and they both have a list of favorite restaurants represented by strings.

# You need to help them find out their common interest with the least list index sum. If there is a choice tie between answers, output all of them with no order requirement. You could assume there always exists an answer.



# Example 1:

# Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["Piatti","The Grill at Torrey Pines","Hungry Hunter Steakhouse","Shogun"]
# Output: ["Shogun"]
# Explanation: The only restaurant they both like is "Shogun".
# Example 2:

# Input: list1 = ["Shogun","Tapioca Express","Burger King","KFC"], list2 = ["KFC","Shogun","Burger King"]
# Output: ["Shogun"]
# Explanation: The restaurant they both like and have the least index sum is "Shogun" with index sum 1 (0+1).


# Constraints:

# 1 <= list1.length, list2.length <= 1000
# 1 <= list1[i].length, list2[i].length <= 30
# list1[i] and list2[i] consist of spaces ' ' and English letters.
# All the stings of list1 are unique.
# All the stings of list2 are unique.

class Solution:
    def findRestaurant(self, list1: List[str], list2: List[str]) -> List[str]:
        indexMap = defaultdict(int)
        for i in range(len(list1)):
            indexMap[list1[i]] = i
        res = list()
        minIdx = float("inf")
        for i in range(len(list2)):
            if list2[i] in indexMap.keys():
                idx = i + indexMap[list2[i]]
                if idx > minIdx:
                    continue
                elif idx < minIdx:
                    minIdx = idx
                    res = list()
                res.append(list2[i])
        return res
