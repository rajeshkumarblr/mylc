/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "lc_test_utils.h"
using namespace std;

int characterReplacement_vector(string s, int k);

// @lc code=start
#ifndef LC_LOCAL_TEST
class Solution
{
public:
#endif
    int characterReplacement(string s, int k)
    {
        return characterReplacement_vector(s,k);
        //return characterReplacement_map(s,k);
    }

    int characterReplacement_vector(string s, int k)
    {
        vector<int> cnt(26, 0);
        int l = 0, best = 0, maxCount = 0;

        for (int r = 0; r < (int)s.size(); ++r)
        {
            int idx = s[r] - 'A';
            maxCount = max(maxCount, ++cnt[idx]);

            // enforce: window size - most frequent char count <= k
            while ((r - l + 1) - maxCount > k)
            {
                cnt[s[l] - 'A']--;
                l++;
            }

            best = max(best, r - l + 1);
        }
        return best;
    }

    int characterReplacement_map(string s, int k)
    {
        map<char, int> charFreq;
        int l = 0, r = 0, best = 0, maxCount = 0;

        for (const auto &ch : s)
        {
            charFreq[ch]++;
            maxCount = max(maxCount, charFreq[ch]);

            // enforce: window size - most frequent char count <= k
            if ((r - l + 1) - maxCount > k)
            {
                charFreq[s[l]]--;
                l++;
            }

            best = max(best, r - l + 1);
            r++;
        }
        return best;
    }
#ifndef LC_LOCAL_TEST
};
#endif
// @lc code=end


