#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <utility>
/*
 * @lc app=leetcode id=125 lang=cpp
 *
 * [125] Valid Palindrome
 *
 * Difficulty: Easy
 * Category: two_pointer
 * URL: https://leetcode.com/problems/valid-palindrome/
 *
 * Description:
 * A phrase is a  palindrome  if, after converting all uppercase letters into
 * lowercase letters and removing all non-alphanumeric characters, it reads
 * the same forward and backward. Alphanumeric characters include letters and
 * numbers.
 *  Given a string  s , return  true   if it is a  palindrome , or   false
 * otherwise .
 *   Example 1:
 *  Input:  s = "A man, a plan, a canal: Panama"
 *  Output:  true
 *  Explanation:  "amanaplanacanalpanama" is a palindrome.
 *   Example 2:
 *  Input:  s = "race a car"
 *  Output:  false
 *  Explanation:  "raceacar" is not a palindrome.
 *   Example 3:
 *  Input:  s = " "
 *  Output:  true
 *  Explanation:  s is an empty string "" after removing non-alphanumeric
 * characters.
 * Since an empty string reads the same forward and backward, it is a
 * palindrome.
 *   Constraints:
 *           1 <= s.length <= 2 * 10 5
 *           s  consists only of printable ASCII characters.
 */

#include <cctype>
#include <string>
using namespace std;

// @lc code=start
class Solution {
public:
  bool isPalindrome(string &s) {
    int l = 0;
    int r = s.size() - 1;
    while (l < r) {
      while (l < r && !isalnum(s[l])) {
        l++;
      }
      while (l < r && !isalnum(s[r])) {
        r--;
      }
      if (tolower(s[l]) == tolower(s[r])) {
        l++;
        r--;
      } else {
        break;
      }
    }
    return l >= r;
  }
};
// @lc code=end

#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
  try {
    json j = json::parse(R"raw({
      "cases": [
        {
          "s": "A man, a plan, a canal: Panama",
          "expected": true
        },
        {
          "s": "race a car",
          "expected": false
        },
        {
          "s": " ",
          "expected": true
        },
        {
          "s": "0P",
          "expected": false
        }
      ]
    })raw");

    for (auto &tc : j.at("cases")) {
      string s = tc.at("s").get<string>();
      bool expected = tc.at("expected").get<bool>();

      Solution sol;
      bool result = sol.isPalindrome(s);

      if (result != expected) {
        cerr << "FAIL for input: \"" << s << "\"" << endl;
        cerr << "Expected: " << (expected ? "true" : "false")
             << ", Got: " << (result ? "true" : "false") << endl;
        return 1;
      }
    }
    cout << "PASS" << endl;
    return 0;
  } catch (const exception &e) {
    cerr << "Exception: " << e.what() << endl;
    return 1;
  }
}
