package dp;

import common.*;

import java.util.*;

/**
 * 139. Word Break
 * Difficulty: Medium
 * 
 * Problem:
 * Given a string s and a dictionary of strings wordDict, return true if s can 
 * be segmented into a space-separated sequence of dictionary words.
 * 
 * Example 1:
 * s = "leetcode", wordDict = ["leet", "code"]
 * Output: true (because "leetcode" can be split into "leet" and "code")
 * 
 * Example 2:
 * s = "applepenapple", wordDict = ["apple", "pen"]
 * Output: true (because "applepenapple" can be split into "apple", "pen", "apple")
 * 
 * Example 3:
 * s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
 * Output: false
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
         * Time Complexity: O(n^3) - Two nested loops O(n^2) and substring operation O(n).
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