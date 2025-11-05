/*
 * @lc app=leetcode id=213 lang=golang
 *
 * [213] House Robber II
 */

package main

// @lc code=start
func rob2(nums []int) int {
	n := len(nums)

	// Edge cases
	if n == 0 {
		return 0
	}
	if n == 1 {
		return nums[0]
	}

	// Two scenarios: exclude first OR exclude last house
	// Take maximum of both scenarios
	return max(robLinear(nums, 0, n-2), // Houses [0, n-2] (exclude last)
		robLinear(nums, 1, n-1)) // Houses [1, n-1] (exclude first)
}

// Linear house robber (same as House Robber I) with start/end indices
func robLinear(nums []int, start, end int) int {
	prev2 := 0 // Max money 2 houses ago
	prev1 := 0 // Max money 1 house ago

	for i := start; i <= end; i++ {
		current := max(prev1, prev2+nums[i])
		prev2 = prev1
		prev1 = current
	}

	return prev1
}

// @lc code=end
