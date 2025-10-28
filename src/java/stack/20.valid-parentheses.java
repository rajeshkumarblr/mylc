import java.util.*;

class P20 {
    // @lc app=leetcode id=20 lang=java
    // @lc code=start
    public class Solution {
        public boolean isValid(String s) {
            Stack<Character> stack = new Stack<>();
            for (char c : s.toCharArray()) {
                if (c == '(' || c == '{' || c == '[') {
                    stack.push(c);
                } else if (c == ')' || c == '}' || c == ']') {
                    if (stack.isEmpty()) return false;  // No matching opening bracket
                    char top = stack.pop();
                    if ((c == ')' && top != '(') || 
                        (c == '}' && top != '{') || 
                        (c == ']' && top != '[')) {
                        return false;
                    }
                }
            }
            return stack.isEmpty();  // All brackets should be matched
        }
    }
    // @lc code=end
}