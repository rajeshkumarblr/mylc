/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * Given a string s, find the length of the longest substring without
 * repeating characters.
 *
 * Example 1:
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 *
 * Example 2:
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 *
 * Example 3:
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.
 *
 * Constraints:
 * - 0 <= s.length <= 5 * 10^4
 * - s consists of English letters, digits, symbols and spaces.
 *
 * Description:
 * Given a string  s , find the length of the  longest    substring   without
 * duplicate characters.
 *   Example 1:
 *  Input:  s = "abcabcbb"
 *  Output:  3
 *  Explanation:  The answer is "abc", with the length of 3. Note that  "bca"
 * and  "cab"  are also correct answers.
 *   Example 2:
 *  Input:  s = "bbbbb"
 *  Output:  1
 *  Explanation:  The answer is "b", with the length of 1.
 *   Example 3:
 *  Input:  s = "pwwkew"
 *  Output:  3
 *  Explanation:  The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 *   Constraints:
 *           0 <= s.length <= 5 * 10 4
 *           s  consists of English letters, digits, symbols and spaces.
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
