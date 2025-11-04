/*
 * @lc app=leetcode id=70 lang=golang
 *
 * [70] Climbing Stairs
 */

package main

// @lc code=start
func climbStairs(n int) int {
	// Base cases:
	// 1 step -> 1 way (just climb 1)
	// 2 steps -> 2 ways (1+1 or 2)
	if n <= 2 {
		return n
	}

	// Dynamic Programming approach:
	// To reach step i, we can come from step (i-1) or step (i-2)
	// So: ways[i] = ways[i-1] + ways[i-2] (Fibonacci sequence!)

	waysToReachPrevPrev := 1 // ways to reach step (i-2)
	waysToReachPrev := 2     // ways to reach step (i-1)

	// Calculate ways to reach each step from 3 to n
	for currentStep := 3; currentStep <= n; currentStep++ {
		waysToReachCurrent := waysToReachPrevPrev + waysToReachPrev

		// Slide the window forward
		waysToReachPrevPrev = waysToReachPrev
		waysToReachPrev = waysToReachCurrent
	}

	return waysToReachPrev // This holds ways to reach step n
}

// @lc code=end
