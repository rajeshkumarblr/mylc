package main

/*
 * @lc app=leetcode id=33 lang=golang
 *
 * [33] Search in Rotated Sorted Array
 * https://leetcode.com/problems/search-in-rotated-sorted-array/
 */

// @lc code=start
func search_33(nums []int, target int) int {
	l := 0
	r := len(nums)
	for l < r {
		m := (l + r) / 2
		if nums[m] == target {
			return m
		}
		if nums[l] <= nums[m] { // Left half is sorted
			if nums[l] <= target && target < nums[m] {
				r = m
			} else {
				l = m + 1
			}
		} else { // Right half is sorted
			if nums[m] < target && target <= nums[r-1] {
				l = m + 1
			} else {
				r = m
			}
		}
	}
	return -1
}

// @lc code=end
