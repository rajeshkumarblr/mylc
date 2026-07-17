#include <set>
#include <cmath>
#include <map>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * Difficulty: Medium
 * Category: binary_search
 * URL: https://leetcode.com/problems/search-a-2d-matrix/
 *
 * Description:
 * You are given an  m x n  integer matrix  matrix  with the following two
 * properties:
 *          Each row is sorted in non-decreasing order.
 *          The first integer of each row is greater than the last integer of
 * the previous row.
 *  Given an integer  target , return  true   if   target   is in   matrix
 * or   false   otherwise .
 *  You must write a solution in  O(log(m * n))  time complexity.
 *   Example 1:
 *  Input:  matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
 *  Output:  true
 *   Example 2:
 *  Input:  matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
 *  Output:  false
 *   Constraints:
 *           m == matrix.length
 *           n == matrix[i].length
 *           1 <= m, n <= 100
 *           -10 4  <= matrix[i][j], target <= 10 4
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


// @lc code=start
class Solution {
public:
  bool searchMatrix(vector<vector<int>> &matrix, int target) {
    int l = 0;
    int m = matrix.size();
    int n = matrix[0].size();
    int r = m * n - 1;
    while (l < r) {
      int mid = (l + r) / 2;
      int midRow = mid / n;
      int midCol = mid % n;
      if (target < matrix[midRow][midCol]) {
        r = mid - 1;
      } else if (matrix[midRow][midCol] < target) {
        l = mid + 1;
      } else {
        return true;
      }
    }
    if (matrix[l / n][l % n] == target) {
      return true;
    }
    return false;
  }
};
// @lc code=end
















// Non-LeetCode wrapper for harness





int main() {
    Solution sol;
    // Case 1
    {
        vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
        int target = 3;
        auto got = sol.searchMatrix(matrix, target);
        if (got != true) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
        int target = 13;
        auto got = sol.searchMatrix(matrix, target);
        if (got != false) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
