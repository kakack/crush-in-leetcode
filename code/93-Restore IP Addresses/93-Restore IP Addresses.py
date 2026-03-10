# -*- coding: utf-8 -*
"""
LeetCode 93 - Restore IP Addresses

解题步骤（自动整理）
1. 用 DFS/回溯枚举所有可能选择，并维护当前路径/状态
2. 在递归过程中进行剪枝（如边界、重复、提前失败条件）
3. 到达终止条件时收集结果或返回，并回溯撤销选择
"""
r"""
@author: Kaka Chen
@license: (C) Copyright Personal Uncommercial Limited.
@contact: kakachen1990@gmail.com
@file: 93-Restore IP Addresses.py
@time: 2020/8/9 2:34 下午
@desc:
Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address consists of exactly four integers (each integer is between 0 and 255) separated by single points.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
"""


class Solution(object):
    def restoreIpAddresses(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        seg_count = 4
        ans = []
        segments = [0] * seg_count

        def dfs(segId, segStart):
            if segId == seg_count:
                if segStart == len(s):
                    ipAddr = '.'.join(str(seg) for seg in segments)
                    ans.append(ipAddr)
                return
            if segStart == len(s):
                return
            if s[segStart] == '0':
                segments[segId] = 0
                dfs(segId + 1, segStart + 1)
            addr = 0
            for segEnd in range(segStart, len(s)):
                addr = addr * 10 + (ord(s[segEnd]) - ord('0'))
                if 0 < addr <= 0xFF:
                    segments[segId] = addr
                    dfs(segId + 1, segEnd + 1)
                else:
                    break

        dfs(0, 0)
        return ans
