package main

/*
 * @lc app=leetcode id=42 lang=golang
 *
 * [42] Trapping Rain Water
 */

// @lc code=start
func trap(height []int) int {
	n := len(height)
	if n < 3 {
		return 0
	}
	l := 0
	r := n - 1
	leftMax := height[l]
	rightMax := height[r]
	trapped := 0
	for l < r {
		if leftMax < rightMax {
			l++
			leftMax = max(leftMax, height[l])
			trapped += leftMax - height[l]
		} else {
			r--
			rightMax = max(rightMax, height[r])
			trapped += rightMax - height[r]
		}
	}
	return trapped
}

// @lc code=end
