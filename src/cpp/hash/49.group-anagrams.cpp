#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <utility>
/*
 * @lc app=leetcode id=49 lang=cpp
 *
 * [49] Group Anagrams
 *
 * Difficulty: Medium
 * Category: hash
 * URL: https://leetcode.com/problems/group-anagrams/
 *
 * Description:
 * Given an array of strings  strs , group the  anagrams  together. You can
 * return the answer in  any order .
 *   Example 1:
 *   Input:   strs = ["eat","tea","tan","ate","nat","bat"]
 *   Output:   [["bat"],["nat","tan"],["ate","eat","tea"]]
 *   Explanation:
 *          There is no string in strs that can be rearranged to form  "bat" .
 *          The strings  "nat"  and  "tan"  are anagrams as they can be
 * rearranged to form each other.
 *          The strings  "ate" ,  "eat" , and  "tea"  are anagrams as they can
 * be rearranged to form each other.
 *   Example 2:
 *   Input:   strs = [""]
 *   Output:   [[""]]
 *   Example 3:
 *   Input:   strs = ["a"]
 *   Output:   [["a"]]
 *   Constraints:
 *           1 <= strs.length <= 10 4
 *           0 <= strs[i].length <= 100
 *           strs[i]  consists of lowercase English letters.
 */

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> countsMap;
    for (auto &s : strs) {
      int counts[26] = {0};
      for (char ch : s) {
        counts[ch - 'a']++;
      }
      string key = "";
      for (int i = 0; i < 26; i++) {
        if (counts[i]) {
          key += ('a' + i);
          key += counts[i];
        }
      }
      countsMap[key].push_back(std::move(s));
    }

    vector<vector<string>> res;
    res.reserve(countsMap.size());
    for (auto &pair : countsMap) {
      res.push_back(std::move(pair.second));
    }
    return res;
  }
};
// @lc code=end

void sortResult(vector<vector<string>> &res) {
  for (auto &v : res) {
    sort(v.begin(), v.end());
  }
  sort(res.begin(), res.end());
}

int main() {
  Solution sol;
  // Case 1
  {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};
    auto got = sol.groupAnagrams(strs);
    auto expected =
        vector<vector<string>>{{"bat"}, {"nat", "tan"}, {"ate", "eat", "tea"}};

    sortResult(got);
    sortResult(expected);

    if (got != expected) {
      cerr << "FAIL case 1" << endl;
      return 1;
    }
  }
  // Case 2
  {
    vector<string> strs = {""};
    auto got = sol.groupAnagrams(strs);
    if (got != vector<vector<string>>{{""}}) {
      cerr << "FAIL case 2" << endl;
      return 1;
    }
  }
  // Case 3
  {
    vector<string> strs = {"a"};
    auto got = sol.groupAnagrams(strs);
    if (got != vector<vector<string>>{{"a"}}) {
      cerr << "FAIL case 3" << endl;
      return 1;
    }
  }
  cout << "PASS" << endl;
  return 0;
}
