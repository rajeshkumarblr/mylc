package hash;
import common.*;
import java.util.*;

/**
 * 242. Valid Anagram
 * Easy
 *
 * Given two strings s and t, return true if t is an anagram of s, and false
 * otherwise.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 * Example 1:
 * Input: s = "anagram", t = "nagaram"
 * [2,0,0,....1.,,1,1]
 * Output: true
 *
 * Example 2:
 * Input: s = "rat", t = "car"
 * Output: false
 *
 * Constraints:
 * 1 <= s.length, t.length <= 5 * 10^4
 * s and t consist of lowercase English letters.
 *
 * Follow up: What if the inputs contain Unicode characters? How would you adapt
 * your solution to such a case?
 */
public class P242 {
    // @lc app=leetcode id=242 lang=java
    // @lc code=start
    public static class Solution {
        public boolean isAnagram(String s, String t) {
            if (s.length() != t.length()) {
                return false;
            }
            int counts[] = new int[26];
            int len = s.length();
            for (int i = 0; i < len; i++) {
                counts[s.charAt(i) - 'a']++;
            }
            for (int i = 0; i < len; i++) {
                int ind = t.charAt(i) - 'a';
                counts[ind]--;
                if (counts[ind] < 0) {
                    return false;
                }
            }
            return true;
        }
    }
    // @lc code=end

    // Wrapper for compatibility with your driver
    public boolean isAnagram(String s, String t) {
        return new Solution().isAnagram(s, t);
    }
}
