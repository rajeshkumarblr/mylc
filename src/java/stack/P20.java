package stack;

import common.*;

import java.util.*;

/*
 * @lc app=leetcode id=20 lang=java
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
 */

public class P20 {
    // @lc code=start
    public class Solution {
        public boolean isValid(String s) {
            Map<Character, Character> brackets = Map.of('(', ')', '{', '}', '[', ']');
            Stack<Character> stack = new Stack<>();
            for (char c : s.toCharArray()) {
                switch (c) {
                    case '[', '{', '(' -> stack.push(brackets.get(c));
                    case '}', ']', ')' -> {
                        if (stack.empty() || stack.pop() != c) {
                            return false;
                        }
                    }
                }
            }
            return stack.isEmpty(); // All brackets should be matched
        }

        public boolean isValid2(String s) {
            Map<Character, Character> brackets = Map.of(')', '(', '}', '{', ']', '[');
            Stack<Character> stack = new Stack<>();
            for (char c : s.toCharArray()) {
                if (brackets.containsKey(c)) {
                    if (stack.isEmpty() || stack.pop() != brackets.get(c)) {
                        return false;
                    }
                } else {
                    stack.push(c);
                }
            }
            return stack.isEmpty(); // All brackets should be matched
        }

        // @lc code=end
        public boolean isValidOrig(String s) {
            Stack<Character> stack = new Stack<>();
            for (char c : s.toCharArray()) {
                switch (c) {
                    case '(', '{', '[' -> stack.push(c);
                    case ')' -> {
                        if (stack.empty() || stack.pop() != '(')
                            return false;
                    }
                    case '}' -> {
                        if (stack.empty() || stack.pop() != '{')
                            return false;
                    }
                    case ']' -> {
                        if (stack.empty() || stack.pop() != '[')
                            return false;
                    }
                }
            }
            return stack.isEmpty(); // All brackets should be matched
        }
    }
}

// (2 * 3 / { 3 * 4} / [4 * 5])