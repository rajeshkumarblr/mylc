package stack;

import common.*;

import java.util.*;

public class P20 {
    // @lc app=leetcode id=20 lang=java
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