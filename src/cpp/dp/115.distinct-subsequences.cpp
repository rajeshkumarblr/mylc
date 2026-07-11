/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 *
 * Difficulty: Hard
 * Category: dp
 * URL: https://leetcode.com/problems/distinct-subsequences/
 *
 * Description:
 * Given two strings s and t, return  the number of distinct    subsequences
 * of  s  which equals  t.
 *  The test cases are generated so that the answer fits on a 32-bit signed
 * integer.
 *   Example 1:
 *  Input:  s = "rabbbit", t = "rabbit"
 *  Output:  3
 *  Explanation:
 * As shown below, there are 3 ways you can generate "rabbit" from s.
 *    rabb  b  it
 *    ra  b  bbit
 *    rab  b  bit
 *   Example 2:
 *  Input:  s = "babgbag", t = "bag"
 *  Output:  5
 *  Explanation:
 * As shown below, there are 5 ways you can generate "bag" from s.
 *    ba  b  g  bag
 *    ba  bgba  g
 *    b  abgb  ag
 *  ba  b  gb  ag
 *  babg  bag
 *   Constraints:
 *           1 <= s.length, t.length <= 1000
 *           s  and  t  consist of English letters.
 */

#include "../lc_test_utils.h"
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
    int numDistinct(string s, string t) {
        
    }
};
// @lc code=end
