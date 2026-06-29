package hash;

import java.util.*;

/*
 * @lc app=leetcode id=49 lang=java
 *
 * [49] Group Anagrams
 *
 * https://leetcode.com/problems/group-anagrams/description/
 *
 * Given an array of strings strs, group the anagrams together. You can
 * return the answer in any order.
 *
 * An Anagram is a word or phrase formed by rearranging the letters of a
 * different word or phrase, typically using all the original letters exactly
 * once.
 *
 * Example 1:
 * Input: strs = ["eat","tea","tan","ate","nat","bat"]
 * Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
 *
 * Example 2:
 * Input: strs = [""]
 * Output: [[""]]
 *
 * Example 3:
 * Input: strs = ["a"]
 * Output: [["a"]]
 *
 * Constraints:
 * - 1 <= strs.length <= 10^4
 * - 0 <= strs[i].length <= 100
 * - strs[i] consists of lowercase English letters.
 */
public class P49 {
    // @lc app=leetcode id=49 lang=java
    // @lc code=start
    public class Solution {
        /**
         * Logic:
         * Anagrams will have the same sorted representation.
         * We can use a HashMap where:
         * - Key: The sorted version of the string.
         * - Value: A list of all original strings that sort to that key.
         */

        String getAnangramString(String s) {
            int counts[] = new int[26];
            for (char c : s.toCharArray()) {
                int ind = c - 'a';
                counts[ind]++;
            }
            StringBuilder buffer = new StringBuilder();
            for (int i = 0; i < 26; i++) {
                buffer.append(counts[i]);
                buffer.append('#');
            }
            return buffer.toString();
        }

        public List<List<String>> groupAnagrams(String[] strs) {
            // Your code here
            Map<String, List<String>> anagramMap = new HashMap<>();
            for (int i = 0; i < strs.length; i++) {
                String anag = getAnangramString(strs[i]);
                if (anagramMap.containsKey(anag)) {
                    anagramMap.get(anag).add(strs[i]);
                } else {
                    List<String> mylist = new ArrayList<>();
                    mylist.add(strs[i]);
                    anagramMap.put(anag, mylist);
                }
            }

            return new ArrayList<>(anagramMap.values());
        }
    }
    // @lc code=end

    // Wrapper for driver
    public List<List<String>> groupAnagrams(String[] strs) {
        return new Solution().groupAnagrams(strs);
    }
}
