/*
 * @lc app=leetcode id=198 lang=golang
 *
 * [198] House Robber
 *
 * https://leetcode.com/problems/house-robber/description/
 *
 * You are a professional robber planning to rob houses along a street. Each
 * house has a certain amount of money stashed, the only constraint stopping
 * you from robbing each of them is that adjacent houses have security
 * systems connected and it will automatically contact the police if two
 * adjacent houses were broken into on the same night.
 *
 * Given an integer array nums representing the amount of money of each
 * house, return the maximum amount of money you can rob tonight without
 * alerting the police.
 *
 * Example 1:
 * Input: nums = [1,2,3,1]
 * Output: 4
 * Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
 * Total amount you can rob = 1 + 3 = 4.
 *
 * Example 2:
 * Input: nums = [2,7,9,3,1]
 * Output: 12
 * Explanation: Rob house 1 (money = 2), rob house 3 (money = 7) and rob house
 * 5 (money = 1).
 * Total amount you can rob = 2 + 7 + 1 = 12.
 *
 * Constraints:
 * - 1 <= nums.length <= 100
 * - 0 <= nums[i] <= 400
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
	prev2 := nums[0]               // dp[i-2]
	prev1 := max(nums[0], nums[1]) // dp[i-1]

	for i := 2; i < n; i++ {
		current := max(prev1, prev2+nums[i])
		prev2 = prev1   // Slide window
		prev1 = current // Slide window
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
