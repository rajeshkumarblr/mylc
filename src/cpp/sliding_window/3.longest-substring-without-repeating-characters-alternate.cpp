/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 */

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) 
    {
        vector<int> charIndex(256,-1);
        int res = 0, l = 0, r = 0;
        for (unsigned char c: s) 
        {
            if ((charIndex[c] >= l)) 
            {
                l = charIndex[c] + 1;
            }
            charIndex[c] = r;
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }
};
// @lc code=end


     