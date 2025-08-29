/*
 * @lc app=leetcode id=438 lang=cpp
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * algorithms
 * Medium (52.48%)
 * Likes:    12876
 * Dislikes: 361
 * Total Accepted:    1.1M
 * Total Submissions: 2M
 * Testcase Example:  '"cbaebabacd"\n"abc"'
 *
 * Given two strings s and p, return an array of all the start indices of p's
 * anagrams in s. You may return the answer in any order.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s = "cbaebabacd", p = "abc"
 * Output: [0,6]
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s = "abab", p = "ab"
 * Output: [0,1,2]
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s.length, p.length <= 3 * 10^4
 * s and p consist of lowercase English letters.
 * 
 * 
 */
#include <vector>
#include <string>
#include <map>
#include <iostream>
#include <cstring>
using namespace std;

// @lc code=start
class Solution {
public:
        vector<int> findAnagrams(string s, string p) {
            vector<int> result = {};
            if (s.size() < p.size()) return result;

            map<char, int> pCount, sCount;
            for (int i=0; i<p.size(); i++) {
                pCount[p[i]]++;
                sCount[s[i]]++;
            }
            if ( pCount == sCount) {
                result.push_back(0);
            }

            int left = 0;
            for (int right = p.size(); right < s.size(); ++right) {

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

int main()
{
    Solution sol;
    map < pair<string,string>, vector<int>> testMap = {
        { {"cbaebabacd", "abc"}, {0,6} }
    };
    bool failed = false;
    for (const auto& [input, expected]: testMap)
    {
        string s = input.first;
        string p = input.second;
        auto v = sol.findAnagrams(s, p);
        if ( v != expected)
        {
            cerr << "test failed for:" << input.first << endl;
            cerr << "actual: [ ";
            for (auto i: v)
            {
                cerr << i << ", ";
            }
            cerr << " ]" << endl;
            failed = true;
        }
    }
    if (!failed) cout << "test passed" << endl;
    return 0;
}
