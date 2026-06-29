package main

import "sort"

/*
 * @lc app=leetcode id=15 lang=golang
 *
 * [15] 3Sum
 *
 * https://leetcode.com/problems/3sum/description/
 *
 * Given an integer array nums, return all the triplets [nums[i], nums[j],
 * nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] +
 * nums[k] == 0.
 *
 * Notice that the solution set must not contain duplicate triplets.
 *
 * Example 1:
 * Input: nums = [-1,0,1,2,-1,-4]
 * Output: [[-1,-1,2],[-1,0,1]]
 * Explanation:
 * nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
 * nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
 * nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
 * The distinct triplets are [-1,0,1] and [-1,-1,2].
 * Notice that the order of the output and the order of the triplets does not matter.
 *
 * Example 2:
 * Input: nums = [0,1,1]
 * Output: []
 * Explanation: The only possible triplet does not sum up to 0.
 *
 * Example 3:
 * Input: nums = [0,0,0]
 * Output: [[0,0,0]]
 * Explanation: The only possible triplet sums up to 0.
 *
 * Constraints:
 * - 3 <= nums.length <= 3000
 * - -10^5 <= nums[i] <= 10^5
 */

// @lc code=start
func threeSum(nums []int) [][]int {
	res := [][]int{}
	sort.Ints(nums)
	n := len(nums)

	for i := 0; i < n; i++ {
		// since we have already sorted the array,
		// anything more than 0 means, whatever follows this, will
		// be positive numbers, so adding them is not going to result
		// in zero, only more than that. so stop here.
		if nums[i] > 0 {
			break
		}

		// if this is a duplicate of previous element, then continue.
		if i > 0 && nums[i] == nums[i-1] {
			continue
		}

		l, r := i+1, n-1

		for l < r {
			sum := nums[i] + nums[l] + nums[r]

			if sum > 0 {
				// if sum is greater than 0, it means the current right is
				// more than what we want, so reduce it by decrementing r.
				r--
			} else if sum < 0 {
				// if sum is less than 0, it means the current left is
				// less than what we want, so increase it by incrementing l.
				l++
			} else {
				// we found the triplet that adds up to zero. so add it to res.
				res = append(res, []int{nums[i], nums[l], nums[r]})

				l++
				r--

				for l < r && nums[l] == nums[l-1] {
					l++
				}
				for l < r && nums[r] == nums[r+1] {
					r--
				}
			}
		}
	}

	return res
}

// @lc code=end
