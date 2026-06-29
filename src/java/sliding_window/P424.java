package sliding_window;
import common.*;


public class P424 {
/*
 * @lc app=leetcode id=424 lang=java
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
 * The substring "BBBB" has the longest repeating letters, which is 4.
 * There may exists other ways to achieve this maximum length.
 *
 * Constraints:
 * - 1 <= s.length <= 10^5
 * - s consists of only uppercase English letters.
 * - 0 <= k <= s.length
 */
    // @lc code=start
    public class Solution {
        public int characterReplacement(String s, int k) {
            int[] cnt = new int[26];
            int best = 0, maxFreq = 0, l = 0;
            for (int r = 0; r < s.length(); r++) {
                int idx = s.charAt(r) - 'A';
                cnt[idx]++;
                maxFreq = Math.max(maxFreq, cnt[idx]);
                while (r - l + 1 - maxFreq > k) {
                    cnt[s.charAt(l) - 'A']--;
                    l++;
                }
                best = Math.max(best, r - l + 1);
            }
            return best;
        }
    }
    // @lc code=end
}
