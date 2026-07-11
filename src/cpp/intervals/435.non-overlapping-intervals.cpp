/*
 * @lc app=leetcode id=435 lang=cpp
 *
 * [435] Non Overlapping Intervals
 *
 * Difficulty: Medium
 * Category: intervals
 * URL: https://leetcode.com/problems/non-overlapping-intervals/
 *
 * Description:
 * Given an array of intervals  intervals  where  intervals[i] = [start i ,
 * end i ] , return  the minimum number of intervals you need to remove to
 * make the rest of the intervals non-overlapping .
 *   Note  that intervals which only touch at a point are  non-overlapping .
 * For example,  [1, 2]  and  [2, 3]  are non-overlapping.
 *   Example 1:
 *  Input:  intervals = [[1,2],[2,3],[3,4],[1,3]]
 *  Output:  1
 *  Explanation:  [1,3] can be removed and the rest of the intervals are non-
 * overlapping.
 *   Example 2:
 *  Input:  intervals = [[1,2],[1,2],[1,2]]
 *  Output:  2
 *  Explanation:  You need to remove two [1,2] to make the rest of the
 * intervals non-overlapping.
 *   Example 3:
 *  Input:  intervals = [[1,2],[2,3]]
 *  Output:  0
 *  Explanation:  You don't need to remove any of the intervals since they're
 * already non-overlapping.
 *   Constraints:
 *           1 <= intervals.length <= 10 5
 *           intervals[i].length == 2
 *           -5 * 10 4  <= start i  < end i  <= 5 * 10 4
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
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
    }
};
// @lc code=end
