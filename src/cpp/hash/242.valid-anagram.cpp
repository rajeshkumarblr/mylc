#include <unordered_set>
#include <queue>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <iostream>
#include <utility>
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
};





int main() {
    Solution sol;
    // Case 1
    {
        string s = "anagram";
        string t = "nagaram";
        auto got = sol.isAnagram(s, t);
        if (got != true) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        string s = "rat";
        string t = "car";
        auto got = sol.isAnagram(s, t);
        if (got != false) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
