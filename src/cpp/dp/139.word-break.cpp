/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // Empty string can always be broken
        
        // Convert wordDict to unordered_set for O(1) lookup
        unordered_set<string> wordSet(wordDict.begin(), wordDict.end());
        
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                string word = s.substr(j, i - j);
                if (dp[j] && wordSet.find(word) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        
        return dp[n];
    }
};
// @lc code=end

bool wordBreak(string s, vector<string>& wordDict) {
    Solution sol;
    return sol.wordBreak(s, wordDict);
}