/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 */

#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    size_t i = 0;
    int l = 0;
    int maxlen = 0;
    unordered_map<char, int> charind;
    while (i < s.size()) {
      char ch = s[i];
      if (charind.count(ch) && charind[ch] >= l) {
        l = charind[ch] + 1;
      }
      charind[ch] = i;
      int wind = i - l + 1;
      maxlen = std::max(maxlen, wind);
      i++;
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
