#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <utility>
/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 *
 * Difficulty: Medium
 * Category: dp
 * URL: https://leetcode.com/problems/edit-distance/
 *
 * Description:
 * Given two strings  word1  and  word2 , return  the minimum number of
 * operations required to convert  word1  to  word2  .
 *  You have the following three operations permitted on a word:
 *          Insert a character
 *          Delete a character
 *          Replace a character
 *   Example 1:
 *  Input:  word1 = "horse", word2 = "ros"
 *  Output:  3
 *  Explanation:
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 *   Example 2:
 *  Input:  word1 = "intention", word2 = "execution"
 *  Output:  5
 *  Explanation:
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 *   Constraints:
 *           0 <= word1.length, word2.length <= 500
 *           word1  and  word2  consist of lowercase English letters.
 */

#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int minDistance(string word1, string word2) {
    int m = word1.size();
    int n = word2.size();
    
    // Create a 2D vector for DP
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    
    // Base cases
    for (int i = 0; i <= m; i++) dp[i][0] = i; // Deleting characters to match empty string
    for (int j = 0; j <= n; j++) dp[0][j] = j; // Inserting characters to match word2
    
    // Fill the grid
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        if (word1[i - 1] == word2[j - 1]) {
          // Characters match, no operation needed. Copy diagonal.
          dp[i][j] = dp[i - 1][j - 1];
        } else {
          // Characters don't match, take minimum of 3 operations + 1
          dp[i][j] = min({
            dp[i - 1][j - 1], // Replace (diagonal)
            dp[i - 1][j],     // Delete (up)
            dp[i][j - 1]      // Insert (left)
          }) + 1;
        }
      }
    }
    
    return dp[m][n];
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
          "word1": "horse",
          "word2": "ros",
          "expected": 3
        },
        {
          "word1": "intention",
          "word2": "execution",
          "expected": 5
        }
      ]
    })raw");
    for (auto &tc : j.at("cases")) {
      string word1 = tc.at("word1").get<string>();
      string word2 = tc.at("word2").get<string>();
      int expected = tc.at("expected").get<int>();
      Solution sol;
      int got = sol.minDistance(word1, word2);
      if (got != expected) {
        cerr << "FAIL: got " << got << ", expected " << expected << endl;
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
