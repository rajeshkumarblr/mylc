#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
#include <stack>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * Given two strings s and p, return an array of all the start indices of p's
 * anagrams in s. You may return the answer in any order.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 * Example 1:
 * Input: s = "cbaebabacd", p = "abc"
 * Output: [0,6]
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 *
 * Example 2:
 * Input: s = "abab", p = "ab"
 * Output: [0,1,2]
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 *
 * Constraints:
 * - 1 <= s.length, p.length <= 3 * 10^4
 * - s and p consist of lowercase English letters.
 */
#include <vector>
#include <string>
#include <map>
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
















// Non-LeetCode wrapper for harness






int main() {
    Solution sol;
    // Case 1
    {
        string s = "cbaebabacd";
        string p = "abc";
        auto got = sol.findAnagrams(s, p);
        if (got != vector<int>{0, 6}) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        string s = "abab";
        string p = "ab";
        auto got = sol.findAnagrams(s, p);
        if (got != vector<int>{0, 1, 2}) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        string s = "baa";
        string p = "aa";
        auto got = sol.findAnagrams(s, p);
        if (got != vector<int>{1}) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    // Case 4
    {
        string s = "abc";
        string p = "def";
        auto got = sol.findAnagrams(s, p);
        if (got != vector<int>{}) {
            cerr << "FAIL case 4" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
