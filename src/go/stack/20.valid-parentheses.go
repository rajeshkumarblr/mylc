package main

/*
 * @lc app=leetcode id=20 lang=golang
 *
 * [20] Valid Parentheses
 */

// @lc code=start
func isValid(s string) bool {
	stack := []rune{}
	pairs := map[rune]rune{
		')': '(',
		'}': '{',
		']': '[',
	}

	for _, char := range s {
		if char == '(' || char == '{' || char == '[' {
			stack = append(stack, char)
		} else if char == ')' || char == '}' || char == ']' {
			if len(stack) == 0 {
				return false
			}
			top := stack[len(stack)-1]
			stack = stack[:len(stack)-1]
			if pairs[char] != top {
				return false
			}
		}
	}
	return len(stack) == 0
}

// @lc code=end
