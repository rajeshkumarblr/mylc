#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
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
bool isValidSudoku(std::vector<std::vector<char>>& board) {
    Solution sol;
    return sol.isValidSudoku(board);
}