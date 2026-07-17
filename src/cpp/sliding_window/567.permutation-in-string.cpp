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
 * @lc app=leetcode id=567 lang=cpp
 *
 * [567] Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/description/
 *
 * Given two strings s1 and s2, return true if s2 contains a permutation of
 * s1, or false otherwise.
 *
 * In other words, return true if one of s1's permutations is the substring of
 * s2.
 *
 * Example 1:
 * Input: s1 = "ab", s2 = "eidbaooo"
 * Output: true
 * Explanation: s2 contains one permutation of s1 ("ba").
 *
 * Example 2:
 * Input: s1 = "ab", s2 = "eidboaoo"
 * Output: false
 *
 * Constraints:
 * - 1 <= s1.length, s2.length <= 10^4
 * - s1 and s2 consist of lowercase English letters.
 *
 * Description:
 * Given two strings  s1  and  s2 , return  true  if  s2  contains a
 * permutation  of  s1 , or  false  otherwise.
 *  In other words, return  true  if one of  s1 's permutations is the
 * substring of  s2 .
 *   Example 1:
 *  Input:  s1 = "ab", s2 = "eidbaooo"
 *  Output:  true
 *  Explanation:  s2 contains one permutation of s1 ("ba").
 *   Example 2:
 *  Input:  s1 = "ab", s2 = "eidboaoo"
 *  Output:  false
 *   Constraints:
 *           1 <= s1.length, s2.length <= 10 4
 *           s1  and  s2  consist of lowercase English letters.
 */

#include <string>
#include <vector>
#include <map>
using namespace std;

bool checkInclusion_vector(string s1, string s2);

// @lc code=start
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        return checkInclusion_vector(s1,s2);
        //return checkInclusion_map(s1,s2);
    }
    bool checkInclusion_vector(string s1, string s2) {
        if (s1.size() > s2.size()) return false;
        vector<int> count1(26, 0), count2(26, 0);
        for (char c : s1) count1[c - 'a']++;
        for (int i = 0; i < (int)s1.size(); ++i) count2[s2[i] - 'a']++;
        if (count1 == count2) return true;
        for (int i = (int)s1.size(); i < (int)s2.size(); ++i) {
            count2[s2[i] - 'a']++;
            count2[s2[i - s1.size()] - 'a']--;
            if (count1 == count2) return true;
        }
        return false;
    }
    
    bool checkInclusion_map(string s1, string s2) {
        map<char,int> s1Map, s2Map;
        for (const auto& c:s1) {
            s1Map[c]++;
        }

        int left = 0;
        int windowLen = (int)s1.length();
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
















// Non-LeetCode wrapper for harness






int main() {
    Solution sol;
    // Case 1
    {
        string s1 = "ab";
        string s2 = "eidbaooo";
        auto got = sol.checkInclusion(s1, s2);
        if (got != true) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        string s1 = "ab";
        string s2 = "eidboaoo";
        auto got = sol.checkInclusion(s1, s2);
        if (got != false) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        string s1 = "adc";
        string s2 = "dcda";
        auto got = sol.checkInclusion(s1, s2);
        if (got != true) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    // Case 4
    {
        string s1 = "a";
        string s2 = "a";
        auto got = sol.checkInclusion(s1, s2);
        if (got != true) {
            cerr << "FAIL case 4" << endl;
            return 1;
        }
    }
    // Case 5
    {
        string s1 = "a";
        string s2 = "b";
        auto got = sol.checkInclusion(s1, s2);
        if (got != false) {
            cerr << "FAIL case 5" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
