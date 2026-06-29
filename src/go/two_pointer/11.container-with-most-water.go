package main

/*
 * @lc app=leetcode id=11 lang=golang
 *
 * [11] Container With Most Water
 *
 * https://leetcode.com/problems/container-with-most-water/description/
 *
 * You are given an integer array height of length n. There are n vertical
 * lines drawn such that the two endpoints of the ith line are (i, 0) and
 * (i, height[i]).
 *
 * Find two lines that, together with the x-axis, form a container, such
 * that the container contains the most water.
 *
 * Return the maximum amount of water a container can store.
 *
 * Notice that you may not slant the container.
 *
 * Example 1:
 * Input: height = [1,8,6,2,5,4,8,3,7]
 * Output: 49
 * Explanation: The above vertical lines are represented by array
 * [1,8,6,2,5,4,8,3,7]. In this case, the max area of water (blue section)
 * the container can contain is 49.
 *
 * Example 2:
 * Input: height = [1,1]
 * Output: 1
 *
 * Constraints:
 * - n == height.length
 * - 2 <= n <= 10^5
 * - 0 <= height[i] <= 10^4
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
