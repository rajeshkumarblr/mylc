#include <set>
#include <cmath>
#include <map>
#include <iostream>
#include <utility>
/*
 * @lc app=leetcode id=973 lang=cpp
 *
 * [973] K Closest Points to Origin
 *
 * Difficulty: Medium
 * Category: heap
 * URL: https://leetcode.com/problems/k-closest-points-to-origin/
 *
 * Description:
 * Given an array of  points  where  points[i] = [x i , y i ]  represents a
 * point on the  X-Y  plane and an integer  k , return the  k  closest points
 * to the origin  (0, 0) .
 *  The distance between two points on the  X-Y  plane is the Euclidean
 * distance (i.e.,  &radic;(x 1  - x 2 ) 2  + (y 1  - y 2 ) 2  ).
 *  You may return the answer in  any order . The answer is  guaranteed  to be
 * unique  (except for the order that it is in).
 *   Example 1:
 *  Input:  points = [[1,3],[-2,2]], k = 1
 *  Output:  [[-2,2]]
 *  Explanation:
 * The distance between (1, 3) and the origin is sqrt(10).
 * The distance between (-2, 2) and the origin is sqrt(8).
 * Since sqrt(8) < sqrt(10), (-2, 2) is closer to the origin.
 * We only want the closest k = 1 points from the origin, so the answer is
 * just [[-2,2]].
 *   Example 2:
 *  Input:  points = [[3,3],[5,-1],[-2,4]], k = 2
 *  Output:  [[3,3],[-2,4]]
 *  Explanation:  The answer [[-2,4],[3,3]] would also be accepted.
 *   Constraints:
 *           1 <= k <= points.length <= 10 4
 *           -10 4  <= x i , y i  <= 10 4
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
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        return {};
    }
};
// @lc code=end


int main() {
    Solution sol;
    // Case 1
    {
        vector<vector<int>> points = {{1, 3}, {-2, 2}};
        int k = 1;
        auto got = sol.kClosest(points, k);
        if (got != vector<vector<int>>{{-2, 2}}) {
            cerr << "FAIL case 1" << endl;
            return 1;
        }
    }
    // Case 2
    {
        vector<vector<int>> points = {{3, 3}, {5, -1}, {-2, 4}};
        int k = 2;
        auto got = sol.kClosest(points, k);
        if (got != vector<vector<int>>{{-2, 4}, {3, 3}}) {
            cerr << "FAIL case 2" << endl;
            return 1;
        }
    }
    cout << "PASS" << endl;
    return 0;
}
