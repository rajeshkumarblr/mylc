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

bool isValid(std::string s) {
  Solution sol;
  return sol.isValid(s);
}
