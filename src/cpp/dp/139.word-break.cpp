#include <queue>
#include <unordered_map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 *
 * https://leetcode.com/problems/word-break/description/
 *
 * Given a string s and a dictionary of strings wordDict, return true if s can
 * be segmented into a space-separated sequence of one or more dictionary
 * words.
 *
 * Note that the same word in the dictionary may be reused multiple times in
 * the segmentation.
 *
 * Example 1:
 * Input: s = "leetcode", wordDict = ["leet","code"]
 * Output: true
 * Explanation: Return true because "leetcode" can be segmented as "leet code".
 *
 * Example 2:
 * Input: s = "applepenapple", wordDict = ["apple","pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple". Note that you are allowed to reuse a dictionary word.
 *
 * Example 3:
 * Input: s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 * Output: false
 *
 * Constraints:
 * - 1 <= s.length <= 300
 * - 1 <= wordDict.length <= 1000
 * - 1 <= wordDict[i].length <= 20
 * - s and wordDict[i] consist of only lowercase English letters.
 * - All the strings of wordDict are unique.
 *
 * Description:
 * Given a string  s  and a dictionary of strings  wordDict , return  true  if
 * s  can be segmented into a space-separated sequence of one or more
 * dictionary words.
 *   Note  that the same word in the dictionary may be reused multiple times
 * in the segmentation.
 *   Example 1:
 *  Input:  s = "leetcode", wordDict = ["leet","code"]
 *  Output:  true
 *  Explanation:  Return true because "leetcode" can be segmented as "leet
 * code".
 *   Example 2:
 *  Input:  s = "applepenapple", wordDict = ["apple","pen"]
 *  Output:  true
 *  Explanation:  Return true because "applepenapple" can be segmented as
 * "apple pen apple".
 * Note that you are allowed to reuse a dictionary word.
 *   Example 3:
 *  Input:  s = "catsandog", wordDict = ["cats","dog","sand","and","cat"]
 *  Output:  false
 *   Constraints:
 *           1 <= s.length <= 300
 *           1 <= wordDict.length <= 1000
 *           1 <= wordDict[i].length <= 20
 *           s  and  wordDict[i]  consist of only lowercase English letters.
 *          All the strings of  wordDict  are  unique .
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


int main() {
    Solution sol;
    // Case 1
    {
        string s = "leetcode";
        vector<string> wordDict = {"leet", "code"};
        auto got = sol.wordBreak(s, wordDict);
        if (got != true) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        string s = "applepenapple";
        vector<string> wordDict = {"apple", "pen"};
        auto got = sol.wordBreak(s, wordDict);
        if (got != true) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        string s = "catsandog";
        vector<string> wordDict = {"cats", "dog", "sand", "and", "cat"};
        auto got = sol.wordBreak(s, wordDict);
        if (got != false) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    // Case 4
    {
        string s = "aaaaaaa";
        vector<string> wordDict = {"aaaa", "aaa"};
        auto got = sol.wordBreak(s, wordDict);
        if (got != true) {
            cerr << "FAIL case 4" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
