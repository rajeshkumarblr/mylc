package main

/*
 * @lc app=leetcode id=1 lang=golang
 *
 * [1] Two Sum
 */

// @lc code=start
func twoSum(nums []int, target int) []int {
	mymap := make(map[int]int)
	for i := 0; i < len(nums); i++ {
		num := nums[i]
		if idx, found := mymap[num]; found {
			return []int{idx, i}
		}
		mymap[target-num] = i
	}
	return []int{}
}

// @lc code=end
