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
        vector<unordered_set<char>> col(9);
        vector<unordered_set<char>> row(9);
        vector<unordered_set<char>> square(9);

        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){

                char c = board[i][j];

                if (c == '.'){
                    continue;
                }

                int square_indx = (i/3)*3+j/3;

                if (row[i].count(c)  || col[j].count(c) || square[square_indx].count(c)){
                        return false;
                    }
                row[i].insert(c);
                col[j].insert(c);
                square[square_indx].insert(c);

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