#include <cmath>
#include <iostream>
#include <map>
#include <set>
#include <utility>
/*
 * @lc app=leetcode id=417 lang=cpp
 *
 * [417] Pacific Atlantic Water Flow
 *
 * Difficulty: Medium
 * Category: graphs
 * URL: https://leetcode.com/problems/pacific-atlantic-water-flow/
 *
 * Description:
 * There is an  m x n  rectangular island that borders both the  Pacific Ocean
 * and  Atlantic Ocean . The  Pacific Ocean  touches the island's left and top
 * edges, and the  Atlantic Ocean  touches the island's right and bottom
 * edges.
 *  The island is partitioned into a grid of square cells. You are given an  m
 * x n  integer matrix  heights  where  heights[r][c]  represents the  height
 * above sea level  of the cell at coordinate  (r, c) .
 *  The island receives a lot of rain, and the rain water can flow to
 * neighboring cells directly north, south, east, and west if the neighboring
 * cell's height is  less than or equal to  the current cell's height. Water
 * can flow from any cell adjacent to an ocean into the ocean.
 *  Return  a  2D list  of grid coordinates   result   where   result[i] = [r
 * i , c i ]   denotes that rain water can flow from cell   (r i , c i )   to
 * both  the Pacific and Atlantic oceans .
 *   Example 1:
 *  Input:  heights =
 * [[1,2,2,3,5],[3,2,3,4,4],[2,4,5,3,1],[6,7,1,4,5],[5,1,1,2,4]]
 *  Output:  [[0,4],[1,3],[1,4],[2,2],[3,0],[3,1],[4,0]]
 *  Explanation:  The following cells can flow to the Pacific and Atlantic
 * oceans, as shown below:
 * [0,4]: [0,4] -> Pacific Ocean
 *        [0,4] -> Atlantic Ocean
 * [1,3]: [1,3] -> [0,3] -> Pacific Ocean
 *        [1,3] -> [1,4] -> Atlantic Ocean
 * [1,4]: [1,4] -> [1,3] -> [0,3] -> Pacific Ocean
 *        [1,4] -> Atlantic Ocean
 * [2,2]: [2,2] -> [1,2] -> [0,2] -> Pacific Ocean
 *        [2,2] -> [2,3] -> [2,4] -> Atlantic Ocean
 * [3,0]: [3,0] -> Pacific Ocean
 *        [3,0] -> [4,0] -> Atlantic Ocean
 * [3,1]: [3,1] -> [3,0] -> Pacific Ocean
 *        [3,1] -> [4,1] -> Atlantic Ocean
 * [4,0]: [4,0] -> Pacific Ocean
 *        [4,0] -> Atlantic Ocean
 * Note that there are other possible paths for these cells to flow to the
 * Pacific and Atlantic oceans.
 *   Example 2:
 *  Input:  heights = [[1]]
 *  Output:  [[0,0]]
 *  Explanation:  The water can flow from the only cell to the Pacific and
 * Atlantic oceans.
 *   Constraints:
 *           m == heights.length
 *           n == heights[r].length
 *           1 <= m, n <= 200
 *           0 <= heights[r][c] <= 10 5
 */

#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

auto init = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();
class Solution_DFS {
public:
  void dfs_pacific(vector<vector<int>> &heights, vector<vector<char>> &flow,
                   int r, int c, int prevHeight) {
    if (r < 0 || r == heights.size()) {
      return;
    }
    if (c < 0 || c == heights[r].size()) {
      return;
    }
    if (flow[r][c] != 0) {
      return;
    }
    int currHeight = heights[r][c];
    if (currHeight >= prevHeight) {
      flow[r][c] = 1;
      dfs_pacific(heights, flow, r, c + 1, currHeight);
      dfs_pacific(heights, flow, r, c - 1, currHeight);
      dfs_pacific(heights, flow, r + 1, c, currHeight);
      dfs_pacific(heights, flow, r - 1, c, currHeight);
    }
  }

  void dfs_atlantic(vector<vector<int>> &heights, vector<vector<char>> &flow,
                    vector<vector<int>> &res, int r, int c, int prevHeight) {
    if (r < 0 || r == heights.size()) {
      return;
    }
    if (c < 0 || c == heights[r].size()) {
      return;
    }

    // check if visited this node aleady.
    if (flow[r][c] == 2 || flow[r][c] == 3) {
      return;
    }

    int currHeight = heights[r][c];
    if (currHeight >= prevHeight) {
      if (flow[r][c] == 0) {
        flow[r][c] = 2;
      } else if (flow[r][c] == 1) {
        flow[r][c] = 3;
        res.push_back({r, c});
      }
      dfs_atlantic(heights, flow, res, r, c + 1, currHeight);
      dfs_atlantic(heights, flow, res, r, c - 1, currHeight);
      dfs_atlantic(heights, flow, res, r + 1, c, currHeight);
      dfs_atlantic(heights, flow, res, r - 1, c, currHeight);
    }
  }

  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int rows = heights.size();
    int cols = heights[0].size();
    vector<vector<char>> flow(rows, vector<char>(cols, 0));

    // process the pacific ocen edges first top, left.
    // top edge:
    for (int c = 0; c < cols; c++) {
      dfs_pacific(heights, flow, 0, c, 0);
    }

    // left edge
    for (int r = 0; r < rows; r++) {
      dfs_pacific(heights, flow, r, 0, 0);
    }

    vector<vector<int>> res;
    // process the atlantic ocen edges right, bottom.
    // bottom edge:
    for (int c = 0; c < cols; c++) {
      dfs_atlantic(heights, flow, res, rows - 1, c, 0);
    }
    // right edge
    for (int r = 0; r < rows; r++) {
      dfs_atlantic(heights, flow, res, r, cols - 1, 0);
    }

    return res;
  }
};

// @lc code=start
class Solution {
public:
  vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights) {
    int rows = heights.size();
    if (rows == 0)
      return {};
    int cols = heights[0].size();

    // State machine matrix:
    // 0 = unvisited, 1 = Pacific, 2 = Atlantic, 3 = Both
    vector<vector<char>> flow(rows, vector<char>(cols, 0));

    // Queues to hold the coordinates for our BFS traversal
    queue<pair<int, int>> pacificQ;
    queue<pair<int, int>> atlanticQ;

    // STEP 1: Initialize the Pacific queue with the top and left border cells.
    for (int r = 0; r < rows; r++) {
      pacificQ.push({r, 0});
      flow[r][0] = 1; // Mark left edge as reachable by Pacific immediately
    }
    for (int c = 0; c < cols; c++) {
      // Avoid double-processing the top-left corner (0,0) which was added in
      // the previous loop
      if (flow[0][c] == 0) {
        pacificQ.push({0, c});
        flow[0][c] = 1; // Mark top edge as reachable by Pacific
      }
    }

    int dirs[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

    // STEP 2: Run BFS from the Pacific Ocean (top & left edges)
    // We travel inwards (uphill) and mark everything we can reach as 1.
    while (!pacificQ.empty()) {
      auto [r, c] = pacificQ.front();
      pacificQ.pop();
      for (auto &d : dirs) {
        int nr = r + d[0], nc = c + d[1];
        // Only explore valid neighbors that haven't been visited by Pacific
        // (flow == 0) and are at a higher or equal elevation (water can flow
        // down to us)
        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && flow[nr][nc] == 0 &&
            heights[nr][nc] >= heights[r][c]) {
          flow[nr][nc] = 1;
          pacificQ.push({nr, nc});
        }
      }
    }

    vector<vector<int>> res;

    // STEP 3: Initialize the Atlantic queue with the bottom and right border
    // cells. We check if they were ALREADY reached by the Pacific. If so, they
    // are part of the result!

    // Process right edge
    for (int r = 0; r < rows; r++) {
      if (flow[r][cols - 1] == 0) {
        flow[r][cols - 1] = 2;
        atlanticQ.push({r, cols - 1});
      } else if (flow[r][cols - 1] == 1) {
        flow[r][cols - 1] = 3;
        res.push_back({r, cols - 1});
        atlanticQ.push({r, cols - 1});
      }
    }

    // Process bottom edge
    for (int c = 0; c < cols; c++) {
      // Avoid double-processing the bottom-right corner if it was processed in
      // the right edge loop
      if (flow[rows - 1][c] == 0) {
        flow[rows - 1][c] = 2;
        atlanticQ.push({rows - 1, c});
      } else if (flow[rows - 1][c] == 1) {
        flow[rows - 1][c] = 3;
        res.push_back({rows - 1, c});
        atlanticQ.push({rows - 1, c});
      }
    }

    // STEP 4: Run BFS from the Atlantic Ocean (bottom & right edges)
    // We travel inwards (uphill) and update the state matrix.
    while (!atlanticQ.empty()) {
      auto [r, c] = atlanticQ.front();
      atlanticQ.pop();
      for (auto &d : dirs) {
        int nr = r + d[0], nc = c + d[1];

        // Ensure neighbor is valid and water can flow downhill to our current
        // cell
        if (nr >= 0 && nr < rows && nc >= 0 && nc < cols &&
            heights[nr][nc] >= heights[r][c]) {

          if (flow[nr][nc] == 0) {
            // Neighbor was completely unvisited, now it's reached by Atlantic
            flow[nr][nc] = 2;
            atlanticQ.push({nr, nc});
          } else if (flow[nr][nc] == 1) {
            // Neighbor was reached by Pacific earlier, now reached by Atlantic
            // too!
            flow[nr][nc] = 3;
            res.push_back({nr, nc});
            atlanticQ.push({nr, nc});
          }
        }
      }
    }

    return res;
  }
};
// @lc code=end

int main() {
  Solution sol;
  // Solution_BFS sol_bfs;
  //  Case 1
  {
    vector<vector<int>> heights = {{1, 2, 2, 3, 5},
                                   {3, 2, 3, 4, 4},
                                   {2, 4, 5, 3, 1},
                                   {6, 7, 1, 4, 5},
                                   {5, 1, 1, 2, 4}};
    vector<vector<int>> expected = {{0, 4}, {1, 3}, {1, 4}, {2, 2},
                                    {3, 0}, {3, 1}, {4, 0}};
    vector<vector<int>> result = sol.pacificAtlantic(heights);
    // vector<vector<int>> result_bfs = sol_bfs.pacificAtlantic(heights);
    sort(expected.begin(), expected.end());
    sort(result.begin(), result.end());
    // sort(result_bfs.begin(), result_bfs.end());
    if (result == expected && result == expected) {
      cout << "Case 1 Passed" << endl;
    } else {
      cerr << "Case 1 Failed" << endl;
      return 1;
    }
  }
  // Case 2
  {
    vector<vector<int>> heights = {{1}};
    vector<vector<int>> expected = {{0, 0}};
    vector<vector<int>> result = sol.pacificAtlantic(heights);
    sort(expected.begin(), expected.end());
    sort(result.begin(), result.end());
    if (result == expected) {
      cout << "Case 2 Passed" << endl;
    } else {
      cerr << "Case 2 Failed" << endl;
      return 1;
    }
  }

  cout << "All cases passed!" << endl;
  return 0;
}
