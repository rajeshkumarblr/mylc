/*
 * @lc app=leetcode id=242 lang=cpp
 *
 * [242] Valid Anagram
 *
 * Difficulty: Easy
 * Category: hash
 * URL: https://leetcode.com/problems/valid-anagram/
 *
 * Description:
 * Given two strings  s  and  t , return  true  if  t  is an  anagram  of  s ,
 * and  false  otherwise.
 *   Example 1:
 *   Input:   s = "anagram", t = "nagaram"
 *   Output:   true
 *   Example 2:
 *   Input:   s = "rat", t = "car"
 *   Output:   false
 *   Constraints:
 *           1 <= s.length, t.length <= 5 * 10 4
 *           s  and  t  consist of lowercase English letters.
 *   Follow up:  What if the inputs contain Unicode characters? How would you
 * adapt your solution to such a case?
 */

#include "../lc_test_utils.h"
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.length() != t.length()) {
      return false;
    }
    
    // Since we only have lowercase English letters, a fixed array of size 26 is much 
    // faster and uses way less memory than an unordered_map (zero dynamic allocations!).
    int counts[26] = {0};
    
    // We can even do this in a single pass!
    for (int i = 0; i < s.length(); i++) {
      counts[s[i] - 'a']++;
      counts[t[i] - 'a']--;
    }
    
    // If they are anagrams, every bucket should be perfectly balanced back to 0
    for (int count : counts) {
      if (count != 0) {
        return false;
      }
    }
    
    return true;
  }
};
// @lc code=end

// Backup approach for Unicode characters (as discussed in follow-up)
class Solution_Map {
public:
  bool isAnagram(string s, string t) {
    unordered_map<char, int> counts;
    if (s.length() != t.length()) {
      return false;
    }
    for (const auto ch : s) {
      counts[ch]++;
    }
    for (const auto ch : t) {
      counts[ch]--;
      if (counts[ch] < 0) {
        return false;
      }
    }
    return true;
  }
};
