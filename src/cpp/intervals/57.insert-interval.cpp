/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 *
 * Difficulty: Medium
 * Category: intervals
 * URL: https://leetcode.com/problems/insert-interval/
 *
 * Description:
 * You are given an array of non-overlapping intervals  intervals  where
 * intervals[i] = [start i , end i ]  represent the start and the end of the
 * i th   interval and  intervals  is sorted in ascending order by  start i  .
 * You are also given an interval  newInterval = [start, end]  that represents
 * the start and end of another interval.
 *  Insert  newInterval  into  intervals  such that  intervals  is still
 * sorted in ascending order by  start i   and  intervals  still does not have
 * any overlapping intervals (merge overlapping intervals if necessary).
 *  Return  intervals   after the insertion .
 *   Note  that you don't need to modify  intervals  in-place. You can make a
 * new array and return it.
 *   Example 1:
 *  Input:  intervals = [[1,3],[6,9]], newInterval = [2,5]
 *  Output:  [[1,5],[6,9]]
 *   Example 2:
 *  Input:  intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval =
 * [4,8]
 *  Output:  [[1,2],[3,10],[12,16]]
 *  Explanation:  Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 *   Constraints:
 *           0 <= intervals.length <= 10 4
 *           intervals[i].length == 2
 *           0 <= start i  <= end i  <= 10 5
 *           intervals  is sorted by  start i   in  ascending  order.
 *           newInterval.length == 2
 *           0 <= start <= end <= 10 5
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
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        
    }
};
// @lc code=end
