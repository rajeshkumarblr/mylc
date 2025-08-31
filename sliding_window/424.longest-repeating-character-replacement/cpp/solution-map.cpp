/*
 * @lc app=leetcode id=424 lang=cpp
 *
 * [424] Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
 *
 * algorithms
 * Medium (57.78%)
 * Likes:    12150
 * Dislikes: 680
 * Total Accepted:    1.2M
 * Total Submissions: 2.1M
 * Testcase Example:  '"ABAB"\n2'
 *
 * You are given a string s and an integer k. You can choose any character of
 * the string and change it to any other uppercase English character. You can
 * perform this operation at most k times.
 *
 * Return the length of the longest substring containing the same letter you
 * can get after performing the above operations.
 *
 *
 * Example 1:
 *
 *
 * Input: s = "ABAB", k = 2
 * Output: 4
 * Explanation: Replace the two 'A's with two 'B's or vice versa.
 *
 *
 * Example 2:
 *
 *
 * Input: s = "AABABBA", k = 1
 * Output: 4
 * Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating letters, which is 4.
 * There may exists other ways to achieve this answer too.
 *
 *
 * Constraints:
 *
 *
 * 1 <= s.length <= 10^5
 * s consists of only uppercase English letters.
 * 0 <= k <= s.length
 *
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "lc_test_utils.h"
using namespace std;

// @lc code=start
class Solution
{
public:
    int characterReplacement(string s, int k)
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

int main() {
    Solution sol;
    vector<pair<pair<string, int>, int>> tests = {
        {{"ABAB", 2}, 4},    // Example 1
        {{"AABABBA", 1}, 4}, // Example 2
        {{"AAAA", 2}, 4},    // All same
        {{"ABCDE", 1}, 2},   // Only one change allowed
        {{"A", 0}, 1}        // Single char
    };
    bool all_passed = true;
    for (const auto& [input, expected] : tests) {
        const string& s = input.first;
        int k = input.second;
        int result = sol.characterReplacement(s, k);
        // Compose input string for print_test_result
        std::ostringstream oss;
        oss << "(\"" << s << "\", k=" << k << ")";
        all_passed &= print_test_result(oss.str(), result, expected);
    }
    cout << "\nFinal Result: " << (all_passed ? "PASS" :  "FAIL") << endl;
    return all_passed ? 0 : 1;
}