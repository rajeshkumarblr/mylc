/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * Given an array of intervals where intervals[i] = [start_i, end_i], merge all
 * overlapping intervals, and return an array of the non-overlapping intervals
 * that cover all the intervals in the input.
 *
 * Description:
 * Given an array of  intervals  where  intervals[i] = [start i , end i ] ,
 * merge all overlapping intervals, and return  an array of the non-
 * overlapping intervals that cover all the intervals in the input .
 *   Example 1:
 *  Input:  intervals = [[1,3],[2,6],[8,10],[15,18]]
 *  Output:  [[1,6],[8,10],[15,18]]
 *  Explanation:  Since intervals [1,3] and [2,6] overlap, merge them into
 * [1,6].
 *   Example 2:
 *  Input:  intervals = [[1,4],[4,5]]
 *  Output:  [[1,5]]
 *  Explanation:  Intervals [1,4] and [4,5] are considered overlapping.
 *   Example 3:
 *  Input:  intervals = [[4,7],[1,4]]
 *  Output:  [[1,7]]
 *  Explanation:  Intervals [1,4] and [4,7] are considered overlapping.
 *   Constraints:
 *           1 <= intervals.length <= 10 4
 *           intervals[i].length == 2
 *           0 <= start i  <= end i  <= 10 4
 */

#include "../lc_test_utils.h"
#include <algorithm>
#include <vector>

using namespace std;

// @lc code=start
class SolutionCopy {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    vector<vector<int>> result;
    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });
    for (const auto &currentInterval : intervals) {
      if (result.empty() || currentInterval[0] > result.back()[1]) {
        result.push_back(currentInterval);
      } else {
        result.back()[1] = max(result.back()[1], currentInterval[1]);
      }
    }
    return result;
  }
};

class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>> &intervals) {
    if (intervals.empty())
      return {};

    sort(
        intervals.begin(), intervals.end(),
        [](const vector<int> &a, const vector<int> &b) { return a[0] < b[0]; });

    size_t writeIdx = 0;
    for (size_t i = 1; i < intervals.size(); ++i) {
      if (intervals[writeIdx][1] >= intervals[i][0]) {
        intervals[writeIdx][1] = max(intervals[writeIdx][1], intervals[i][1]);
      } else {
        writeIdx++;
        if (writeIdx != i) {
          intervals[writeIdx] = std::move(intervals[i]);
        }
      }
    }

    intervals.resize(writeIdx + 1);
    return intervals;
  }
};
// @lc code=end

vector<vector<int>> mergeIntervals(vector<vector<int>> &intervals) {
  Solution sol;
  return sol.merge(intervals);
}
