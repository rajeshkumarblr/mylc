package main

/*
 * @lc app=leetcode id=560 lang=golang
 *
 * [560] Subarray Sum Equals K
 */

// @lc code=start
func subarraySum(nums []int, k int) int {
	count := 0
	sum := 0
	prefixSums := make(map[int]int)
	prefixSums[0] = 1 // Empty subarray

	for _, num := range nums {
		sum += num
		if prefixSums[sum-k] > 0 {
			count += prefixSums[sum-k]
		}
		prefixSums[sum]++
	}

	return count
}

// @lc code=end
