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
#ifndef LC_LOCAL_TEST
class Solution {
public:
#endif
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

#ifndef LC_LOCAL_TEST
};
#endif
// @lc code=end

