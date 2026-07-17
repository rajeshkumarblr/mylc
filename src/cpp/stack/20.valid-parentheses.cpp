#include <unordered_set>
#include <queue>
#include <unordered_map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <vector>
#include <iostream>
#include <utility>
#include <stack>
#include <string>
using namespace std;

/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 *
 * https://leetcode.com/problems/valid-parentheses/description/
 *
 * Given a string s containing just the characters '(', ')', '{', '}', '['
 * and ']', determine if the input string is valid.
 *
 * An input string is valid if:
 * 1. Open brackets must be closed by the same type of brackets.
 * 2. Open brackets must be closed in the correct order.
 * 3. Every close bracket has a corresponding open bracket of the same type.
 *
 * Example 1:
 * Input: s = "()"
 * Output: true
 *
 * Example 2:
 * Input: s = "()[]{}"
 * Output: true
 *
 * Example 3:
 * Input: s = "(]"
 * Output: false
 *
 * Constraints:
 * - 1 <= s.length <= 10^4
 * - s consists of parentheses only '()[]{}'.
 *
 * Description:
 * Given a string  s  containing just the characters  '(' ,  ')' ,  '{' ,  '}'
 * ,  '['  and  ']' , determine if the input string is valid.
 *  An input string is valid if:
 *          Open brackets must be closed by the same type of brackets.
 *          Open brackets must be closed in the correct order.
 *          Every close bracket has a corresponding open bracket of the same
 * type.
 *   Example 1:
 *   Input:   s = "()"
 *   Output:   true
 *   Example 2:
 *   Input:   s = "()[]{}"
 *   Output:   true
 *   Example 3:
 *   Input:   s = "(]"
 *   Output:   false
 *   Example 4:
 *   Input:   s = "([])"
 *   Output:   true
 *   Example 5:
 *   Input:   s = "([)]"
 *   Output:   false
 *   Constraints:
 *           1 <= s.length <= 10 4
 *           s  consists of parentheses only  '()[]{}' .
 */

//([}])
//()[]}

// @lc code=start
class Solution {
public:
  bool isValid(string s) {
    stack<char> st;
    for (auto ch : s) {
      if (ch == '(' || ch == '{' || ch == '[') {
        st.push(ch);
      } else if (ch == ')' || ch == '}' || ch == ']') {
        if (st.empty())
          return false; // No matching opening bracket
        char ctop = st.top();
        st.pop();
        if ((ch == ')' && ctop != '(') || (ch == '}' && ctop != '{') ||
            (ch == ']' && ctop != '[')) {
          return false;
        }
      }
    }
    return st.empty(); // All brackets should be matched
  }
};
// @lc code=end


int main() {
    Solution sol;
    // Case 1
    {
        string input = "()";
        auto got = sol.isValid(input);
        if (got != true) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        string input = "()[]{}";
        auto got = sol.isValid(input);
        if (got != true) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    // Case 3
    {
        string input = "(]";
        auto got = sol.isValid(input);
        if (got != false) {
            cerr << "FAIL case 3" << endl;
            return 1;
        }
    }
    // Case 4
    {
        string input = "([)]";
        auto got = sol.isValid(input);
        if (got != false) {
            cerr << "FAIL case 4" << endl;
            return 1;
        }
    }
    // Case 5
    {
        string input = "{[]}";
        auto got = sol.isValid(input);
        if (got != true) {
            cerr << "FAIL case 5" << endl;
            return 1;
        }
    }
    // Case 6
    {
        string input = "";
        auto got = sol.isValid(input);
        if (got != true) {
            cerr << "FAIL case 6" << endl;
            return 1;
        }
    }
    // Case 7
    {
        string input = "(";
        auto got = sol.isValid(input);
        if (got != false) {
            cerr << "FAIL case 7" << endl;
            return 1;
        }
    }
    // Case 8
    {
        string input = ")";
        auto got = sol.isValid(input);
        if (got != false) {
            cerr << "FAIL case 8" << endl;
            return 1;
        }
    }
    // Case 9
    {
        string input = "((";
        auto got = sol.isValid(input);
        if (got != false) {
            cerr << "FAIL case 9" << endl;
            return 1;
        }
    }
    // Case 10
    {
        string input = "))";
        auto got = sol.isValid(input);
        if (got != false) {
            cerr << "FAIL case 10" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
