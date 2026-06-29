/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
 *
 * You are given a string s and an integer k. You can choose any character of
 * the string and change it to any other uppercase English character. You can
 * perform this operation at most k times.
 *
 * Return the length of the longest substring containing the same letter you
 * can get after performing the above operations.
 *
 * Example 1:
 * Input: s = "ABAB", k = 2
 * Output: 4
 * Explanation: Replace the two 'A's with two 'B's or vice versa.
 *
 * Example 2:
 * Input: s = "AABABBA", k = 1
 * Output: 4
 * Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating character, which is 4.
 * There may exists other ways to achieve this answer length.
 *
 * Constraints:
 * - 1 <= s.length <= 10^5
 * - s consists of only uppercase English letters.
 * - 0 <= k <= s.length
 */

#include <string>
#include <vector>
#include <map>
using namespace std;

int characterReplacement_vector(string s, int k);

// @lc code=start
class Solution
{
public:
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
};
// @lc code=end

// Non-LeetCode wrapper for harness
int characterReplacement(string s, int k) {
    Solution sol;
    return sol.characterReplacement(std::move(s), k);
}


