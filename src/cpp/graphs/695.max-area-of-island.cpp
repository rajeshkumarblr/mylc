#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <utility>
/*
 * @lc app=leetcode id=695 lang=cpp
 *
 * [695] Max Area of Island
 *
 * Difficulty: Medium
 * Category: graphs
 * URL: https://leetcode.com/problems/max-area-of-island/
 *
 * Description:
 * You are given an  m x n  binary matrix  grid . An island is a group of  1
 * 's (representing land) connected  4-directionally  (horizontal or
 * vertical.) You may assume all four edges of the grid are surrounded by
 * water.
 *  The  area  of an island is the number of cells with a value  1  in the
 * island.
 *  Return  the maximum  area  of an island in   grid . If there is no island,
 * return  0 .
 *   Example 1:
 *  Input:  grid = [[0,0,1,0,0,0,0,1,0,0,0,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0
 * ,1,1,0,1,0,0,0,0,0,0,0,0],[0,1,0,0,1,1,0,0,1,0,1,0,0],[0,1,0,0,1,1,0,0,1,1,
 * 1,0,0],[0,0,0,0,0,0,0,0,0,0,1,0,0],[0,0,0,0,0,0,0,1,1,1,0,0,0],[0,0,0,0,0,0
 * ,0,1,1,0,0,0,0]]
 *  Output:  6
 *  Explanation:  The answer is not 11, because the island must be connected
 * 4-directionally.
 *   Example 2:
 *  Input:  grid = [[0,0,0,0,0,0,0,0]]
 *  Output:  0
 *   Constraints:
 *           m == grid.length
 *           n == grid[i].length
 *           1 <= m, n <= 50
 *           grid[i][j]  is either  0  or  1 .
 */

#include <algorithm>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution_dfs {
public:
  int dfs(vector<vector<int>> &grid, int r, int c) {
    if (r < 0 || r >= grid.size()) {
      return 0;
    }
    if (c < 0 || c >= grid[r].size()) {
      return 0;
    }

    if (grid[r][c] == 0) {
      return 0;
    }

    grid[r][c] = 0;
    return dfs(grid, r - 1, c) + dfs(grid, r, c - 1) + dfs(grid, r + 1, c) +
           dfs(grid, r, c + 1) + 1;
  }

  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int maxArea = 0;
    for (int r = 0; r < grid.size(); r++) {
      for (int c = 0; c < grid[r].size(); c++) {
        if (grid[r][c] == 1) {
          maxArea = max(maxArea, dfs(grid, r, c));
        }
      }
    }
    return maxArea;
  }
};

// @lc code=start
class Solution {
public:
  int maxAreaOfIsland(vector<vector<int>> &grid) {
    int maxArea = 0;
    int m = grid.size();
    int n = grid[0].size();

    // 4 directions: up, down, left, right
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

    for (int r = 0; r < m; r++) {
      for (int c = 0; c < n; c++) {
        if (grid[r][c] == 1) {
          int area = 0;
          stack<pair<int, int>> st;
          st.push({r, c});

          // Mark visited immediately when adding to stack
          grid[r][c] = 0;

          while (!st.empty()) {
            auto [curr_r, curr_c] = st.top();
            st.pop();
            area++;

            // Explore 4 neighbors
            for (auto &d : dirs) {
              int nr = curr_r + d[0];
              int nc = curr_c + d[1];

              if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc] == 1) {
                st.push({nr, nc});
                grid[nr][nc] = 0; // Mark visited so we don't push duplicates
              }
            }
          }
          maxArea = max(maxArea, area);
        }
      }
    }
    return maxArea;
  }
};
// @lc code=end
// @lc code=end

#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main() {
  try {
    json j = json::parse(R"raw({
      "cases": [
        {
          "grid": [
            [0,0,1,0,0,0,0,1,0,0,0,0,0],
            [0,0,0,0,0,0,0,1,1,1,0,0,0],
            [0,1,1,0,1,0,0,0,0,0,0,0,0],
            [0,1,0,0,1,1,0,0,1,0,1,0,0],
            [0,1,0,0,1,1,0,0,1,1,1,0,0],
            [0,0,0,0,0,0,0,0,0,0,1,0,0],
            [0,0,0,0,0,0,0,1,1,1,0,0,0],
            [0,0,0,0,0,0,0,1,1,0,0,0,0]
          ],
          "expected": 6
        },
        {
          "grid": [
            [0,0,0,0,0,0,0,0]
          ],
          "expected": 0
        }
      ]
    })raw");

    for (auto &tc : j.at("cases")) {
      vector<vector<int>> grid = tc.at("grid").get<vector<vector<int>>>();
      int expected = tc.at("expected").get<int>();

      Solution sol;
      int result = sol.maxAreaOfIsland(grid);

      // We pass a copy of the grid to the iterative solution because the first
      // solution destroys it
      vector<vector<int>> grid_copy = tc.at("grid").get<vector<vector<int>>>();
      Solution_iteration sol_iter;
      int iter_result = sol_iter.maxAreaOfIsland(grid_copy);

      if (result != expected || iter_result != expected) {
        cerr << "FAIL for input" << endl;
        cerr << "Expected: " << expected << ", Recursive Got: " << result
             << ", Iterative Got: " << iter_result << endl;
        return 1;
      }
    }
    cout << "PASS" << endl;
    return 0;
  } catch (const exception &e) {
    cerr << "Exception: " << e.what() << endl;
    return 1;
  }
}
