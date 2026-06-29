/*
 * @lc app=leetcode id=424 lang=golang
 *
 * [424] Longest Repeating Character Replacement
 *
 * https://leetcode.com/problems/longest-repeating-character-replacement/description/
 *
 * You are given a string s and an integer k. You can choose any character of
 * the string and change it to any other uppercase English character. You can
 * perform this operation at most k times.
 *
 * Return the length of the longest substring containing the same letter you
 * can get after performing the above operations.
 *
 * Example 1:
 * Input: s = "ABAB", k = 2
 * Output: 4
 * Explanation: Replace the two 'A's with two 'B's or vice versa.
 *
 * Example 2:
 * Input: s = "AABABBA", k = 1
 * Output: 4
 * Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
 * The substring "BBBB" has the longest repeating character, which is 4.
 * There may exists other ways to achieve this answer length.
 *
 * Constraints:
 * - 1 <= s.length <= 10^5
 * - s consists of only uppercase English letters.
 * - 0 <= k <= s.length
 */

package main

func characterReplacement(s string, k int) int {
	count := [26]int{}
	maxCount := 0
	res := 0
	left := 0
	for right := 0; right < len(s); right++ {
		count[s[right]-'A']++
		if count[s[right]-'A'] > maxCount {
			maxCount = count[s[right]-'A']
		}
		if right-left+1-maxCount > k {
			count[s[left]-'A']--
			left++
		}
		if right-left+1 > res {
			res = right - left + 1
		}
	}
	return res
}
