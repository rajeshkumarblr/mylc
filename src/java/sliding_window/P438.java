package sliding_window;
import common.*;


public class P438 {
/*
 * @lc app=leetcode id=438 lang=java
 *
 * [438] Find All Anagrams in a String
 *
 * https://leetcode.com/problems/find-all-anagrams-in-a-string/description/
 *
 * Given two strings s and p, return an array of all the start indices of p's
 * anagrams in s. You may return the answer in any order.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 * Example 1:
 * Input: s = "cbaebabacd", p = "abc"
 * Output: [0,6]
 * Explanation:
 * The substring with start index = 0 is "cba", which is an anagram of "abc".
 * The substring with start index = 6 is "bac", which is an anagram of "abc".
 *
 * Example 2:
 * Input: s = "abab", p = "ab"
 * Output: [0,1,2]
 * Explanation:
 * The substring with start index = 0 is "ab", which is an anagram of "ab".
 * The substring with start index = 1 is "ba", which is an anagram of "ab".
 * The substring with start index = 2 is "ab", which is an anagram of "ab".
 *
 * Constraints:
 * - 1 <= s.length, p.length <= 3 * 10^4
 * - s and p consist of lowercase English letters.
 */
    // @lc code=start
    public class Solution {
        public java.util.List<Integer> findAnagrams(String s, String p) {
            int[] need = new int[26], have = new int[26];
            for (int i=0;i<p.length();i++) need[p.charAt(i)-'a']++;
            java.util.List<Integer> ans = new java.util.ArrayList<>();
            int m=p.length();
            for (int i=0;i<s.length();i++){
                have[s.charAt(i)-'a']++;
                if (i>=m) have[s.charAt(i-m)-'a']--;
                if (i+1>=m && same(have, need)) ans.add(i-m+1);
            }
            return ans;
        }
        private boolean same(int[] a, int[] b){
            for(int i=0;i<26;i++) if (a[i]!=b[i]) return false; return true;
        }
    }
    // @lc code=end
}
