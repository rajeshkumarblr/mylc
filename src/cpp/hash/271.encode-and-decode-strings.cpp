#include <set>
#include <cmath>
#include <map>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=271 lang=cpp
 *
 * [271] Encode and Decode Strings
 *
 * Difficulty: Medium
 * Category: hash
 * URL: https://leetcode.com/problems/encode-and-decode-strings/
 *
 * Description:
 * Premium problem or no description found.
 */

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;


// @lc code=start
class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        return "";
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        return {};
    }
};
// @lc code=end


#include <nlohmann/json.hpp>
#include <iostream>

using json = nlohmann::json;

int main() {
  try {
    json j = json::parse(R"raw({
      "cases": [
        {
          "strs": ["Hello", "World"]
        },
        {
          "strs": [""]
        },
        {
          "strs": ["", ""]
        },
        {
          "strs": ["leet", "code", "love", "you"]
        },
        {
          "strs": ["a#b", "c", "d!e", "some234", "#"]
        }
      ]
    })raw");
    
    for (auto &tc : j.at("cases")) {
      vector<string> strs = tc.at("strs").get<vector<string>>();
      Solution sol;
      
      string encoded = sol.encode(strs);
      vector<string> decoded = sol.decode(encoded);
      
      if (decoded != strs) {
        cerr << "FAIL:" << endl;
        cerr << "Original: ";
        for (const string& s : strs) cerr << "\"" << s << "\" ";
        cerr << endl << "Decoded:  ";
        for (const string& s : decoded) cerr << "\"" << s << "\" ";
        cerr << endl;
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
