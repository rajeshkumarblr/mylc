#include <set>
#include <cmath>
#include <map>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=678 lang=cpp
 *
 * [678] Valid Parenthesis String
 *
 * Difficulty: Medium
 * Category: greedy
 * URL: https://leetcode.com/problems/valid-parenthesis-string/
 *
 * Description:
 * Given a string  s  containing only three types of characters:  '(' ,  ')'
 * and  '*' , return  true   if   s   is  valid  .
 *  The following rules define a  valid  string:
 *          Any left parenthesis  '('  must have a corresponding right
 * parenthesis  ')' .
 *          Any right parenthesis  ')'  must have a corresponding left
 * parenthesis  '(' .
 *          Left parenthesis  '('  must go before the corresponding right
 * parenthesis  ')' .
 *           '*'  could be treated as a single right parenthesis  ')'  or a
 * single left parenthesis  '('  or an empty string  "" .
 *   Example 1:
 *   Input:  s = "()"
 *  Output:  true
 *    Example 2:
 *   Input:  s = "(*)"
 *  Output:  true
 *    Example 3:
 *   Input:  s = "(*))"
 *  Output:  true
 *   Constraints:
 *           1 <= s.length <= 100
 *           s[i]  is  '(' ,  ')'  or  '*' .
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
    bool checkValidString(string s) {
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    cerr << "FAIL (No test cases)" << endl;
    return 1;
}
