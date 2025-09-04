/*
 * @lc app=leetcode id=3 lang=cpp
 *
 * [3] Longest Substring Without Repeating Characters
 *
 * https://leetcode.com/problems/longest-substring-without-repeating-characters/description/
 */

#include <string>
#include <vector>
#include <set>
#include <unordered_map>
#include <iostream>
#include "lc_test_utils.h"

using namespace std;

// @lc code=start
class Solution
{
public:
    int lengthOfLongestSubstring(string s) {
        return lengthOfLongestSubstring_vector(s);
        // return lengthOfLongestSubstring_map(s);
        // return lengthOfLongestSubstring_set(s);
    }

    // --- Approach 1: Using fixed-size vector as last index map ---
    int lengthOfLongestSubstring_vector(string s) {
        vector<int> charIndex(256, -1);
        int res = 0, l = 0, r = 0;
        for (unsigned char c : s) {
            if (charIndex[c] >= l) {
                l = charIndex[c] + 1;
            }
            charIndex[c] = r;
            res = max(res, r - l + 1);
            r++;
        }
        return res;
    }

    // --- Approach 2: Using unordered_map for last seen index ---
    int lengthOfLongestSubstring_map(string s) {
        unordered_map<char, int> charMap;
        int res = 0, l = 0;
        for (int r = 0; r < (int)s.length(); ++r) {
            char next = s[r];
            if (charMap.find(next) != charMap.end() && charMap[next] >= l) {
                l = charMap[next] + 1;
            }
            charMap[next] = r;
            res = max(res, r - l + 1);
        }
        return res;
    }

    // --- Approach 3: Using set and sliding window ---
    int lengthOfLongestSubstring_set(string s) {
        set<char> charSet;
        int res = 0, left = 0;
        for (int right = 0; right < (int)s.length(); ++right) {
            char next = s[right];
            while (charSet.count(next)) {
                charSet.erase(s[left]);
                left++;
            }
            charSet.insert(next);
            res = max(res, right - left + 1);
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
