package sliding_window;
import common.*;


public class P567 {
/*
 * @lc app=leetcode id=567 lang=java
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
 */
    // @lc code=start
    public class Solution {
        public boolean checkInclusion(String s1, String s2) {
            int n1 = s1.length(), n2 = s2.length();
            if (n1 > n2) return false;
            int[] need = new int[26], have = new int[26];
            for (int i=0;i<n1;i++) need[s1.charAt(i)-'a']++;
            for (int i=0;i<n2;i++){
                have[s2.charAt(i)-'a']++;
                if (i>=n1) have[s2.charAt(i-n1)-'a']--;
                if (i+1>=n1 && same(have, need)) return true;
            }
            return false;
        }
        private boolean same(int[] a, int[] b){ for(int i=0;i<26;i++) if (a[i]!=b[i]) return false; return true; }
    }
    // @lc code=end
}
