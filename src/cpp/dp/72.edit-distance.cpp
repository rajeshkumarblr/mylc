#include <set>
#include <cmath>
#include <map>
#include <iostream>
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
    int minDistance(string word1, string word2) {
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    cerr << "FAIL (No test cases)" << endl;
    return 1;
}
