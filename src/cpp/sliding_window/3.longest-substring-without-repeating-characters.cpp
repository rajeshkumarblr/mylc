/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 */

#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> last;
        int maxlen = 0, start = 0;
        for (int i = 0; i < (int)s.size(); ++i) {
            if (last.count(s[i]) && last[s[i]] >= start) {
                start = last[s[i]] + 1;
            }
            last[s[i]] = i;
            maxlen = max(maxlen, i - start + 1);
        }
        return maxlen;
    }
};
// @lc code=end

// Non-LeetCode wrapper for harness
int lengthOfLongestSubstring(string s) {
    Solution sol;
    return sol.lengthOfLongestSubstring(std::move(s));
}
