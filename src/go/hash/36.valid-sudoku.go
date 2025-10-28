package main

/*
 * @lc app=leetcode id=36 lang=golang
 *
 * [36] Valid Sudoku
 */

// @lc code=start
func isValidSudoku(board [][]byte) bool {
	rows := make([]map[byte]bool, 9)
	cols := make([]map[byte]bool, 9)
	boxes := make([]map[byte]bool, 9)

	for i := 0; i < 9; i++ {
		rows[i] = make(map[byte]bool)
		cols[i] = make(map[byte]bool)
		boxes[i] = make(map[byte]bool)
	}

	for r := 0; r < 9; r++ {
		for c := 0; c < 9; c++ {
			if board[r][c] != '.' {
				val := board[r][c]
				boxIndex := (r/3)*3 + c/3

				if rows[r][val] || cols[c][val] || boxes[boxIndex][val] {
					return false
				}

				rows[r][val] = true
				cols[c][val] = true
				boxes[boxIndex][val] = true
			}
		}
	}

	return true
}

// @lc code=end
