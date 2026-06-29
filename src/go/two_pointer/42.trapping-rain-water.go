package main

/*
 * @lc app=leetcode id=42 lang=golang
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * Given n non-negative integers representing an elevation map where the
 * width of each bar is 1, compute how much water it can trap after raining.
 *
 * Example 1:
 * Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * Explanation: The above elevation map (black section) is represented by
 * array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue
 * section) are being trapped.
 *
 * Example 2:
 * Input: height = [4,2,0,3,2,5]
 * Output: 9
 *
 * Constraints:
 * - n == height.length
 * - 1 <= n <= 2 * 10^4
 * - 0 <= height[i] <= 10^5
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
