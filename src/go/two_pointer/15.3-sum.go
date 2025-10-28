package main

import "sort"

/*
 * @lc app=leetcode id=15 lang=golang
 *
 * [15] 3Sum
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
