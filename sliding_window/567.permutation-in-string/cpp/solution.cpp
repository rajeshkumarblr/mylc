/*
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * algorithms
 * Medium (47.59%)
 * Likes:    12523
 * Dislikes: 498
 * Total Accepted:    1.3M
 * Total Submissions: 2.7M
 * Testcase Example:  '"ab"\n"eidbaooo"'
 *
 * Given two strings s1 and s2, return true if s2 contains a permutation of s1,
 * or false otherwise.
 * 
 * In other words, return true if one of s1's permutations is the substring of
 * s2.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= s1.length, s2.length <= 10^4
 * s1 and s2 consist of lowercase English letters.
 * 
 * 
 */

#include <iostream>
#include <string>
#include <map>

using namespace std;

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int> s1Map, s2Map;
        for (const auto& c:s1) {
            s1Map[c]++;
        }

        int left = 0;
        int windowLen = s1.length();
        for (auto right = 0; right <(int)s2.length(); right++) {

            auto nextChar = s2[right];
            s2Map[nextChar]++;

            int curWindowLen = right - left + 1;
            if (curWindowLen < windowLen) {
                continue;
            } else  if ( (curWindowLen == windowLen) && (s1Map == s2Map) ) {
                return true;
            }

            auto prevChar = s2[left];
            s2Map[prevChar]--;
            if (s2Map[prevChar] == 0)
            {
                s2Map.erase(prevChar);
            }


            left++;
        }
        return (s1Map == s2Map);
    }
};
// @lc code=end

int main()
{
    Solution sol;
    cout << sol.checkInclusion("ab","eidbaooo") << endl;
    return 0;
}

