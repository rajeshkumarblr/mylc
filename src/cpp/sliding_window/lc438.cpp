/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 */
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cstring>
#include "lc_test_utils.h"
using namespace std;

// @lc code=start
class Solution {
public:
        vector<int> findAnagrams(string s, string p) {
            vector<int> result = {};
            if (s.size() < p.size()) return result;

            map<char, int> pCount, sCount;
            for (int i=0; i<(int)p.size(); i++) {
                pCount[p[i]]++;
                sCount[s[i]]++;
            }
            if ( pCount == sCount) {
                result.push_back(0);
            }

            int left = 0;
            for (int right = (int)p.size(); right < (int)s.size(); ++right) {

                //take the next char in right into the window.
                sCount[s[right]]++;

                // remoe the left most char from window.
                if (--sCount[s[left]] == 0) sCount.erase(s[left]);

                /* compare the counts of "s" and "p" right now.*/
                if (sCount == pCount) {
                    /* both are same, so we found a match! */
                    // NOTE: the window here is (left+1 , right).
                    // So when you find a match, insert "left+1" not "left".
                    result.push_back(left+1);
                }

                left++;
            }
            return result;
        }
};
// @lc code=end


int main() {
    Solution sol;
    vector<tuple<string, string, vector<int>>> tests = {
        {"cbaebabacd", "abc", {0,6}},    // Example 1
        {"abab", "ab", {0,1,2}},         // Example 2
        {"a", "a", {0}},                 // Edge case
        {"a", "b", {}},                  // Edge case
        {"baa", "aa", {1}},              // Custom
        {"abc", "abcd", {}}              // Custom: p longer than s
    };
    bool all_passed = true;
    for (const auto& [s, p, expected] : tests) {
        auto result = sol.findAnagrams(s, p);
        all_passed &= print_test_result(s + ", " + p, result, expected);
    }
    return all_passed ? 0 : 1;
}
