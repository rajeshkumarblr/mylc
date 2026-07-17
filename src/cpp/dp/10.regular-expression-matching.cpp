#include <set>
#include <cmath>
#include <map>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=10 lang=cpp
 *
 * [10] Regular Expression Matching
 *
 * Difficulty: Hard
 * Category: dp
 * URL: https://leetcode.com/problems/regular-expression-matching/
 *
 * Description:
 * Given an input string  s  and a pattern  p , implement regular expression
 * matching with support for  '.'  and  '*'  where:
 *           '.'  Matches any single character.​​​​
 *           '*'  Matches zero or more of the preceding element.
 *  Return a boolean indicating whether the matching covers the entire input
 * string (not partial).
 *   Example 1:
 *  Input:  s = "aa", p = "a"
 *  Output:  false
 *  Explanation:  "a" does not match the entire string "aa".
 *   Example 2:
 *  Input:  s = "aa", p = "a*"
 *  Output:  true
 *  Explanation:  '*' means zero or more of the preceding element, 'a'.
 * Therefore, by repeating 'a' once, it becomes "aa".
 *   Example 3:
 *  Input:  s = "ab", p = ".*"
 *  Output:  true
 *  Explanation:  ".*" means "zero or more (*) of any character (.)".
 *   Constraints:
 *           1 <= s.length <= 20
 *           1 <= p.length <= 20
 *           s  contains only lowercase English letters.
 *           p  contains only lowercase English letters,  '.' , and  '*' .
 *          It is guaranteed for each appearance of the character  '*' , there
 * will be a previous valid character to match.
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
    bool isMatch(string s, string p) {
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    cerr << "FAIL (No test cases)" << endl;
    return 1;
}
