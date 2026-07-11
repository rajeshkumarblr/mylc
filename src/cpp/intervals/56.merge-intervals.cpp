/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * Difficulty: Medium
 * Category: intervals
 * URL: https://leetcode.com/problems/merge-intervals/
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
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
    }
};
// @lc code=end
