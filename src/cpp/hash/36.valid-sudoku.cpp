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
        unordered_set<string> seen;
        
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.') {
                    char ch = board[i][j];
                    string row = "row" + to_string(i) + ch;
                    string col = "col" + to_string(j) + ch;
                    string box = "box" + to_string(i/3) + to_string(j/3) + ch;
                    
                    if (seen.count(row) || seen.count(col) || seen.count(box)) {
                        return false;
                    }
                    
                    seen.insert(row);
                    seen.insert(col);
                    seen.insert(box);
                }
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