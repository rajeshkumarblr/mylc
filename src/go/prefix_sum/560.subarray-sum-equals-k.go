package main

/*
 * @lc app=leetcode id=560 lang=golang
 *
 * [560] Subarray Sum Equals K
 *
 * https://leetcode.com/problems/subarray-sum-equals-k/description/
 *
 * Given an array of integers nums and an integer k, return the total number
 * of continuous subarrays whose sum equals k.
 *
 * Example 1:
 * Input: nums = [1,1,1], k = 2
 * Output: 2
 *
 * Example 2:
 * Input: nums = [1,2,3], k = 3
 * Output: 2
 *
 * Constraints:
 * - 1 <= nums.length <= 2 * 10^4
 * - -1000 <= nums[i] <= 1000
 * - -10^7 <= k <= 10^7
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
