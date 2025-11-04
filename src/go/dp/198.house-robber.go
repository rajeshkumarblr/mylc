/*
 * @lc app=leetcode id=198 lang=golang
 *
 * [198] House Robber
 */

package main

// @lc code=start
func rob(nums []int) int {
	n := len(nums)
	
	// Edge cases
	if n == 0 {
		return 0
	}
	if n == 1 {
		return nums[0]
	}
	
	// O(1) space optimization: only track last 2 values
	prev2 := nums[0]                    // dp[i-2]
	prev1 := max(nums[0], nums[1])      // dp[i-1]
	
	for i := 2; i < n; i++ {
		current := max(prev1, prev2+nums[i])
		prev2 = prev1    // Slide window
		prev1 = current  // Slide window
	}
	
	return prev1
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
// @lc code=end