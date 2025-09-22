#include <string>
#include <stack>
using namespace std;

/*
 * @lc app=leetcode id=20 lang=cpp
 *
 * [20] Valid Parentheses
 */

// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (auto ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                st.push(ch);
            } else if (ch == ')' || ch == '}' || ch == ']') {
                if (st.empty()) return false;  // No matching opening bracket
                char ctop = st.top();
                st.pop();
                if ((ch == ')' && ctop != '(') || 
                    (ch == '}' && ctop != '{') || 
                    (ch == ']' && ctop != '[')) {
                    return false;
                }
            }
        }
        return st.empty();  // All brackets should be matched
    }
};
// @lc code=end

bool isValid(std::string s) {
    Solution sol;
    return sol.isValid(s);
}

