/*
 * @lc app=leetcode id=139 lang=golang
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
 * Explanation: Return true because "leetcode" can be segmented as "leet
 * code".
 *
 * Example 2:
 * Input: s = "applepenapple", wordDict = ["apple","pen"]
 * Output: true
 * Explanation: Return true because "applepenapple" can be segmented as "apple
 * pen apple".
 * Note that you are allowed to reuse a dictionary word.
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

package main

func wordBreak(s string, wordDict []string) bool {
	n := len(s)
	dp := make([]bool, n+1)
	dp[0] = true // Empty string can always be broken

	// Convert wordDict to map for O(1) lookup
	wordSet := make(map[string]bool)
	for _, word := range wordDict {
		wordSet[word] = true
	}

	for i := 1; i <= n; i++ {
		for j := 0; j < i; j++ {
			word := s[j:i]
			if dp[j] && wordSet[word] {
				dp[i] = true
				break
			}
		}
	}

	return dp[n]
}
