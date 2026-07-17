#include <set>
#include <cmath>
#include <map>
#include <iostream>
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

#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;


// @lc code=start
class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    cerr << "FAIL (No test cases)" << endl;
    return 1;
}
