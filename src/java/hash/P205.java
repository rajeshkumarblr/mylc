package hash;

import common.*;
import java.util.*;

/**
 * 205. Isomorphic Strings
 * Easy
 *
 * Given two strings s and t, determine if they are isomorphic.
 * Two strings s and t are isomorphic if the characters in s can be replaced to
 * get t.
 *
 * All occurrences of a character must be replaced with another character while
 * preserving the order of characters. No two characters may map to the same
 * character, but a character may map to itself.
 *
 * Example 1:
 * Input: s = "egg", t = "add"
 * Output: true
 * 
 * 
 * Example 2:
 * Input: s = "foo", t = "bar"
 * Output: false
 *
 * Example 3:
 * Input: s = "paper", t = "title"
 * Output: true
 *
 * Constraints:
 * 1 <= s.length <= 5 * 10^4
 * t.length == s.length
 * s and t consist of any valid ascii character.
 */
public class P205 {
    // @lc app=leetcode id=205 lang=java
    // @lc code=start
    public static class Solution {
        public boolean isIsomorphic(String s, String t) {
            int lastSeenPositions1[] = new int[256];
            int lastSeenPositions2[] = new int[256];
            Arrays.fill(lastSeenPositions1, -1);
            Arrays.fill(lastSeenPositions2, -1);
            for (int i = 0; i < s.length(); i++) {
                char ch1 = s.charAt(i);
                char ch2 = t.charAt(i);
                if (lastSeenPositions1[ch1] != lastSeenPositions2[ch2]) {
                    return false;
                }
                lastSeenPositions1[ch1] = i;
                lastSeenPositions2[ch2] = i;
            }

            return true;
        }
    }
    // @lc code=end

    // Wrapper for compatibility with your driver
    public boolean isIsomorphic(String s, String t) {
        return new Solution().isIsomorphic(s, t);
    }
}
