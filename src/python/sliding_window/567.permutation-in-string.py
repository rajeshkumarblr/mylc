"""
@lc app=leetcode id=567 lang=python3

[567] Permutation in String

https://leetcode.com/problems/permutation-in-string/description/

Given two strings s1 and s2, return true if s2 contains a permutation of
s1, or false otherwise.

In other words, return true if one of s1's permutations is the substring of
s2.

Example 1:
Input: s1 = "ab", s2 = "eidbaooo"
Output: true
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input: s1 = "ab", s2 = "eidboaoo"
Output: false

Constraints:
- 1 <= s1.length, s2.length <= 10^4
- s1 and s2 consist of lowercase English letters.
"""

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s1) > len(s2):
            return False
            
        s1_count = [0] * 26
        s2_count = [0] * 26
        
        for i in range(len(s1)):
            s1_count[ord(s1[i]) - ord('a')] += 1
            s2_count[ord(s2[i]) - ord('a')] += 1
            
        matches = 0
        for i in range(26):
            if s1_count[i] == s2_count[i]:
                matches += 1
                
        l = 0
        for r in range(len(s1), len(s2)):
            if matches == 26:
                return True
                
            index = ord(s2[r]) - ord('a')
            s2_count[index] += 1
            if s1_count[index] == s2_count[index]:
                matches += 1
            elif s1_count[index] + 1 == s2_count[index]:
                matches -= 1
                
            index = ord(s2[l]) - ord('a')
            s2_count[index] -= 1
            if s1_count[index] == s2_count[index]:
                matches += 1
            elif s1_count[index] - 1 == s2_count[index]:
                matches -= 1
            l += 1
            
        return matches == 26
