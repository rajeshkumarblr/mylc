package main
package main

/*
 * @lc app=leetcode id=200 lang=golang
 *
 * [200] Number of Islands
 */

// @lc code=start
func numIslands(grid [][]byte) int {
	if len(grid) == 0 || len(grid[0]) == 0 {
		return 0
	}
	
	rows, cols := len(grid), len(grid[0])
	count := 0
	
	var dfs func(r, c int)
	dfs = func(r, c int) {
		if r < 0 || r >= rows || c < 0 || c >= cols || grid[r][c] != '1' {
			return
		}
		grid[r][c] = '0' // Mark as visited
		dfs(r+1, c)
		dfs(r-1, c)
		dfs(r, c+1)
		dfs(r, c-1)
	}
	
	for r := 0; r < rows; r++ {
		for c := 0; c < cols; c++ {
			if grid[r][c] == '1' {
				count++
				dfs(r, c)
			}
		}
	}
	
	return count
}
// @lc code=end