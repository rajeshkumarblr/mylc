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
