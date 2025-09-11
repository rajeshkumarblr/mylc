package main

/*
 * @lc app=leetcode id=11 lang=golang
 *
 * [11] Container With Most Water
 */

// @lc code=start
func maxArea(height []int) int {
	n := len(height)
	if n < 2 {
		return 0
	}
	l := 0
	r := n - 1
	maxarea := 0
	for l < r {
		maxarea = max(maxarea, min(height[l], height[r])*(r-l))
		if height[l] > height[r] {
			r--
		} else {
			l++
		}
	}
	return maxarea
}

// @lc code=end
