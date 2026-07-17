#include <queue>
#include <unordered_map>
#include <set>
#include <list>
#include <algorithm>
#include <cmath>
#include <map>
#include <stack>
#include <iostream>
#include <utility>
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to
 * be validated according to the following rules:
 *
 * 1. Each row must contain the digits 1-9 without repetition.
 * 2. Each column must contain the digits 1-9 without repetition.
 * 3. Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9
 *    without repetition.
 *
 * Note:
 * - A Sudoku board (partially filled) could be valid but is not necessarily
 *   solvable.
 * - Only the filled cells need to be validated according to the mentioned
 *   rules.
 *
 * Example 1:
 * Input: board =
 * [["5","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".","8",".",".",".","7","9"]]
 * Output: true
 *
 * Example 2:
 * Input: board =
 * [["8","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".","8",".",".",".","7","9"]]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 *
 * Constraints:
 * - board.length == 9
 * - board[i].length == 9
 * - board[i][j] is a digit 1-9 or '.'.
 *
 * Description:
 * Determine if a  9 x 9  Sudoku board is valid. Only the filled cells need to
 * be validated  according to the following rules :
 *          Each row must contain the digits  1-9  without repetition.
 *          Each column must contain the digits  1-9  without repetition.
 *          Each of the nine  3 x 3  sub-boxes of the grid must contain the
 * digits  1-9  without repetition.
 *   Note:
 *          A Sudoku board (partially filled) could be valid but is not
 * necessarily solvable.
 *          Only the filled cells need to be validated according to the
 * mentioned rules.
 *   Example 1:
 *  Input:  board =
 * [["5","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 *  Output:  true
 *   Example 2:
 *  Input:  board =
 * [["8","3",".",".","7",".",".",".","."]
 * ,["6",".",".","1","9","5",".",".","."]
 * ,[".","9","8",".",".",".",".","6","."]
 * ,["8",".",".",".","6",".",".",".","3"]
 * ,["4",".",".","8",".","3",".",".","1"]
 * ,["7",".",".",".","2",".",".",".","6"]
 * ,[".","6",".",".",".",".","2","8","."]
 * ,[".",".",".","4","1","9",".",".","5"]
 * ,[".",".",".",".","8",".",".","7","9"]]
 *  Output:  false
 *  Explanation:  Same as Example 1, except with the  5  in the top left
 * corner being modified to  8 . Since there are two 8's in the top left 3x3
 * sub-box, it is invalid.
 *   Constraints:
 *           board.length == 9
 *           board[i].length == 9
 *           board[i][j]  is a digit  1-9  or  '.' .
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // Use bitsets for maximum efficiency
        // Each int represents 9 digits as bits
        int rows[9] = {0};
        int cols[9] = {0}; 
        int boxes[9] = {0};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;

                int bit = 1 << (c - '1'); // Create bit mask for digit
                int box = (i / 3) * 3 + (j / 3);

                // Check if bit is already set (duplicate found)
                if ((rows[i] & bit) || (cols[j] & bit) || (boxes[box] & bit))
                    return false;

                // Set the bit
                rows[i] |= bit;
                cols[j] |= bit;
                boxes[box] |= bit;
            }
        }
        return true;
    }
};
// @lc code=end
















// Non-LeetCode wrapper for harness





int main() {
    Solution sol;
    // Case 1
    {
        vector<vector<char>> board = {{'5', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
        auto got = sol.isValidSudoku(board);
        if (got != true) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<vector<char>> board = {{'8', '3', '.', '.', '7', '.', '.', '.', '.'}, {'6', '.', '.', '1', '9', '5', '.', '.', '.'}, {'.', '9', '8', '.', '.', '.', '.', '6', '.'}, {'8', '.', '.', '.', '6', '.', '.', '.', '3'}, {'4', '.', '.', '8', '.', '3', '.', '.', '1'}, {'7', '.', '.', '.', '2', '.', '.', '.', '6'}, {'.', '6', '.', '.', '.', '.', '2', '8', '.'}, {'.', '.', '.', '4', '1', '9', '.', '.', '5'}, {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
        auto got = sol.isValidSudoku(board);
        if (got != false) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
