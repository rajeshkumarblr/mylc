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
#include <vector>
using namespace std;

// @lc code=start
auto init = []() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  return 0;
}();
class Solution {
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
// @lc code=end

int main() {
  Solution sol;
  // Case 1
  {
    vector<vector<int>> heights = {{1, 2, 2, 3, 5},
                                   {3, 2, 3, 4, 4},
                                   {2, 4, 5, 3, 1},
                                   {6, 7, 1, 4, 5},
                                   {5, 1, 1, 2, 4}};
    vector<vector<int>> expected = {{0, 4}, {1, 3}, {1, 4}, {2, 2},
                                    {3, 0}, {3, 1}, {4, 0}};
    vector<vector<int>> result = sol.pacificAtlantic(heights);
    sort(expected.begin(), expected.end());
    sort(result.begin(), result.end());
    if (result == expected) {
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
