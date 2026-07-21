#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <utility>
/*
 * @lc app=leetcode id=994 lang=cpp
 *
 * [994] Rotting Oranges
 *
 * Difficulty: Medium
 * Category: graphs
 * URL: https://leetcode.com/problems/rotting-oranges/
 *
 * Description:
 * You are given an  m x n   grid  where each cell can have one of three
 * values:
 *           0  representing an empty cell,
 *           1  representing a fresh orange, or
 *           2  representing a rotten orange.
 *  Every minute, any fresh orange that is  4-directionally adjacent  to a
 * rotten orange becomes rotten.
 *  Return  the minimum number of minutes that must elapse until no cell has a
 * fresh orange . If  this is impossible, return   -1 .
 *   Example 1:
 *  Input:  grid = [[2,1,1],[1,1,0],[0,1,1]]
 *  Output:  4
 *   Example 2:
 *  Input:  grid = [[2,1,1],[0,1,1],[1,0,1]]
 *  Output:  -1
 *  Explanation:  The orange in the bottom left corner (row 2, column 0) is
 * never rotten, because rotting only happens 4-directionally.
 *   Example 3:
 *  Input:  grid = [[0,2]]
 *  Output:  0
 *  Explanation:  Since there are already no fresh oranges at minute 0, the
 * answer is just 0.
 *   Constraints:
 *           m == grid.length
 *           n == grid[i].length
 *           1 <= m, n <= 10
 *           grid[i][j]  is  0 ,  1 , or  2 .
 */

#include <queue>
#include <vector>
using namespace std;

// @lc code=start
class Solution {
  enum State { EMPTY, FRESH, ROTTEN };

public:
  int orangesRotting(vector<vector<int>> &grid) {
    queue<pair<int, int>> q;
    int fresh = 0;
    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid[0].size(); c++) {
        if (grid[r][c] == 1) {
          fresh++;
        } else if (grid[r][c] == 2) {
          q.push({r, c});
        }
      }
    }

    if (q.size() == 0) {
      return (fresh == 0) ? 0 : -1;
    }

    int mins = 0;

    while (!q.empty()) {

      int size = q.size();
      for (int i = 0; i < size; i++) {
        auto &rc = q.front();
        int r = rc.first;
        int c = rc.second;
        q.pop();

        if (r > 0 && grid[r - 1][c] == 1) {
          grid[r - 1][c] = 2;
          fresh--;
          q.push({r - 1, c});
        }
        if (r < grid.size() - 1 && grid[r + 1][c] == 1) {
          grid[r + 1][c] = 2;
          fresh--;
          q.push({r + 1, c});
        }
        if (c > 0 && grid[r][c - 1] == 1) {
          grid[r][c - 1] = 2;
          fresh--;
          q.push({r, c - 1});
        }
        if (c < grid[r].size() - 1 && grid[r][c + 1] == 1) {
          grid[r][c + 1] = 2;
          fresh--;
          q.push({r, c + 1});
        }
      }
      if (q.size() > 0) {
        mins++;
      }
    }
    return (fresh == 0) ? mins : -1;
  }
};
// @lc code=end

int main() {
  Solution sol;

  // Case 1
  {
    vector<vector<int>> grid = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
    auto got = sol.orangesRotting(grid);
    if (got != 4) {
      cerr << "FAIL case 1: expected 4, got " << got << endl;
      return 1;
    }
  }

  // Case 2
  {
    vector<vector<int>> grid = {{2, 1, 1}, {0, 1, 1}, {1, 0, 1}};
    auto got = sol.orangesRotting(grid);
    if (got != -1) {
      cerr << "FAIL case 2: expected -1, got " << got << endl;
      return 1;
    }
  }

  // Case 3
  {
    vector<vector<int>> grid = {{0, 2}};
    auto got = sol.orangesRotting(grid);
    if (got != 0) {
      cerr << "FAIL case 3: expected 0, got " << got << endl;
      return 1;
    }
  }

  cout << "PASS" << endl;
  return 0;
}
