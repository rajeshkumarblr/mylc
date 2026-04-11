package stack;

import common.*;

import java.util.*;

public class P20 {
    // @lc app=leetcode id=20 lang=java
    // @lc code=start
    public class Solution {
        public boolean isValid(String s) {
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
        // @lc code=end
    }
}