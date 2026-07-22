#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <utility>
/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 *
 * Difficulty: Medium
 * Category: graphs
 * URL: https://leetcode.com/problems/surrounded-regions/
 *
 * Description:
 * You are given an  m x n  matrix  board  containing  letters   'X'  and  'O'
 * ,  capture regions  that are  surrounded :
 *           Connect : A cell is connected to adjacent cells horizontally or
 * vertically.
 *           Region : To form a region  connect every   'O'  cell.
 *           Surround : A region is surrounded if none of the  'O'  cells in
 * that region are on the edge of the board. Such regions are  completely
 * enclosed  by  'X'  cells.
 *  To capture a  surrounded region , replace all  'O' s with  'X' s  in-place
 * within the original board. You do not need to return anything.
 *   Example 1:
 *   Input:   board =
 * [["X","X","X","X"],["X","O","O","X"],["X","X","O","X"],["X","O","X","X"]]
 *   Output:
 * [["X","X","X","X"],["X","X","X","X"],["X","X","X","X"],["X","O","X","X"]]
 *   Explanation:
 *  In the above diagram, the bottom region is not captured because it is on
 * the edge of the board and cannot be surrounded.
 *   Example 2:
 *   Input:   board = [["X"]]
 *   Output:   [["X"]]
 *   Constraints:
 *           m == board.length
 *           n == board[i].length
 *           1 <= m, n <= 200
 *           board[i][j]  is  'X'  or  'O' .
 */

#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  void dfs(vector<vector<char>> &board, int i, int j) {

    if (i < 0 || i >= board.size()) {
      return;
    }

    if (j < 0 || j >= board[i].size()) {
      return;
    }

    if (board[i][j] != 'O') {
      return;
    }

    board[i][j] = 'T';
    dfs(board, i, j + 1);
    dfs(board, i, j - 1);
    dfs(board, i + 1, j);
    dfs(board, i - 1, j);
  }

  void solve(vector<vector<char>> &board) {

    if (board.empty() || board[0].empty()) return;
    int rows = board.size();
    int cols = board[0].size();

    // 1. First and last row
    for (int j = 0; j < cols; j++) {
      if (board[0][j] == 'O') dfs(board, 0, j);
      if (rows > 1 && board[rows - 1][j] == 'O') dfs(board, rows - 1, j);
    }

    // 2. First and last column
    for (int i = 0; i < rows; i++) {
      if (board[i][0] == 'O') dfs(board, i, 0);
      if (cols > 1 && board[i][cols - 1] == 'O') dfs(board, i, cols - 1);
    }

    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (board[i][j] == 'O')
          board[i][j] = 'X';
      }
    }
    for (int i = 0; i < board.size(); i++) {
      for (int j = 0; j < board[i].size(); j++) {
        if (board[i][j] == 'T')
          board[i][j] = 'O';
      }
    }
  }
};
// @lc code=end

int main() {
  Solution sol;
  // Case 1
  {
    vector<vector<char>> board = {{'X', 'X', 'X', 'X'},
                                  {'X', 'O', 'O', 'X'},
                                  {'X', 'X', 'O', 'X'},
                                  {'X', 'O', 'X', 'X'}};
    vector<vector<char>> expected = {{'X', 'X', 'X', 'X'},
                                     {'X', 'X', 'X', 'X'},
                                     {'X', 'X', 'X', 'X'},
                                     {'X', 'O', 'X', 'X'}};
    sol.solve(board);
    if (board != expected) {
      cerr << "FAIL case 1" << endl;
      return 1;
    }
  }
  // Case 2
  {
    vector<vector<char>> board = {{'X'}};
    vector<vector<char>> expected = {{'X'}};
    sol.solve(board);
    if (board != expected) {
      cerr << "FAIL case 2" << endl;
      return 1;
    }
  }
  cout << "PASS" << endl;
  return 0;
}
