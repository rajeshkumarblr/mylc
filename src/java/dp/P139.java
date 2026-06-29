package dp;

import common.*;

import java.util.*;

/*
 * @lc app=leetcode id=139 lang=java
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
 */
public class P139 {
    // @lc app=leetcode id=139 lang=java
    // @lc code=start
    public static class Solution {
        /**
         * DP Approach:
         * We use a boolean array dp[] where dp[i] is true if the prefix s[0...i-1]
         * can be segmented into words from the dictionary.
         * 
         * Time Complexity: O(n^3) - Two nested loops O(n^2) and substring operation
         * O(n).
         * Space Complexity: O(n) - For the dp array and HashSet.
         */
        public boolean wordBreak(String s, List<String> wordDict) {
            int n = s.length();
            // dp[i] means s.substring(0, i) can be segmented
            boolean[] dp = new boolean[n + 1];

            // Base case: empty string is always valid
            dp[0] = true;

            // Convert wordDict to HashSet for O(1) average lookup
            Set<String> wordSet = new HashSet<>(wordDict);

            // Transition:
            // For each prefix of length i, check every possible split point j
            for (int i = 1; i <= n; i++) {
                for (int j = 0; j < i; j++) {
                    // If s[0...j] is breakable AND s[j...i] is in the dictionary
                    if (dp[j] && wordSet.contains(s.substring(j, i))) {
                        dp[i] = true;
                        break; // No need to check other j for this i
                    }
                }
            }

            return dp[n];
        }
    }
    // @lc code=end

    // Wrapper method for driver compatibility
    public boolean wordBreak(String s, List<String> wordDict) {
        return new Solution().wordBreak(s, wordDict);
    }
}