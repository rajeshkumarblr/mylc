"""
@lc app=leetcode id=438 lang=python3

[438] Find All Anagrams in a String

https://leetcode.com/problems/find-all-anagrams-in-a-string/description/

Given two strings s and p, return an array of all the start indices of p's
anagrams in s. You may return the answer in any order.

An Anagram is a word or phrase formed by rearranging the letters of a
different word or phrase, typically using all the original letters exactly
once.

Example 1:
Input: s = "cbaebabacd", p = "abc"
Output: [0,6]
Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".

Example 2:
Input: s = "abab", p = "ab"
Output: [0,1,2]
Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".

Constraints:
- 1 <= s.length, p.length <= 3 * 10^4
- s and p consist of lowercase English letters.
"""

from typing import List

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if len(p) > len(s):
            return []
            
        p_count = {}
        s_count = {}
        for char in p:
            p_count[char] = p_count.get(char, 0) + 1
            
        res = []
        l = 0
        for r in range(len(s)):
            s_count[s[r]] = s_count.get(s[r], 0) + 1
            
            if r - l + 1 > len(p):
                s_count[s[l]] -= 1
                if s_count[s[l]] == 0:
                    del s_count[s[l]]
                l += 1
            
            if s_count == p_count:
                res.append(l)
                
        return res
