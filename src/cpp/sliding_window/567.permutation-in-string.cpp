/*
 * Test harness for LeetCode 567: Permutation in String
 *
 * https://leetcode.com/problems/permutation-in-string/
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
bool checkInclusion(string s1, string s2) {
    Solution sol;
    return sol.checkInclusion(std::move(s1), std::move(s2));
}

