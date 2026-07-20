#include <cmath>
#include <iostream>
#include <map>
#include <set>
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
 * Design an algorithm to encode a list of strings to a single string. The
 * encoded string is then sent over the network and is decoded back to the
 * original list of strings.
 *
 * Machine 1 (sender) has the function:
 * string encode(vector<string> strs) {
 *   // ... your code
 *   return encoded_string;
 * }
 *
 * Machine 2 (receiver) has the function:
 * vector<string> decode(string s) {
 *   //... your code
 *   return strs;
 * }
 *
 * Implement the encode and decode methods.
 *
 * Note:
 * - The string may contain any possible characters out of 256 valid ascii
 * characters. Your algorithm should be generalized enough to work on any
 * possible characters.
 * - Do not use class member/global/static variables to store states. Your
 * encode and decode algorithms should be stateless.
 * - Do not rely on any library method such as eval or serialize methods. You
 * should implement your own encode/decode algorithm.
 */

#include <algorithm>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

//{3bc,def} ==>33bc3def

// @lc code=start
class Solution {
public:
  // Encodes a list of strings to a single string.
  string encode(vector<string> &strs) {
    string res = "";
    for (string s : strs) {
      int len = s.size();
      res += to_string(len) + "#" + s;
    }
    return res;
  }

  // Decodes a single string to a list of strings.
  vector<string> decode(string s) {
    vector<string> res;
    int ind = 0;
    for (int i = 0; i < s.size();) {
      int st = i;
      while (i < s.size() && s[i] != '#') {
        i++;
      }
      string lenheader = s.substr(st, i - st);
      int len = stoi(lenheader);
      string word = s.substr(i + 1, len);
      res.push_back(word);
      i = i + 1 + len;
    }
    return res;
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
        for (const string &s : strs)
          cerr << "\"" << s << "\" ";
        cerr << endl << "Decoded:  ";
        for (const string &s : decoded)
          cerr << "\"" << s << "\" ";
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
