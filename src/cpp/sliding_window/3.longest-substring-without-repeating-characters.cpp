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
#ifndef LC_LOCAL_TEST
class Solution {
public:
#endif
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
#ifndef LC_LOCAL_TEST
};
#endif
// @lc code=end
