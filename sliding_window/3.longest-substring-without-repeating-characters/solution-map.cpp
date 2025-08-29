/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 *
 * algorithms
 * Medium (37.37%)
 * Likes:    42869
 * Dislikes: 2094
 * Total Accepted:    8M
 * Total Submissions: 21.4M
 * Testcase Example:  '"abcabcbb"'
 *
 * Given a string s, find the length of the longest substring without duplicate
 * characters.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "abcabcbb"
 * Output: 3
 * Explanation: The answer is "abc", with the length of 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "bbbbb"
 * Output: 1
 * Explanation: The answer is "b", with the length of 1.
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: s = "pwwkew"
 * Output: 3
 * Explanation: The answer is "wke", with the length of 3.
 * Notice that the answer must be a substring, "pwke" is a subsequence and not
 * a substring.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= s.length <= 5 * 10^4
 * s consists of English letters, digits, symbols and spaces.
 * 
 * 
 */

 #include <string>
 #include <iostream>
 #include <vector>
 #include <unordered_map>
 #include <algorithm>
 #include <unordered_map>
 #include "../../lc_test_utils.h"
 using namespace std;

// @lc code=start
class Solution {
public:

    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> charMap;
        int res = 0, l = 0;
        for (int r = 0; r < s.length(); ++r) {
            char next = s[r];
            if ( charMap.find(next) != charMap.end() && charMap[next] >= l) {
                l = charMap[next] + 1;
            }
            charMap[next] = r;
            res = max(res, r - l + 1);
        }
        return res;
    }
};
// @lc code=end

int main() {
    Solution sol;
    vector<pair<string, int>> tests = {
        {"abcabcbb", 3},    // Example 1
        {"bbbbb", 1},       // Example 2
        {"pwwkew", 3},      // Example 3
        {"", 0},            // Edge case: empty string
        {"au", 2},          // Custom
        {"dvdf", 3}         // Custom
    };
    bool all_passed = true;
    for (const auto& [input, expected] : tests) {
        int result = sol.lengthOfLongestSubstring(input);
        all_passed &= print_test_result(input, result, expected);
    }
    return all_passed ? 0 : 1;
}
